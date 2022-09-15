/**
 * @file  ActionEvent.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

/**
 * @brief MC class ActionEvent.
 *
 */
class ActionEvent {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ACTIONEVENT
public:
    class ActionEvent& operator=(class ActionEvent const &) = delete;
    ActionEvent(class ActionEvent const &) = delete;
    ActionEvent() = delete;
#endif

public:
    /**
     * @symbol ??0ActionEvent@@QEAA@HW4ActionState@0@_NW4FocusImpact@@@Z
     * @hash   -27240850
     */
    MCAPI ActionEvent(int, enum ActionEvent::ActionState, bool, enum FocusImpact);

};