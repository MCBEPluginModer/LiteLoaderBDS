// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#include <Global.h>
#include "ITickingSystem.hpp"
class DamageOverTimeSystem : public ITickingSystem {
public:
    virtual ~DamageOverTimeSystem();
    virtual void unk_vfn_1();
    virtual void tick(class EntityRegistry&);
};