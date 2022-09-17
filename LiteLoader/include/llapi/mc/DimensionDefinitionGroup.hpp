/**
 * @file  DimensionDefinitionGroup.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

/**
 * @brief MC class DimensionDefinitionGroup.
 *
 */
class DimensionDefinitionGroup {

#define AFTER_EXTRA
public:
    struct DimensionDefinition{};
#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_DIMENSIONDEFINITIONGROUP
public:
    class DimensionDefinitionGroup& operator=(class DimensionDefinitionGroup const &) = delete;
    DimensionDefinitionGroup(class DimensionDefinitionGroup const &) = delete;
    DimensionDefinitionGroup() = delete;
#endif

public:
    /**
     * @symbol ??0DimensionDefinitionGroup@@QEAA@QEAVResourcePackManager@@_N@Z
     * @hash   -879050833
     */
    MCAPI DimensionDefinitionGroup(class ResourcePackManager *const, bool);
    /**
     * @symbol ?getDimensionDefinition@DimensionDefinitionGroup@@QEBA?AV?$optional@UDimensionDefinition@DimensionDefinitionGroup@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@@Z
     * @hash   -1454202474
     */
    MCAPI class std::optional<struct DimensionDefinitionGroup::DimensionDefinition> getDimensionDefinition(std::string const &) const;
    /**
     * @symbol ?isEmpty@DimensionDefinitionGroup@@QEBA_NXZ
     * @hash   472018010
     */
    MCAPI bool isEmpty() const;
    /**
     * @symbol ?tryAddDimensionDefinitionByString@DimensionDefinitionGroup@@QEAA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
     * @hash   -1447322201
     */
    MCAPI bool tryAddDimensionDefinitionByString(std::string const &);
    /**
     * @symbol ??1DimensionDefinitionGroup@@QEAA@XZ
     * @hash   -1589447408
     */
    MCAPI ~DimensionDefinitionGroup();

};