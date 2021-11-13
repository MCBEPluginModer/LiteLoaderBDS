// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#include <Global.h>
#include "Monster.hpp"
class EnderDragon : public Monster {
public:
    virtual void reloadHardcoded(int /*enum Actor::InitializationMethod*/, class VariantParameterList const&);
    virtual ~EnderDragon();
    virtual void remove();
    virtual bool isRuntimePredictedMovementEnabled();
    virtual void unk_vfn_22();
    virtual class Vec3 getInterpolatedRidingOffset(float);
    virtual void unk_vfn_41();
    virtual float getRidingHeight();
    virtual void unk_vfn_61();
    virtual void unk_vfn_68();
    virtual float getCameraOffset();
    virtual float getShadowRadius();
    virtual class Vec3 getHeadLookVector(float);
    virtual void unk_vfn_82();
    virtual void unk_vfn_87();
    virtual void playerTouch(class Player&);
    virtual bool isImmobile();
    virtual void unk_vfn_94();
    virtual void unk_vfn_97();
    virtual bool isDamageBlocked(class ActorDamageSource const&);
    virtual void unk_vfn_103();
    virtual void unk_vfn_104();
    virtual void unk_vfn_106();
    virtual void unk_vfn_107();
    virtual void unk_vfn_108();
    virtual bool isValidTarget(class Actor*);
    virtual void adjustDamageAmount(int&);
    virtual void setSitting(bool);
    virtual void onTame();
    virtual void onFailedTame();
    virtual void unk_vfn_130();
    virtual void vehicleLanded(class Vec3 const&, class Vec3 const&);
    virtual bool isInvulnerableTo(class ActorDamageSource const&);
    virtual void onBounceStarted(class BlockPos const&, class Block const&);
    virtual void handleEntityEvent(int /*enum ActorEvent*/, int);
    virtual void unk_vfn_144();
    virtual void awardKillScore(class Actor&, int);
    virtual int /*enum ActorType*/ getEntityTypeId();
    virtual class HashedString const& queryEntityRenderer();
    virtual struct ActorUniqueID getSourceUniqueID();
    virtual int getPortalWaitTime();
    virtual bool canChangeDimensions();
    virtual void unk_vfn_184();
    virtual struct ActorUniqueID getControllingPlayer();
    virtual bool canPickupItem(class ItemStack const&);
    virtual bool canBePulledIntoVehicle();
    virtual void unk_vfn_197();
    virtual bool canSynchronizeNewEntity();
    virtual bool canBeAffected(class MobEffectInstance const&);
    virtual void unk_vfn_222();
    virtual void unk_vfn_223();
    virtual bool isWorldBuilder();
    virtual void unk_vfn_229();
    virtual bool isAdventure();
    virtual bool canDestroyBlock(class Block const&);
    virtual void setAuxValue(int);
    virtual void stopSpinAttack();
    virtual void unk_vfn_243();
    virtual void unk_vfn_246();
    virtual void updateEntitySpecificMolangVariables(class RenderParams&);
    virtual void unk_vfn_258();
    virtual bool _hurt(class ActorDamageSource const&, int, bool, bool);
    virtual void unk_vfn_266();
    virtual void _onSizeUpdated();
    virtual void unk_vfn_275();
    virtual void spawnAnim();
    virtual void aiStep();
    virtual bool checkSpawnRules(bool);
    virtual int getItemUseDuration();
    virtual float getItemUseStartupProgress();
    virtual float getItemUseIntervalProgress();
    virtual void unk_vfn_305();
    virtual bool isAlliedTo(class Mob*);
    virtual void unk_vfn_309();
    virtual void sendArmorDamage(class std::bitset<4> const&);
    virtual void onBorn(class Actor&, class Actor&);
    virtual void unk_vfn_338();
    virtual void unk_vfn_341();
    virtual void _serverAiMobStep();
    virtual void tickDeath();
    virtual void unk_vfn_357();

public:
    MCAPI void dieNaturally();
    MCAPI int findClosestNode(class Vec3 const&);
    MCAPI int findClosestNode();
    MCAPI std::unique_ptr<class Path> findPath(int, int, class PathfinderNode*);
    MCAPI int getFlameCount() const;
    MCAPI float getFlapTime() const;
    MCAPI class BlockPos getHeadPos() const;
    MCAPI std::vector<float> const getLatencyPos(int, float) const;
    MCAPI int getNumCrystalsAlive();
    MCAPI class Vec3 getTargetPos() const;
    MCAPI void incrementFlameCount();
    MCAPI void onCrystalDestroyed(class EnderCrystal const&, class BlockPos, class ActorDamageSource const&);
    MCAPI void resetFlameCount();
    MCAPI void setDragonKilledCallback(class std::function<void(class EnderDragon&)>);
    MCAPI void setHasDragonPreviouslyBeenKilled(bool);
    MCAPI void setNumCrystalsAlive(int);
    MCAPI void setTargetPos(class Vec3);
    MCAPI void setTurnSpeed(float);

private:
    MCAPI void checkCrystals();
    MCAPI bool checkWalls(class AABB);
    MCAPI void hurtEntities(class gsl::span<class gsl::not_null<class Actor*>, -1>) const;
    MCAPI void knockBack(class gsl::span<class gsl::not_null<class Actor*>, -1>) const;
    MCAPI std::unique_ptr<class Path> reconstructPath(class PathfinderNode&, class PathfinderNode&, enum PathCompletionType);

    MCAPI static int GROWL_INTERVAL_MAX;
    MCAPI static int GROWL_INTERVAL_MIN;
    MCAPI static int MAX_PATH_RADIUS;
    MCAPI static float SITTING_ALLOWED_DAMAGE_PERCENTAGE;

protected:
    MCAPI bool _hurt(class AABB*, class ActorDamageSource const&, float);
};