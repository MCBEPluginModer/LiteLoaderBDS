/**
 * @file  Slime.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Actor.hpp"
#include "Monster.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC class Slime.
 *
 */
class Slime : public Monster {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SLIME
public:
    class Slime& operator=(class Slime const &) = delete;
    Slime(class Slime const &) = delete;
    Slime() = delete;
#endif

public:
    /**
     * @vftbl  8
     * @symbol ?reloadHardcoded@Slime@@UEAAXW4InitializationMethod@Actor@@AEBVVariantParameterList@@@Z
     * @hash   802299061
     */
    virtual void reloadHardcoded(enum Actor::InitializationMethod, class VariantParameterList const &);
    /**
     * @vftbl  14
     * @hash   766107030
     */
    virtual ~Slime();
    /**
     * @vftbl  18
     * @symbol ?remove@Slime@@UEAAXXZ
     * @hash   -1805152477
     */
    virtual void remove();
    /**
     * @vftbl  41
     * @hash   -249160383
     */
    virtual void __unk_vfn_41();
    /**
     * @vftbl  49
     * @symbol ?normalTick@Slime@@UEAAXXZ
     * @hash   319141939
     */
    virtual void normalTick();
    /**
     * @vftbl  61
     * @hash   -191902081
     */
    virtual void __unk_vfn_61();
    /**
     * @vftbl  68
     * @hash   -185437434
     */
    virtual void __unk_vfn_68();
    /**
     * @vftbl  80
     * @symbol ?getShadowRadius@Slime@@UEBAMXZ
     * @hash   -871058370
     */
    virtual float getShadowRadius() const;
    /**
     * @vftbl  82
     * @hash   -133720258
     */
    virtual void __unk_vfn_82();
    /**
     * @vftbl  85
     * @hash   -137684383
     */
    virtual void __unk_vfn_85();
    /**
     * @vftbl  88
     * @hash   -128179132
     */
    virtual void __unk_vfn_88();
    /**
     * @vftbl  89
     * @symbol ?playerTouch@Slime@@UEAAXAEAVPlayer@@@Z
     * @hash   1404569206
     */
    virtual void playerTouch(class Player &);
    /**
     * @vftbl  96
     * @hash   -108131711
     */
    virtual void __unk_vfn_96();
    /**
     * @vftbl  99
     * @hash   -105361148
     */
    virtual void __unk_vfn_99();
    /**
     * @vftbl  106
     * @hash   1332943623
     */
    virtual void __unk_vfn_106();
    /**
     * @vftbl  108
     * @hash   1334790665
     */
    virtual void __unk_vfn_108();
    /**
     * @vftbl  109
     * @hash   1328979498
     */
    virtual void __unk_vfn_109();
    /**
     * @vftbl  111
     * @hash   1356955169
     */
    virtual void __unk_vfn_111();
    /**
     * @vftbl  182
     * @hash   1509264059
     */
    virtual void __unk_vfn_182();
    /**
     * @vftbl  191
     * @symbol ?onSynchedDataUpdate@Slime@@UEAAXH@Z
     * @hash   -1729560928
     */
    virtual void onSynchedDataUpdate(int);
    /**
     * @vftbl  196
     * @hash   1590605982
     */
    virtual void __unk_vfn_196();
    /**
     * @vftbl  222
     * @hash   -2034256014
     */
    virtual void __unk_vfn_222();
    /**
     * @vftbl  223
     * @hash   -2020032253
     */
    virtual void __unk_vfn_223();
    /**
     * @vftbl  248
     * @hash   -2007175034
     */
    virtual void __unk_vfn_248();
    /**
     * @vftbl  251
     * @hash   -786620466
     */
    virtual void __unk_vfn_251();
    /**
     * @vftbl  269
     * @hash   -1906709211
     */
    virtual void __unk_vfn_269();
    /**
     * @vftbl  273
     * @symbol ?readAdditionalSaveData@Slime@@MEAAXAEBVCompoundTag@@AEAVDataLoadHelper@@@Z
     * @hash   -2120250152
     */
    virtual void readAdditionalSaveData(class CompoundTag const &, class DataLoadHelper &);
    /**
     * @vftbl  274
     * @symbol ?addAdditionalSaveData@Slime@@MEBAXAEAVCompoundTag@@@Z
     * @hash   60381349
     */
    virtual void addAdditionalSaveData(class CompoundTag &) const;
    /**
     * @vftbl  277
     * @hash   -1873192414
     */
    virtual void __unk_vfn_277();
    /**
     * @vftbl  285
     * @hash   -1895428993
     */
    virtual void __unk_vfn_285();
    /**
     * @vftbl  300
     * @symbol ?aiStep@Slime@@UEAAXXZ
     * @hash   922752563
     */
    virtual void aiStep();
    /**
     * @vftbl  305
     * @symbol ?checkSpawnRules@Slime@@UEAA_N_N@Z
     * @hash   328990135
     */
    virtual bool checkSpawnRules(bool);
    /**
     * @vftbl  313
     * @hash   -1210176411
     */
    virtual void __unk_vfn_313();
    /**
     * @vftbl  317
     * @hash   -1157463639
     */
    virtual void __unk_vfn_317();
    /**
     * @vftbl  349
     * @symbol ?_getWalkTargetValue@Slime@@MEAAMAEBVBlockPos@@@Z
     * @hash   -997693686
     */
    virtual float _getWalkTargetValue(class BlockPos const &);
    /**
     * @vftbl  351
     * @hash   -1055222849
     */
    virtual void __unk_vfn_351();
    /**
     * @vftbl  365
     * @hash   -1022899614
     */
    virtual void __unk_vfn_365();
    /**
     * @vftbl  368
     * @symbol ?canDealDamage@Slime@@UEAA_NXZ
     * @hash   1175601740
     */
    virtual bool canDealDamage();
    /**
     * @vftbl  369
     * @symbol ?getSquishSound@Slime@@UEAA?AW4LevelSoundEvent@@XZ
     * @hash   -2094589182
     */
    virtual enum LevelSoundEvent getSquishSound();
    /**
     * @vftbl  370
     * @symbol ?setSlimeSize@Slime@@MEAAXH@Z
     * @hash   -1368829232
     */
    virtual void setSlimeSize(int);
    /**
     * @vftbl  371
     * @symbol ?doPlayJumpSound@Slime@@MEAA_NXZ
     * @hash   -1842185220
     */
    virtual bool doPlayJumpSound();
    /**
     * @vftbl  372
     * @symbol ?doPlayLandSound@Slime@@MEAA_NXZ
     * @hash   2090125151
     */
    virtual bool doPlayLandSound();
    /**
     * @vftbl  373
     * @symbol ?playJumpSound@Slime@@MEAAXXZ
     * @hash   1320624405
     */
    virtual void playJumpSound();
    /**
     * @vftbl  374
     * @symbol ?playLandSound@Slime@@MEAAXXZ
     * @hash   586987512
     */
    virtual void playLandSound();
    /**
     * @vftbl  375
     * @symbol ?decreaseSquish@Slime@@MEAAXXZ
     * @hash   -1490267683
     */
    virtual void decreaseSquish();
    /**
     * @vftbl  376
     * @symbol ?createChild@Slime@@MEAA?AV?$OwnerPtrT@UEntityRefTraits@@@@H@Z
     * @hash   659286191
     */
    virtual class OwnerPtrT<struct EntityRefTraits> createChild(int);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_SLIME
    /**
     * @symbol ?useNewAi@Slime@@UEBA_NXZ
     * @hash   1052395121
     */
    MCVAPI bool useNewAi() const;
#endif
    /**
     * @symbol ??0Slime@@QEAA@PEAVActorDefinitionGroup@@AEBUActorDefinitionIdentifier@@AEAVEntityContext@@@Z
     * @hash   1852082532
     */
    MCAPI Slime(class ActorDefinitionGroup *, struct ActorDefinitionIdentifier const &, class EntityContext &);
    /**
     * @symbol ?getOldSquishValue@Slime@@QEBAMXZ
     * @hash   -597004088
     */
    MCAPI float getOldSquishValue() const;
    /**
     * @symbol ?getSlimeSize@Slime@@QEBAHXZ
     * @hash   -772092692
     */
    MCAPI int getSlimeSize() const;
    /**
     * @symbol ?getSquishValue@Slime@@QEBAMXZ
     * @hash   -919412932
     */
    MCAPI float getSquishValue() const;
    /**
     * @symbol ?getSpawnRulesCallback@Slime@@SA?AV?$function@$$A6A_NAEBVSpawnConditions@@AEAVBlockSource@@@Z@std@@XZ
     * @hash   798432303
     */
    MCAPI static class std::function<bool (class SpawnConditions const &, class BlockSource &)> getSpawnRulesCallback();

//protected:
    /**
     * @symbol ?justJumped@Slime@@IEAAXXZ
     * @hash   -2044889116
     */
    MCAPI void justJumped();
    /**
     * @symbol ?justLanded@Slime@@IEAAXXZ
     * @hash   -1299226367
     */
    MCAPI void justLanded();

protected:

};