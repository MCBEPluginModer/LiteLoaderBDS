#pragma once

class CommandPermissions {
private:
    CommandPermissions() {}

public:
    static const int NORMAL = 0;
    static const int OPERATOR = 1;
    static const int AUTOMATION = 2; // command blocks
    static const int HOST = 3;       // hosting player on LAN multiplayer
    static const int OWNER = 4;      // server terminal on BDS
    static const int INTERNAL = 5;
};
