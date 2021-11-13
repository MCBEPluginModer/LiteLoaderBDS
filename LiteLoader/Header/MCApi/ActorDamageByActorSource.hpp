// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#include <Global.h>
#include "ActorDamageSource.hpp"
class ActorDamageByActorSource : public ActorDamageSource {
public:
    virtual ~ActorDamageByActorSource();
    virtual void unk_vfn_1();
    virtual void unk_vfn_2();
    virtual void unk_vfn_3();
    virtual struct std::pair<std::string, std::vector<std::string>> getDeathMessage(std::string, class Actor*);
    virtual void unk_vfn_6();
    virtual void unk_vfn_7();
    virtual void unk_vfn_8();
    virtual void unk_vfn_9();
    virtual void unk_vfn_10();
    virtual void unk_vfn_11();
    virtual void unk_vfn_12();
    virtual struct ActorUniqueID getDamagingEntityUniqueID();
    virtual int /*enum ActorType*/ getDamagingEntityType();
    virtual void unk_vfn_15();
    virtual std::unique_ptr<class ActorDamageSource> clone();
};