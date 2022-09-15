/**
 * @file  JigsawJunction.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

/**
 * @brief MC structure JigsawJunction.
 *
 */
struct JigsawJunction {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_JIGSAWJUNCTION
public:
    struct JigsawJunction& operator=(struct JigsawJunction const &) = delete;
    JigsawJunction(struct JigsawJunction const &) = delete;
    JigsawJunction() = delete;
#endif

public:
    /**
     * @symbol ??0JigsawJunction@@QEAA@HHHHW4Projection@@0@Z
     * @hash   -1066582701
     */
    MCAPI JigsawJunction(int, int, int, int, enum Projection, enum Projection);
    /**
     * @symbol ?getDeltaTargetY@JigsawJunction@@QEBAHXZ
     * @hash   -1145927610
     */
    MCAPI int getDeltaTargetY() const;

};