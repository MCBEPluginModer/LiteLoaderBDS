/**
 * @file  BlockPlacementFilterDescription.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC structure BlockPlacementFilterDescription.
 *
 */
struct BlockPlacementFilterDescription {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_BLOCKPLACEMENTFILTERDESCRIPTION
public:
    struct BlockPlacementFilterDescription& operator=(struct BlockPlacementFilterDescription const &) = delete;
    BlockPlacementFilterDescription(struct BlockPlacementFilterDescription const &) = delete;
    BlockPlacementFilterDescription() = delete;
#endif

public:
    /**
     * @vftbl  0
     * @hash   -123799110
     */
    virtual ~BlockPlacementFilterDescription();
    /**
     * @vftbl  1
     * @symbol ?getName@BlockPlacementFilterDescription@@UEBAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
     * @hash   -1412187331
     */
    virtual std::string const & getName() const;
    /**
     * @vftbl  2
     * @symbol ?initializeComponent@BlockPlacementFilterDescription@@UEBAXAEAVEntityContext@@@Z
     * @hash   287407751
     */
    virtual void initializeComponent(class EntityContext &) const;
    /**
     * @vftbl  3
     * @hash   -1406631549
     */
    virtual void __unk_vfn_3();
    /**
     * @vftbl  4
     * @symbol ?isNetworkComponent@BlockPlacementFilterDescription@@UEBA_NXZ
     * @hash   -931772699
     */
    virtual bool isNetworkComponent() const;
    /**
     * @vftbl  5
     * @symbol ?buildNetworkTag@BlockPlacementFilterDescription@@UEBA?AV?$unique_ptr@VCompoundTag@@U?$default_delete@VCompoundTag@@@std@@@std@@XZ
     * @hash   1746095399
     */
    virtual std::unique_ptr<class CompoundTag> buildNetworkTag() const;
    /**
     * @vftbl  6
     * @symbol ?initializeFromNetwork@BlockPlacementFilterDescription@@UEAAXAEBVCompoundTag@@@Z
     * @hash   1809414859
     */
    virtual void initializeFromNetwork(class CompoundTag const &);
    /**
     * @symbol ?NameID@BlockPlacementFilterDescription@@2V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@B
     * @hash   1933293989
     */
    MCAPI static std::string const NameID;
    /**
     * @symbol ?bindType@BlockPlacementFilterDescription@@SAXXZ
     * @hash   -1286219361
     */
    MCAPI static void bindType();

};