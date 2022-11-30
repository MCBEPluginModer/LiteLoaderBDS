/**
 * @file  StructurePoolBlockPredicateBlockMatchRandom.hpp
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
 * @brief MC class StructurePoolBlockPredicateBlockMatchRandom.
 *
 */
class StructurePoolBlockPredicateBlockMatchRandom {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_STRUCTUREPOOLBLOCKPREDICATEBLOCKMATCHRANDOM
public:
    class StructurePoolBlockPredicateBlockMatchRandom& operator=(class StructurePoolBlockPredicateBlockMatchRandom const &) = delete;
    StructurePoolBlockPredicateBlockMatchRandom(class StructurePoolBlockPredicateBlockMatchRandom const &) = delete;
    StructurePoolBlockPredicateBlockMatchRandom() = delete;
#endif

public:
    /**
     * @vftbl  0
     * @hash   -2089134270
     */
    virtual ~StructurePoolBlockPredicateBlockMatchRandom();
    /**
     * @vftbl  1
     * @symbol ?test@StructurePoolBlockPredicateBlockMatchRandom@@UEBA_NAEBVBlock@@AEAVRandomize@@@Z
     * @hash   536100629
     */
    virtual bool test(class Block const &, class Randomize &) const;
    /**
     * @vftbl  2
     * @symbol ?test@StructurePoolBlockPredicateBlockMatchRandom@@UEBA_NAEBVBlockPos@@0AEAVRandomize@@@Z
     * @hash   -593541493
     */
    virtual bool test(class BlockPos const &, class BlockPos const &, class Randomize &) const;
    /**
     * @symbol ??0StructurePoolBlockPredicateBlockMatchRandom@@QEAA@AEBVBlock@@M@Z
     * @hash   -2027130458
     */
    MCAPI StructurePoolBlockPredicateBlockMatchRandom(class Block const &, float);

};