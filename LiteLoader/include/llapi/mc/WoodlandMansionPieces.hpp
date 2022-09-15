/**
 * @file  WoodlandMansionPieces.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Bedrock.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC class WoodlandMansionPieces.
 *
 */
class WoodlandMansionPieces {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_WOODLANDMANSIONPIECES
public:
    class WoodlandMansionPieces& operator=(class WoodlandMansionPieces const &) = delete;
    WoodlandMansionPieces(class WoodlandMansionPieces const &) = delete;
    WoodlandMansionPieces() = delete;
#endif

public:
    /**
     * @symbol ?generateMansion@WoodlandMansionPieces@@SAXV?$not_null@V?$NonOwnerPointer@VStructureManager@@@Bedrock@@@gsl@@AEBVBlockPos@@W4Rotation@@AEAV?$vector@V?$unique_ptr@VStructurePiece@@U?$default_delete@VStructurePiece@@@std@@@std@@V?$allocator@V?$unique_ptr@VStructurePiece@@U?$default_delete@VStructurePiece@@@std@@@std@@@2@@std@@AEAVRandom@@@Z
     * @hash   -1809955327
     */
    MCAPI static void generateMansion(class gsl::not_null<class Bedrock::NonOwnerPointer<class StructureManager>>, class BlockPos const &, enum Rotation, std::vector<std::unique_ptr<class StructurePiece>> &, class Random &);

};