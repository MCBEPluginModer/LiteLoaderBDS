/**
 * @file  SeatDescription.hpp
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
 * @brief MC structure SeatDescription.
 *
 */
struct SeatDescription {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SEATDESCRIPTION
public:
    SeatDescription() = delete;
#endif

public:
    /**
     * @symbol ??0SeatDescription@@QEAA@AEBU0@@Z
     * @hash   314768357
     */
    MCAPI SeatDescription(struct SeatDescription const &);
    /**
     * @symbol ?addRotationExpressionNode@SeatDescription@@QEAAXAEBVExpressionNode@@@Z
     * @hash   -1940700140
     */
    MCAPI void addRotationExpressionNode(class ExpressionNode const &);
    /**
     * @symbol ??4SeatDescription@@QEAAAEAU0@AEBU0@@Z
     * @hash   -923918210
     */
    MCAPI struct SeatDescription & operator=(struct SeatDescription const &);
    /**
     * @symbol ??4SeatDescription@@QEAAAEAU0@$$QEAU0@@Z
     * @hash   -519813714
     */
    MCAPI struct SeatDescription & operator=(struct SeatDescription &&);
    /**
     * @symbol ??8SeatDescription@@QEBA_NAEBU0@@Z
     * @hash   -1348903772
     */
    MCAPI bool operator==(struct SeatDescription const &) const;
    /**
     * @symbol ??1SeatDescription@@QEAA@XZ
     * @hash   2075380675
     */
    MCAPI ~SeatDescription();
    /**
     * @symbol ?EMPTY@SeatDescription@@2U1@B
     * @hash   -2080577241
     */
    MCAPI static struct SeatDescription const EMPTY;

};