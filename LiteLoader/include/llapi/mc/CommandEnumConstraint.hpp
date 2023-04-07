#pragma once
#include "CommandEnum.h"

class CommandEnumConstraint {
    static constexpr int REQUIRES_CHEATS_ENABLED = 1 << 0;
    static constexpr int REQUIRES_ELEVATED_PERMISSIONS = 1 << 1;
    static constexpr int REQUIRES_HOST_PERMISSIONS = 1 << 2;
    static constexpr int REQUIRES_ALLOW_ALIASES = 1 << 3;
    CommandEnum _enum;
    int valueOffset;
    vector<int> constraints;
public:
    CommandEnumConstraint(CommandEnum enumVal, int valueOffset, std::vector<int> constraints)
    : _enum(enumVal), valueOffset(valueOffset), constraints(constraints) {
        if (valueOffset >= static_cast<int>(enumVal.getValues().size())) {
            throw std::invalid_argument("Invalid enum value offset " + std::to_string(valueOffset));
        }
    }

    CommandEnum getEnum() const {
        return enumVal;
    }

    int getValueOffset() const {
        return valueOffset;
    }

    std::string getAffectedValue() const {
        return enumVal.getValues().at(valueOffset);
    }

    std::vector<int> getConstraints() const {
        return constraints;
    }
};