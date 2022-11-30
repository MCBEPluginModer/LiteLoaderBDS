/**
 * @file  GrowsCropDefinition.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "JsonUtil.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC class GrowsCropDefinition.
 *
 */
class GrowsCropDefinition {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_GROWSCROPDEFINITION
public:
    class GrowsCropDefinition& operator=(class GrowsCropDefinition const &) = delete;
    GrowsCropDefinition(class GrowsCropDefinition const &) = delete;
#endif

public:
    /**
     * @symbol ??0GrowsCropDefinition@@QEAA@XZ
     * @hash   -1006008513
     */
    MCAPI GrowsCropDefinition();
    /**
     * @symbol ?initialize@GrowsCropDefinition@@QEAAXAEAVEntityContext@@AEAVGrowsCropComponent@@@Z
     * @hash   756039429
     */
    MCAPI void initialize(class EntityContext &, class GrowsCropComponent &);
    /**
     * @symbol ?buildSchema@GrowsCropDefinition@@SAXAEAV?$shared_ptr@V?$JsonSchemaObjectNode@VEmptyClass@JsonUtil@@VGrowsCropDefinition@@@JsonUtil@@@std@@@Z
     * @hash   -1050622632
     */
    MCAPI static void buildSchema(class std::shared_ptr<class JsonUtil::JsonSchemaObjectNode<class JsonUtil::EmptyClass, class GrowsCropDefinition>> &);

};