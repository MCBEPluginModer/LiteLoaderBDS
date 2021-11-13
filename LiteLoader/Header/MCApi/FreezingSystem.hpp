// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#include <Global.h>
#include "ITickingSystem.hpp"
class FreezingSystem : public ITickingSystem {
public:
    virtual ~FreezingSystem();
    virtual void unk_vfn_1();
    virtual void tick(class EntityRegistry&);

public:
    MCAPI static class mce::UUID const FREEZE_EFFECT_UUID;
    MCAPI static int const VULNERABLE_MOB_FREEZE_DAMAGE;
};