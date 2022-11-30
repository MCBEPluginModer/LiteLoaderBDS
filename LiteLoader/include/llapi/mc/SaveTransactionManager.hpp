/**
 * @file  SaveTransactionManager.hpp
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
 * @brief MC class SaveTransactionManager.
 *
 */
class SaveTransactionManager {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SAVETRANSACTIONMANAGER
public:
    class SaveTransactionManager& operator=(class SaveTransactionManager const &) = delete;
    SaveTransactionManager(class SaveTransactionManager const &) = delete;
    SaveTransactionManager() = delete;
#endif

public:
    /**
     * @symbol ??0SaveTransactionManager@@QEAA@AEAVWorkerPool@@AEAVScheduler@@V?$function@$$A6AX_N@Z@std@@@Z
     * @hash   -546186960
     */
    MCAPI SaveTransactionManager(class WorkerPool &, class Scheduler &, class std::function<void (bool)>);
    /**
     * @symbol ?onBeginCompaction@SaveTransactionManager@@QEAAXXZ
     * @hash   1799540259
     */
    MCAPI void onBeginCompaction();
    /**
     * @symbol ?onEndCompaction@SaveTransactionManager@@QEAAXXZ
     * @hash   1779718963
     */
    MCAPI void onEndCompaction();

//private:
    /**
     * @symbol ?_hideGlobalSaveIcon@SaveTransactionManager@@AEAAXXZ
     * @hash   -1322600886
     */
    MCAPI void _hideGlobalSaveIcon();
    /**
     * @symbol ?_showGlobalSaveIcon@SaveTransactionManager@@AEAAXXZ
     * @hash   -137579387
     */
    MCAPI void _showGlobalSaveIcon();

private:

};