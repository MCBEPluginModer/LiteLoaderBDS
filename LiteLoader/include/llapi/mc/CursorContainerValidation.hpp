/**
 * @file  CursorContainerValidation.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "ContainerValidationBase.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC class CursorContainerValidation.
 *
 */
class CursorContainerValidation : public ContainerValidationBase {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_CURSORCONTAINERVALIDATION
public:
    class CursorContainerValidation& operator=(class CursorContainerValidation const &) = delete;
    CursorContainerValidation(class CursorContainerValidation const &) = delete;
    CursorContainerValidation() = delete;
#endif

public:
    /**
     * @vftbl  0
     * @hash   -1119958926
     */
    virtual ~CursorContainerValidation();
    /**
     * @vftbl  1
     * @symbol ?isValidSlotForContainer@ContainerValidationBase@@UEBA_NAEBVContainerScreenContext@@AEBVContainer@@H@Z
     * @hash   -1668172600
     */
    virtual bool isValidSlotForContainer(class ContainerScreenContext const &, class Container const &, int) const;
    /**
     * @vftbl  2
     * @hash   -1265373198
     */
    virtual void __unk_vfn_2();
    /**
     * @vftbl  3
     * @symbol ?getAvailableSetCount@ContainerValidationBase@@UEBAHHAEBVItemStackBase@@@Z
     * @hash   -2131704437
     */
    virtual int getAvailableSetCount(int, class ItemStackBase const &) const;
    /**
     * @vftbl  4
     * @hash   -1263526156
     */
    virtual void __unk_vfn_4();
    /**
     * @vftbl  5
     * @hash   -1262602635
     */
    virtual void __unk_vfn_5();
    /**
     * @vftbl  6
     * @hash   -1261679114
     */
    virtual void __unk_vfn_6();
    /**
     * @vftbl  7
     * @symbol ?canDestroy@ContainerValidationBase@@UEBA_NAEBVContainerScreenContext@@@Z
     * @hash   1636180575
     */
    virtual bool canDestroy(class ContainerScreenContext const &) const;
    /**
     * @vftbl  8
     * @symbol ?getContainerOffset@CursorContainerValidation@@UEBAHAEBVContainerScreenContext@@@Z
     * @hash   1539919096
     */
    virtual int getContainerOffset(class ContainerScreenContext const &) const;
    /**
     * @vftbl  9
     * @symbol ?getContainerSize@ContainerValidationBase@@UEBAHAEBVContainerScreenContext@@AEBVContainer@@@Z
     * @hash   1011790636
     */
    virtual int getContainerSize(class ContainerScreenContext const &, class Container const &) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_CURSORCONTAINERVALIDATION
    /**
     * @symbol ?canItemMoveToContainer@CursorContainerValidation@@UEBA_NAEBVItemStackBase@@@Z
     * @hash   -1676224341
     */
    MCVAPI bool canItemMoveToContainer(class ItemStackBase const &) const;
#endif

};