/**
 * @file  AnvilBlock.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "HeavyBlock.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC class AnvilBlock.
 *
 */
class AnvilBlock : public HeavyBlock {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ANVILBLOCK
public:
    class AnvilBlock& operator=(class AnvilBlock const &) = delete;
    AnvilBlock(class AnvilBlock const &) = delete;
    AnvilBlock() = delete;
#endif

public:
    /**
     * @vftbl  0
     * @hash   32036971
     */
    virtual ~AnvilBlock();
    /**
     * @vftbl  10
     * @symbol ?getAABB@AnvilBlock@@UEBAAEBVAABB@@AEBVIConstBlockSource@@AEBVBlockPos@@AEBVBlock@@AEAV2@_N@Z
     * @hash   906759185
     */
    virtual class AABB const & getAABB(class IConstBlockSource const &, class BlockPos const &, class Block const &, class AABB &, bool) const;
    /**
     * @vftbl  14
     * @symbol ?getLiquidClipVolume@AnvilBlock@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@AEAVAABB@@@Z
     * @hash   -1605995367
     */
    virtual bool getLiquidClipVolume(class BlockSource &, class BlockPos const &, class AABB &) const;
    /**
     * @vftbl  19
     * @hash   -327659668
     */
    virtual void __unk_vfn_19();
    /**
     * @vftbl  29
     * @hash   -299030517
     */
    virtual void __unk_vfn_29();
    /**
     * @vftbl  30
     * @hash   -278713055
     */
    virtual void __unk_vfn_30();
    /**
     * @vftbl  32
     * @hash   -283600701
     */
    virtual void __unk_vfn_32();
    /**
     * @vftbl  33
     * @hash   -275942492
     */
    virtual void __unk_vfn_33();
    /**
     * @vftbl  34
     * @hash   -275018971
     */
    virtual void __unk_vfn_34();
    /**
     * @vftbl  36
     * @hash   -273171929
     */
    virtual void __unk_vfn_36();
    /**
     * @vftbl  37
     * @hash   -272248408
     */
    virtual void __unk_vfn_37();
    /**
     * @vftbl  38
     * @hash   -271324887
     */
    virtual void __unk_vfn_38();
    /**
     * @vftbl  39
     * @hash   -270401366
     */
    virtual void __unk_vfn_39();
    /**
     * @vftbl  40
     * @hash   -250083904
     */
    virtual void __unk_vfn_40();
    /**
     * @vftbl  41
     * @hash   -249160383
     */
    virtual void __unk_vfn_41();
    /**
     * @vftbl  42
     * @hash   -248236862
     */
    virtual void __unk_vfn_42();
    /**
     * @vftbl  44
     * @hash   -246389820
     */
    virtual void __unk_vfn_44();
    /**
     * @vftbl  45
     * @hash   -245466299
     */
    virtual void __unk_vfn_45();
    /**
     * @vftbl  46
     * @hash   -244542778
     */
    virtual void __unk_vfn_46();
    /**
     * @vftbl  47
     * @hash   -243619257
     */
    virtual void __unk_vfn_47();
    /**
     * @vftbl  48
     * @hash   -242695736
     */
    virtual void __unk_vfn_48();
    /**
     * @vftbl  49
     * @hash   -241772215
     */
    virtual void __unk_vfn_49();
    /**
     * @vftbl  59
     * @hash   -213143064
     */
    virtual void __unk_vfn_59();
    /**
     * @vftbl  60
     * @hash   -192825602
     */
    virtual void __unk_vfn_60();
    /**
     * @vftbl  61
     * @symbol ?canContainLiquid@AnvilBlock@@UEBA_NXZ
     * @hash   -585630249
     */
    virtual bool canContainLiquid() const;
    /**
     * @vftbl  73
     * @hash   -161425888
     */
    virtual void __unk_vfn_73();
    /**
     * @vftbl  80
     * @hash   -135567300
     */
    virtual void __unk_vfn_80();
    /**
     * @vftbl  94
     * @symbol ?breaksFallingBlocks@AnvilBlock@@UEBA_NAEBVBlock@@VBaseGameVersion@@@Z
     * @hash   -2069459110
     */
    virtual bool breaksFallingBlocks(class Block const &, class BaseGameVersion) const;
    /**
     * @vftbl  101
     * @symbol ?getResourceItem@AnvilBlock@@UEBA?AVItemInstance@@AEAVRandomize@@AEBVBlock@@H@Z
     * @hash   -77479313
     */
    virtual class ItemInstance getResourceItem(class Randomize &, class Block const &, int) const;
    /**
     * @vftbl  102
     * @symbol ?asItemInstance@AnvilBlock@@UEBA?AVItemInstance@@AEAVBlockSource@@AEBVBlockPos@@AEBVBlock@@@Z
     * @hash   746445076
     */
    virtual class ItemInstance asItemInstance(class BlockSource &, class BlockPos const &, class Block const &) const;
    /**
     * @vftbl  105
     * @hash   1332020102
     */
    virtual void __unk_vfn_105();
    /**
     * @vftbl  106
     * @symbol ?getPlacementBlock@AnvilBlock@@UEBAAEBVBlock@@AEAVActor@@AEBVBlockPos@@EAEBVVec3@@H@Z
     * @hash   1365317152
     */
    virtual class Block const & getPlacementBlock(class Actor &, class BlockPos const &, unsigned char, class Vec3 const &, int) const;
    /**
     * @vftbl  124
     * @hash   1388354883
     */
    virtual void __unk_vfn_124();
    /**
     * @vftbl  126
     * @hash   1390201925
     */
    virtual void __unk_vfn_126();
    /**
     * @vftbl  127
     * @hash   1391125446
     */
    virtual void __unk_vfn_127();
    /**
     * @vftbl  132
     * @hash   1415136992
     */
    virtual void __unk_vfn_132();
    /**
     * @vftbl  134
     * @symbol ?buildDescriptionId@AnvilBlock@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVBlock@@@Z
     * @hash   -1624025256
     */
    virtual std::string buildDescriptionId(class Block const &) const;
    /**
     * @vftbl  135
     * @symbol ?isAuxValueRelevantForPicking@AnvilBlock@@UEBA_NXZ
     * @hash   1701077859
     */
    virtual bool isAuxValueRelevantForPicking() const;
    /**
     * @vftbl  147
     * @symbol ?getVariant@AnvilBlock@@UEBAHAEBVBlock@@@Z
     * @hash   55301105
     */
    virtual int getVariant(class Block const &) const;
    /**
     * @vftbl  148
     * @hash   1442572581
     */
    virtual void __unk_vfn_148();
    /**
     * @vftbl  152
     * @symbol ?animateTick@AnvilBlock@@UEBAXAEAVBlockSource@@AEBVBlockPos@@AEAVRandom@@@Z
     * @hash   1555544294
     */
    virtual void animateTick(class BlockSource &, class BlockPos const &, class Random &) const;
    /**
     * @vftbl  157
     * @hash   1477012899
     */
    virtual void __unk_vfn_157();
    /**
     * @vftbl  158
     * @symbol ?getSilkTouchItemInstance@AnvilBlock@@UEBA?AVItemInstance@@AEBVBlock@@@Z
     * @hash   -1058822440
     */
    virtual class ItemInstance getSilkTouchItemInstance(class Block const &) const;
    /**
     * @vftbl  168
     * @hash   1457546883
     */
    virtual void __unk_vfn_168();
    /**
     * @vftbl  169
     * @hash   1458470404
     */
    virtual void __unk_vfn_169();
    /**
     * @vftbl  170
     * @hash   1478787866
     */
    virtual void __unk_vfn_170();
    /**
     * @vftbl  177
     * @hash   1527536513
     */
    virtual void __unk_vfn_177();
    /**
     * @vftbl  179
     * @symbol ?use@AnvilBlock@@UEBA_NAEAVPlayer@@AEBVBlockPos@@E@Z
     * @hash   645931174
     */
    virtual bool use(class Player &, class BlockPos const &, unsigned char) const;
    /**
     * @vftbl  188
     * @hash   1563823873
     */
    virtual void __unk_vfn_188();
    /**
     * @vftbl  192
     * @symbol ?getDustColor@AnvilBlock@@UEBA?AVColor@mce@@AEBVBlock@@@Z
     * @hash   -1481668435
     */
    virtual class mce::Color getDustColor(class Block const &) const;
    /**
     * @vftbl  193
     * @symbol ?getDustParticleName@AnvilBlock@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVBlock@@@Z
     * @hash   1214517288
     */
    virtual std::string getDustParticleName(class Block const &) const;
    /**
     * @vftbl  194
     * @hash   1582024252
     */
    virtual void __unk_vfn_194();
    /**
     * @vftbl  195
     * @symbol ?onLand@AnvilBlock@@UEBAXAEAVBlockSource@@AEBVBlockPos@@@Z
     * @hash   559129093
     */
    virtual void onLand(class BlockSource &, class BlockPos const &) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_ANVILBLOCK
    /**
     * @symbol ?canBeSilkTouched@AnvilBlock@@MEBA_NXZ
     * @hash   -2095729914
     */
    MCVAPI bool canBeSilkTouched() const;
    /**
     * @symbol ?falling@AnvilBlock@@UEBA_NXZ
     * @hash   -1931159938
     */
    MCVAPI bool falling() const;
    /**
     * @symbol ?isCraftingBlock@AnvilBlock@@UEBA_NXZ
     * @hash   1195105944
     */
    MCVAPI bool isCraftingBlock() const;
    /**
     * @symbol ?isInteractiveBlock@AnvilBlock@@UEBA_NXZ
     * @hash   2134843276
     */
    MCVAPI bool isInteractiveBlock() const;
#endif
    /**
     * @symbol ??0AnvilBlock@@QEAA@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@Z
     * @hash   856162559
     */
    MCAPI AnvilBlock(std::string const &, int);

};