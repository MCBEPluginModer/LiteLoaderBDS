/**
 * @file  ExperienceRewardComponent.hpp
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
 * @brief MC class ExperienceRewardComponent.
 *
 */
class ExperienceRewardComponent {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_EXPERIENCEREWARDCOMPONENT
public:
    class ExperienceRewardComponent& operator=(class ExperienceRewardComponent const &) = delete;
    ExperienceRewardComponent(class ExperienceRewardComponent const &) = delete;
    ExperienceRewardComponent() = delete;
#endif

public:
    /**
     * @symbol ?addAdditionalSaveData@ExperienceRewardComponent@@QEBAXAEAVCompoundTag@@@Z
     * @hash   951813720
     */
    MCAPI void addAdditionalSaveData(class CompoundTag &) const;
    /**
     * @symbol ?getIsExperienceDropEnabled@ExperienceRewardComponent@@QEBA_NXZ
     * @hash   1666378968
     */
    MCAPI bool getIsExperienceDropEnabled() const;
    /**
     * @symbol ?getOnBredExperience@ExperienceRewardComponent@@QEBAHAEAVActor@@@Z
     * @hash   -343891319
     */
    MCAPI int getOnBredExperience(class Actor &) const;
    /**
     * @symbol ?getOnDeathExperience@ExperienceRewardComponent@@QEBAHAEAVActor@@@Z
     * @hash   -1631114427
     */
    MCAPI int getOnDeathExperience(class Actor &) const;
    /**
     * @symbol ??4ExperienceRewardComponent@@QEAAAEAV0@$$QEAV0@@Z
     * @hash   -1740191892
     */
    MCAPI class ExperienceRewardComponent & operator=(class ExperienceRewardComponent &&);
    /**
     * @symbol ?readAdditionalSaveData@ExperienceRewardComponent@@QEAAXAEAVActor@@AEBVCompoundTag@@AEAVDataLoadHelper@@@Z
     * @hash   1790615208
     */
    MCAPI void readAdditionalSaveData(class Actor &, class CompoundTag const &, class DataLoadHelper &);
    /**
     * @symbol ?setIsExperienceDropEnabled@ExperienceRewardComponent@@QEAAX_N@Z
     * @hash   -1813605900
     */
    MCAPI void setIsExperienceDropEnabled(bool);

//private:

private:
    /**
     * @symbol ?mIsExperienceDropEnabledTag@ExperienceRewardComponent@@0V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@B
     * @hash   -1932720344
     */
    MCAPI static std::string const mIsExperienceDropEnabledTag;

};