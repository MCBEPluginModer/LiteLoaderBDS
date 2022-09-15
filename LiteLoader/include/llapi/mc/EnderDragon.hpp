/**
 * @file  EnderDragon.hpp
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
 * @brief MC class EnderDragon.
 *
 */
class EnderDragon : public Monster {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ENDERDRAGON
public:
    class EnderDragon& operator=(class EnderDragon const &) = delete;
    EnderDragon(class EnderDragon const &) = delete;
    EnderDragon() = delete;
#endif

public:
    /**
     * @vftbl  8
     * @symbol ?reloadHardcoded@EnderDragon@@UEAAXW4InitializationMethod@Actor@@AEBVVariantParameterList@@@Z
     * @hash   536722498
     */
    virtual void reloadHardcoded(enum Actor::InitializationMethod, class VariantParameterList const &);
    /**
     * @vftbl  14
     * @hash   -1172919607
     */
    virtual ~EnderDragon();
    /**
     * @vftbl  18
     * @symbol ?remove@EnderDragon@@UEAAXXZ
     * @hash   1469755616
     */
    virtual void remove();
    /**
     * @vftbl  41
     * @hash   -249160383
     */
    virtual void __unk_vfn_41();
    /**
     * @vftbl  61
     * @hash   -198636769
     */
    virtual void __unk_vfn_61();
    /**
     * @vftbl  68
     * @hash   -185437434
     */
    virtual void __unk_vfn_68();
    /**
     * @vftbl  80
     * @symbol ?getShadowRadius@EnderDragon@@UEBAMXZ
     * @hash   -512993045
     */
    virtual float getShadowRadius() const;
    /**
     * @vftbl  81
     * @symbol ?getHeadLookVector@EnderDragon@@UEBA?AVVec3@@M@Z
     * @hash   -1541836573
     */
    virtual class Vec3 getHeadLookVector(float) const;
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
     * @vftbl  92
     * @symbol ?isImmobile@EnderDragon@@UEBA_NXZ
     * @hash   1031050797
     */
    virtual bool isImmobile() const;
    /**
     * @vftbl  96
     * @hash   -101397023
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
     * @vftbl  120
     * @symbol ?setSitting@EnderDragon@@UEAAX_N@Z
     * @hash   191862262
     */
    virtual void setSitting(bool);
    /**
     * @vftbl  135
     * @symbol ?isInvulnerableTo@EnderDragon@@UEBA_NAEBVActorDamageSource@@@Z
     * @hash   1793206905
     */
    virtual bool isInvulnerableTo(class ActorDamageSource const &) const;
    /**
     * @vftbl  142
     * @symbol ?handleEntityEvent@EnderDragon@@UEAAXW4ActorEvent@@H@Z
     * @hash   -1007678421
     */
    virtual void handleEntityEvent(enum ActorEvent, int);
    /**
     * @vftbl  181
     * @symbol ?canChangeDimensionsUsingPortal@EnderDragon@@UEBA_NXZ
     * @hash   -291490112
     */
    virtual bool canChangeDimensionsUsingPortal() const;
    /**
     * @vftbl  182
     * @hash   1509264059
     */
    virtual void __unk_vfn_182();
    /**
     * @vftbl  194
     * @symbol ?canBePulledIntoVehicle@EnderDragon@@UEBA_NXZ
     * @hash   47876146
     */
    virtual bool canBePulledIntoVehicle() const;
    /**
     * @vftbl  196
     * @hash   1590605982
     */
    virtual void __unk_vfn_196();
    /**
     * @vftbl  212
     * @symbol ?canBeAffected@EnderDragon@@UEBA_NAEBVMobEffectInstance@@@Z
     * @hash   -1137032675
     */
    virtual bool canBeAffected(class MobEffectInstance const &) const;
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
     * @vftbl  267
     * @symbol ?updateEntitySpecificMolangVariables@EnderDragon@@UEAAXAEAVRenderParams@@@Z
     * @hash   -621672573
     */
    virtual void updateEntitySpecificMolangVariables(class RenderParams &);
    /**
     * @vftbl  269
     * @hash   -1906709211
     */
    virtual void __unk_vfn_269();
    /**
     * @vftbl  270
     * @symbol ?_hurt@EnderDragon@@MEAA_NAEBVActorDamageSource@@M_N1@Z
     * @hash   -491445131
     */
    virtual bool _hurt(class ActorDamageSource const &, float, bool, bool);
    /**
     * @vftbl  277
     * @hash   -1873192414
     */
    virtual void __unk_vfn_277();
    /**
     * @vftbl  284
     * @symbol ?_onSizeUpdated@EnderDragon@@EEAAXXZ
     * @hash   770426986
     */
    virtual void _onSizeUpdated();
    /**
     * @vftbl  285
     * @hash   -1895428993
     */
    virtual void __unk_vfn_285();
    /**
     * @vftbl  300
     * @symbol ?aiStep@EnderDragon@@UEAAXXZ
     * @hash   559065712
     */
    virtual void aiStep();
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
     * @vftbl  351
     * @hash   -1055222849
     */
    virtual void __unk_vfn_351();
    /**
     * @vftbl  363
     * @symbol ?tickDeath@EnderDragon@@MEAAXXZ
     * @hash   -868252596
     */
    virtual void tickDeath();
    /**
     * @vftbl  365
     * @hash   -1022899614
     */
    virtual void __unk_vfn_365();
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_ENDERDRAGON
    /**
     * @symbol ?canExistInPeaceful@EnderDragon@@UEBA_NXZ
     * @hash   -424249576
     */
    MCVAPI bool canExistInPeaceful() const;
    /**
     * @symbol ?isFishable@EnderDragon@@UEBA_NXZ
     * @hash   -517282791
     */
    MCVAPI bool isFishable() const;
#endif
    /**
     * @symbol ??0EnderDragon@@QEAA@PEAVActorDefinitionGroup@@AEBUActorDefinitionIdentifier@@AEAVEntityContext@@@Z
     * @hash   1203121623
     */
    MCAPI EnderDragon(class ActorDefinitionGroup *, struct ActorDefinitionIdentifier const &, class EntityContext &);
    /**
     * @symbol ?dieNaturally@EnderDragon@@QEAAXXZ
     * @hash   1548447935
     */
    MCAPI void dieNaturally();
    /**
     * @symbol ?findClosestNode@EnderDragon@@QEAAHAEBVVec3@@@Z
     * @hash   -344969475
     */
    MCAPI int findClosestNode(class Vec3 const &);
    /**
     * @symbol ?findClosestNode@EnderDragon@@QEAAHXZ
     * @hash   606332030
     */
    MCAPI int findClosestNode();
    /**
     * @symbol ?findPath@EnderDragon@@QEAA?AV?$unique_ptr@VPath@@U?$default_delete@VPath@@@std@@@std@@HHPEAVPathfinderNode@@@Z
     * @hash   35916934
     */
    MCAPI std::unique_ptr<class Path> findPath(int, int, class PathfinderNode *);
    /**
     * @symbol ?getFlameCount@EnderDragon@@QEBAHXZ
     * @hash   153011260
     */
    MCAPI int getFlameCount() const;
    /**
     * @symbol ?getFlapTime@EnderDragon@@QEBAMXZ
     * @hash   1556549478
     */
    MCAPI float getFlapTime() const;
    /**
     * @symbol ?getHeadPos@EnderDragon@@QEBA?AVBlockPos@@XZ
     * @hash   299182252
     */
    MCAPI class BlockPos getHeadPos() const;
    /**
     * @symbol ?getLatencyPos@EnderDragon@@QEBA?BV?$vector@MV?$allocator@M@std@@@std@@HM@Z
     * @hash   -1944264022
     */
    MCAPI std::vector<float> const getLatencyPos(int, float) const;
    /**
     * @symbol ?getNumCrystalsAlive@EnderDragon@@QEAAHXZ
     * @hash   -597411510
     */
    MCAPI int getNumCrystalsAlive();
    /**
     * @symbol ?getTargetPos@EnderDragon@@QEBA?AVVec3@@XZ
     * @hash   -1414517382
     */
    MCAPI class Vec3 getTargetPos() const;
    /**
     * @symbol ?incrementFlameCount@EnderDragon@@QEAAXXZ
     * @hash   1627369163
     */
    MCAPI void incrementFlameCount();
    /**
     * @symbol ?onCrystalDestroyed@EnderDragon@@QEAAXAEBVEnderCrystal@@VBlockPos@@AEBVActorDamageSource@@@Z
     * @hash   147240198
     */
    MCAPI void onCrystalDestroyed(class EnderCrystal const &, class BlockPos, class ActorDamageSource const &);
    /**
     * @symbol ?postAiStep@EnderDragon@@QEAAXXZ
     * @hash   -701349525
     */
    MCAPI void postAiStep();
    /**
     * @symbol ?resetFlameCount@EnderDragon@@QEAAXXZ
     * @hash   -1298559669
     */
    MCAPI void resetFlameCount();
    /**
     * @symbol ?setDragonKilledCallback@EnderDragon@@QEAAXV?$function@$$A6AXAEAVEnderDragon@@@Z@std@@@Z
     * @hash   804495437
     */
    MCAPI void setDragonKilledCallback(class std::function<void (class EnderDragon &)>);
    /**
     * @symbol ?setHasDragonPreviouslyBeenKilled@EnderDragon@@QEAAX_N@Z
     * @hash   -721126158
     */
    MCAPI void setHasDragonPreviouslyBeenKilled(bool);
    /**
     * @symbol ?setNumCrystalsAlive@EnderDragon@@QEAAXH@Z
     * @hash   -1069072994
     */
    MCAPI void setNumCrystalsAlive(int);
    /**
     * @symbol ?setTargetPos@EnderDragon@@QEAAXVVec3@@@Z
     * @hash   -77321922
     */
    MCAPI void setTargetPos(class Vec3);
    /**
     * @symbol ?setTurnSpeed@EnderDragon@@QEAAXM@Z
     * @hash   -1421211338
     */
    MCAPI void setTurnSpeed(float);

//protected:
    /**
     * @symbol ?_hurt@EnderDragon@@IEAA_NPEAVAABB@@AEBVActorDamageSource@@M@Z
     * @hash   -1411695712
     */
    MCAPI bool _hurt(class AABB *, class ActorDamageSource const &, float);

//private:
    /**
     * @symbol ?_checkCrystals@EnderDragon@@AEAAXXZ
     * @hash   -995875417
     */
    MCAPI void _checkCrystals();
    /**
     * @symbol ?_checkWalls@EnderDragon@@AEAA_NVAABB@@@Z
     * @hash   -938114152
     */
    MCAPI bool _checkWalls(class AABB);
    /**
     * @symbol ?_hurtEntities@EnderDragon@@AEBAXV?$span@V?$not_null@PEAVActor@@@gsl@@$0?0@gsl@@@Z
     * @hash   398432790
     */
    MCAPI void _hurtEntities(class gsl::span<class gsl::not_null<class Actor *>, -1>) const;
    /**
     * @symbol ?_knockBack@EnderDragon@@AEBAXV?$span@V?$not_null@PEAVActor@@@gsl@@$0?0@gsl@@@Z
     * @hash   -1497690215
     */
    MCAPI void _knockBack(class gsl::span<class gsl::not_null<class Actor *>, -1>) const;
    /**
     * @symbol ?_reconstructPath@EnderDragon@@AEAA?AV?$unique_ptr@VPath@@U?$default_delete@VPath@@@std@@@std@@AEAVPathfinderNode@@0W4PathCompletionType@@@Z
     * @hash   -828738453
     */
    MCAPI std::unique_ptr<class Path> _reconstructPath(class PathfinderNode &, class PathfinderNode &, enum PathCompletionType);
    /**
     * @symbol ?_isDragonImmuneBlock@EnderDragon@@CA_NAEBVBlockLegacy@@@Z
     * @hash   787916186
     */
    MCAPI static bool _isDragonImmuneBlock(class BlockLegacy const &);

protected:

private:
    /**
     * @symbol ?GROWL_INTERVAL_MAX@EnderDragon@@0HA
     * @hash   -984909748
     */
    MCAPI static int GROWL_INTERVAL_MAX;
    /**
     * @symbol ?GROWL_INTERVAL_MIN@EnderDragon@@0HA
     * @hash   -965976714
     */
    MCAPI static int GROWL_INTERVAL_MIN;
    /**
     * @symbol ?MAX_PATH_RADIUS@EnderDragon@@0HA
     * @hash   -887626187
     */
    MCAPI static int MAX_PATH_RADIUS;
    /**
     * @symbol ?SITTING_ALLOWED_DAMAGE_PERCENTAGE@EnderDragon@@0MA
     * @hash   894644051
     */
    MCAPI static float SITTING_ALLOWED_DAMAGE_PERCENTAGE;

};