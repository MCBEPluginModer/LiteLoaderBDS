// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

struct ItemChargeEvent {

#define AFTER_EXTRA

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ITEMCHARGEEVENT
public:
    struct ItemChargeEvent& operator=(struct ItemChargeEvent const &) = delete;
    ItemChargeEvent() = delete;
#endif

public:
    MCAPI ItemChargeEvent(struct ItemChargeEvent &&);
    MCAPI ItemChargeEvent(struct ItemChargeEvent const &);
    MCAPI ~ItemChargeEvent();

protected:

private:

};