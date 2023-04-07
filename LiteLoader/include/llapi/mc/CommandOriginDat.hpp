#pragma once
#include <string>
#include "llapi/Global.h"

class CommandOriginData {
public:
    static const int ORIGIN_PLAYER = 0;
    static const int ORIGIN_BLOCK = 1;
    static const int ORIGIN_MINECART_BLOCK = 2;
    static const int ORIGIN_DEV_CONSOLE = 3;
    static const int ORIGIN_TEST = 4;
    static const int ORIGIN_AUTOMATION_PLAYER = 5;
    static const int ORIGIN_CLIENT_AUTOMATION = 6;
    static const int ORIGIN_DEDICATED_SERVER = 7;
    static const int ORIGIN_ENTITY = 8;
    static const int ORIGIN_VIRTUAL = 9;
    static const int ORIGIN_GAME_ARGUMENT = 10;
    static const int ORIGIN_ENTITY_SERVER = 11;

    int type;
    mce::UUID uuid;
    std::string requestId;
    int playerActorUniqueId;
};