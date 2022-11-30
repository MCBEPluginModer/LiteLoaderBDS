/**
 * @file  SerializedAbilitiesData.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
#include "LayeredAbilities.hpp"
#undef BEFORE_EXTRA

/**
 * @brief MC structure SerializedAbilitiesData.
 *
 */
struct SerializedAbilitiesData {

#define AFTER_EXTRA
    ActorUniqueID mUid;
    LayeredAbilities mAbilities;
#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SERIALIZEDABILITIESDATA
public:
    struct SerializedAbilitiesData& operator=(struct SerializedAbilitiesData const &) = delete;
    SerializedAbilitiesData(struct SerializedAbilitiesData const &) = delete;
#endif

public:
    /**
     * @symbol ??0SerializedAbilitiesData@@QEAA@XZ
     * @hash   681638394
     */
    MCAPI SerializedAbilitiesData();
    /**
     * @symbol ??0SerializedAbilitiesData@@QEAA@UActorUniqueID@@AEBVLayeredAbilities@@@Z
     * @hash   2048367378
     */
    MCAPI SerializedAbilitiesData(struct ActorUniqueID, class LayeredAbilities const &);
    /**
     * @symbol ?fillIn@SerializedAbilitiesData@@QEBAXAEAVLayeredAbilities@@@Z
     * @hash   1573292580
     */
    MCAPI void fillIn(class LayeredAbilities &) const;
    /**
     * @symbol ?getTargetPlayer@SerializedAbilitiesData@@QEBA?AUActorUniqueID@@XZ
     * @hash   -950278476
     */
    MCAPI struct ActorUniqueID getTargetPlayer() const;
    /**
     * @symbol ??1SerializedAbilitiesData@@QEAA@XZ
     * @hash   1926595930
     */
    MCAPI ~SerializedAbilitiesData();

//private:

};