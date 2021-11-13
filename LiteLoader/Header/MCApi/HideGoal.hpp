// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#include <Global.h>
#include "MoveToPOIGoal.hpp"
class HideGoal : public MoveToPOIGoal {
public:
    virtual ~HideGoal();
    virtual bool canUse();
    virtual bool canContinueToUse();
    virtual void unk_vfn_3();
    virtual void start();
    virtual void stop();
    virtual void appendDebugInfo(std::string&);
    virtual void unk_vfn_8();
    virtual void unk_vfn_9();
    virtual void unk_vfn_16();
    virtual class std::weak_ptr<class POIInstance> _getOwnedPOI(int /*enum POIType*/);
};