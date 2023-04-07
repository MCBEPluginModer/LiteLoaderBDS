#pragma once
#include "CommandEnum.hpp"
#include <optio>
#include "AvailableCommandsPacket.hpp"

enum AvailableCommandsPacketFlags {
    ARG_FLAG_VALID = 0x100000,
    ARG_FLAG_ENUM = 0x200000,
    ARG_FLAG_POSTFIX = 0x1000000
};

class CommandParameter {
public:
    static const int FLAG_FORCE_COLLAPSE_ENUM = 0x1;
    static const int FLAG_HAS_ENUM_CONSTRAINT = 0x2;

    std::string paramName;
    int paramType;
    bool isOptional;
    int flags = 0;
    CommandEnum* enumPtr = nullptr;
    std::optional<std::string> postfix;

private:
    static CommandParameter baseline(std::string name, int type, int flags, bool optional) {
        CommandParameter result;
        result.paramName = name;
        result.paramType = ARG_FLAG_VALID | type;
        result.flags = flags;
        result.isOptional = optional;
        return result;
    }

public:
    static CommandParameter standard(std::string name, int type, int flags = 0, bool optional = false) {
        return baseline(name, type, ARG_FLAG_VALID | flags, optional);
    }

    static CommandParameter postfixed(std::string name, std::string postfix, int flags = 0, bool optional = false) {
        auto result = baseline(name, ARG_FLAG_POSTFIX, flags, optional);
        result.postfix = postfix;
        return result;
    }

    static CommandParameter withEnum(std::string name, CommandEnum* enumPtr, int flags, bool optional = false) {
        auto result = baseline(name, ARG_FLAG_VALID | ARG_FLAG_ENUM, flags, optional);
        result.enumPtr = enumPtr;
        return result;
    }
};