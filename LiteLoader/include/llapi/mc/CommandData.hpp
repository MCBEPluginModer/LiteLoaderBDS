#pragma once
#include "CommandParameter.hpp"
#include "CommandEnum.hpp"

class CommandData {
public:
    CommandData(std::string name, std::string description, int flags, int permission,
                std::shared_ptr<CommandEnum> aliases, std::vector<std::vector<CommandParameter>> overloads)
    : name(std::move(name))
    , description(std::move(description))
    , flags(flags)
    , permission(permission)
    , aliases(aliases)
    , overloads(std::move(overloads)) {
        for (const auto& overload : this->overloads) {
            for (const auto& parameter : overload) {
                // Perform some operation on each CommandParameter object in the overloads
            }
        }
    }
    std::string getName() const {
        return name;
    }

    std::string getDescription() const {
        return description;
    }

    int getFlags() const {
        return flags;
    }

    int getPermission() const {
        return permission;
    }

    std::shared_ptr<CommandEnum> getAliases() const {
        return aliases;
    }

    std::vector<std::vector<CommandParameter>> getOverloads() const {
        return overloads;
    }
    std::vector<std::vector<CommandParameter>> getOverloads() {
        return overloads;
    }
private:
    std::string name;
    std::string description;
    int flags;
    int permission;
    std::shared_ptr<CommandEnum> aliases;
    std::vector<std::vector<CommandParameter>> overloads;
};