/**
 * @file  AvailableCommandsPacket.hpp
 *
 */
#pragma once
#define AUTO_GENERATED
#include "llapi/Global.h"
#include "Packet.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here
#include "CommandData.hpp"
#include "CommandOutputMessag.hpp"
#include "CommandOriginDat.hpp"
#include "CommandPermissions.hpp"
#include "CommandParameter.hpp"
#include "CommandEnum.hpp"
#include "CommandEnumConstraint.hpp"
#include "BinaryStream.hpp"
enum class CommandPermissionLevel : char;

#undef BEFORE_EXTRA

/**
 * @brief MC class AvailableCommandsPacket.
 *
 */
class AvailableCommandsPacket : public Packet {

#define AFTER_EXTRA
// Add Member There
public:
const int ARG_TYPE_WILDCARD_TARGET = 0x0a;

const int ARG_TYPE_FILEPATH = 0x11;

const int ARG_TYPE_FULL_INTEGER_RANGE = 0x17;

const int ARG_TYPE_EQUIPMENT_SLOT = 0x26;
const int ARG_TYPE_STRING = 0x27;

const int ARG_TYPE_INT_POSITION = 0x2f;
const int ARG_TYPE_POSITION = 0x30;

const int ARG_TYPE_MESSAGE = 0x33;

const int ARG_TYPE_RAWTEXT = 0x35;

const int ARG_TYPE_JSON = 0x39;

const int ARG_TYPE_BLOCK_STATES = 0x43;

const int ARG_TYPE_COMMAND = 0x46;

/**

Enums are a little different: they are composed as follows:
ARG_FLAG_ENUM | ARG_FLAG_VALID | (enum index)
*/
const int ARG_FLAG_ENUM = 0x200000;
/** This is used for /xp <level: int>L. It can only be applied to integer parameters. */
const int ARG_FLAG_POSTFIX = 0x1000000;

const int ARG_FLAG_SOFT_ENUM = 0x4000000;

const std::unordered_map<std::string, bool> HARDCODED_ENUM_NAMES =
    std::unordered_map<std::string, bool>{{"CommandName", true}};

/**

@var CommandData[]
List of command data, including name, description, alias indexes and parameters.
*/
std::vector<CommandData> commandData;
/**

@var CommandEnum[]
List of enums which aren't directly referenced by any vanilla command.
This is used for the CommandName enum, which is a magic enum used by the command argument type.
*/
std::vector<CommandEnum> hardcodedEnums;
/**

@var CommandEnum[]
List of dynamic command enums, also referred to as "soft" enums. These can by dynamically updated mid-game
without resending this packet.
*/
std::vector<CommandEnum> softEnums;
/**

@var CommandEnumConstraint[]
List of constraints for enum members. Used to constrain gamerules that can bechanged in nocheats mode and more.
*/
std::vector<CommandEnumConstraint> enumConstraints;

public:
inline void initSoftEnumsInCommandData() {
    for (const auto& datum : commandData) {
        for (const auto& overload : datum.getOverloads()) {
            for (const auto& parameter : overload) {
                if ((parameter.paramType & ARG_FLAG_SOFT_ENUM) != 0) {
                    int index = parameter.paramType & 0xffff;
                    parameter.enum = softEnums[index];
                    if (parameter.enum == nullptr) {
                        throw runtime_error("deserializing " + datum.getName() + " parameter " +
                                                    parameter.paramName + ": expected soft enum at " +
                                                    std::to_string(index) + ", but got none");
                    }
                }
            }
        }
    }
}

CommandEnum getEnum(std::vector<std::string> enumValueList, BinaryStream& in) {
    std::string enumName = in.getString();
    std::vector<std::string> enumValues;
    int listSize = enumValueList.size();

    for (int i = 0, count = in.getUnsignedVarInt(); i < count; ++i) {
        int index = getEnumValueIndex(listSize, in);
        if (index >= enumValueList.size()) {
            throw runtime_error("Invalid enum value index " + std::to_string(index));
        }
        // Get the enum value from the initial pile of mess
        enumValues.push_back(enumValueList[index]);
    }
    return CommandEnum(enumName, enumValues,0);
}

CommandEnum getSoftEnum(BinaryStream& in) {
    std::string enumName = in.getString();
    std::vector<std::string> enumValues;
    int count = in.getUnsignedVarInt();
    for (int i = 0; i < count; ++i) {
        // Get the enum value from the initial pile of mess
        enumValues.push_back(in.getString());
    }

    return CommandEnum(enumName, enumValues, true);
}

void putEnum(CommandEnum& enumVal, std::unordered_map<std::string, int>& enumValueMap, BinaryStream& out) {
    out.writeString(enumVal.getName());
    const auto& values = enumVal.getValues();
    out.writeUnsignedVarInt(values.size());
    const auto listSize = enumValueMap.size();
    for (const auto& value : values) {
        if (enumValueMap.find(value) == enumValueMap.end()) {
            throw std::logic_error("Enum value '" + value + "' doesn't have a value index");
        }
        putEnumValueIndex(enumValueMap.at(value), listSize, out);
    }
}

void putSoftEnum(CommandEnum& enumObj, BinaryStream& out) {
    out.writeString(enumObj.getName());
    const auto& values = enumObj.getValues();
    out.writeUnsignedVarInt(values.size());
    for (const auto& value : values) {
        out.writeString(value);
    }
}

int getEnumValueIndex(int valueCount, BinaryStream& in) {
    if (valueCount < 256) {
        return in.getByte();
    } else if (valueCount < 65536) {
        return in.getSignedShort();
    } else {
        return in.getSignedInt();
    }
}

void putEnumValueIndex(int index, int valueCount, BinaryStream& out) {
    if (valueCount < 256) {
        out.writeByte(index);
    } else if (valueCount < 65536) {
        out.writeSignedShort(index);
    } else {
        out.writeSignedInt(index);
    }
}

CommandEnumConstraint getEnumConstraint(std::vector<CommandEnum>& enums,
                                        std::vector<std::string>& enumValues, BinaryStream& in) {
    int valueIndex = in.getSignedInt();
    if (valueIndex >= static_cast<int>(enumValues.size())) {
        throw runtime_error("Enum constraint refers to unknown enum value index " + std::to_string(valueIndex));
    }
    const std::string& value = enumValues[valueIndex];

    int enumIndex = in.getSignedInt();
    if (enumIndex >= static_cast<int>(enums.size())) {
        throw runtime_error("Enum constraint refers to unknown enum index " + std::to_string(enumIndex));
    }
    CommandEnum& enumObj = enums[enumIndex];

    int valueOffset = -1;
    const auto& values = enumObj.getValues();
    for (size_t i = 0; i < values.size(); ++i) {
        if (values[i] == value) {
            valueOffset = static_cast<int>(i);
            break;
        }
    }
    if (valueOffset == -1) {
        throw runtime_error("Value \"" + value + "\" does not belong to enum \"" + enumObj.getName() + "\"");
    }

    std::vector<int> constraintIds;
    size_t count = in.getUnsignedVarInt();
    for (size_t i = 0; i < count; ++i) {
        constraintIds.push_back(in.getByte());
    }

    return CommandEnumConstraint(enumObj, valueOffset, constraintIds);
}

void putEnumConstraint(CommandEnumConstraint constraint, std::unordered_map<std::string, int> enumIndexes,
                       std::unordered_map<std::string, std::unordered_map<std::string, int>> enumValueIndexes,
                       BinaryStream& out) {
    out.writeSignedInt(enumValueIndexes[constraint.getEnum().getName()]
                                [constraint.getEnum().getValues()[constraint.getAffectedValue()]]);
    out.writeSignedInt(enumIndexes[constraint.getEnum().getName()]);
    out.writeUnsignedVarInt(constraint.getConstraints().size());
    for (auto v : constraint.getConstraints()) {
        out.writeByte(v);
    }
}



#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_AVAILABLECOMMANDSPACKET
public:
    class AvailableCommandsPacket& operator=(class AvailableCommandsPacket const &) = delete;
    AvailableCommandsPacket(class AvailableCommandsPacket const &) = delete;
#endif

public:
    /**
     * @vftbl 0
     * @symbol __unk_vfn_0
     */
    virtual void __unk_vfn_0();
    /**
     * @vftbl 1
     * @symbol ?getId\@AvailableCommandsPacket\@\@UEBA?AW4MinecraftPacketIds\@\@XZ
     */
    virtual enum class MinecraftPacketIds getId() const;
    /**
     * @vftbl 2
     * @symbol ?getName\@AvailableCommandsPacket\@\@UEBA?AV?$basic_string\@DU?$char_traits\@D\@std\@\@V?$allocator\@D\@2\@\@std\@\@XZ
     */
    virtual std::string getName() const;
    /**
     * @vftbl 3
     * @symbol ?write\@AvailableCommandsPacket\@\@UEBAXAEAVBinaryStream\@\@\@Z
     */
    virtual void write(class BinaryStream &) const;
    /**
     * @vftbl 7
     * @symbol ?_read\@AvailableCommandsPacket\@\@EEAA?AW4StreamReadResult\@\@AEAVReadOnlyBinaryStream\@\@\@Z
     */
    virtual enum class StreamReadResult _read(class ReadOnlyBinaryStream &);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_AVAILABLECOMMANDSPACKET
    /**
     * @symbol __unk_destructor_-1
     */
    MCVAPI ~AvailableCommandsPacket();
#endif
    /**
     * @symbol ??0AvailableCommandsPacket\@\@QEAA\@AEBV?$vector\@V?$basic_string\@DU?$char_traits\@D\@std\@\@V?$allocator\@D\@2\@\@std\@\@V?$allocator\@V?$basic_string\@DU?$char_traits\@D\@std\@\@V?$allocator\@D\@2\@\@std\@\@\@2\@\@std\@\@0$$QEAV?$vector\@UEnumData\@AvailableCommandsPacket\@\@V?$allocator\@UEnumData\@AvailableCommandsPacket\@\@\@std\@\@\@2\@$$QEAV?$vector\@UConstrainedValueData\@AvailableCommandsPacket\@\@V?$allocator\@UConstrainedValueData\@AvailableCommandsPacket\@\@\@std\@\@\@2\@$$QEAV?$vector\@UCommandData\@AvailableCommandsPacket\@\@V?$allocator\@UCommandData\@AvailableCommandsPacket\@\@\@std\@\@\@2\@$$QEAV?$vector\@USoftEnumData\@AvailableCommandsPacket\@\@V?$allocator\@USoftEnumData\@AvailableCommandsPacket\@\@\@std\@\@\@2\@\@Z
     */
    MCAPI AvailableCommandsPacket(std::vector<std::string> const &, std::vector<std::string> const &, std::vector<struct AvailableCommandsPacket::EnumData> &&, std::vector<struct AvailableCommandsPacket::ConstrainedValueData> &&, std::vector<struct AvailableCommandsPacket::CommandData> &&, std::vector<struct AvailableCommandsPacket::SoftEnumData> &&);
    /**
     * @symbol ??0AvailableCommandsPacket\@\@QEAA\@XZ
     */
    MCAPI AvailableCommandsPacket();

};
