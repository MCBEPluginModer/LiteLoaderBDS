/**
 * @file  WeakStorageFeature.hpp
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
 * @brief MC class WeakStorageFeature.
 *
 */
class WeakStorageFeature {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_WEAKSTORAGEFEATURE
public:
    class WeakStorageFeature& operator=(class WeakStorageFeature const &) = delete;
    WeakStorageFeature(class WeakStorageFeature const &) = delete;
    WeakStorageFeature() = delete;
#endif

public:

//protected:
    /**
     * @symbol ??0WeakStorageFeature@@IEAA@W4EmptyInit@0@@Z
     * @hash   829753933
     */
    MCAPI WeakStorageFeature(enum class WeakStorageFeature::EmptyInit);
    /**
     * @symbol ??0WeakStorageFeature@@IEAA@AEBVOwnerStorageFeature@@@Z
     * @hash   324814696
     */
    MCAPI WeakStorageFeature(class OwnerStorageFeature const &);
    /**
     * @symbol ??0WeakStorageFeature@@IEAA@$$QEAV0@@Z
     * @hash   815575634
     */
    MCAPI WeakStorageFeature(class WeakStorageFeature &&);
    /**
     * @symbol ?_isSet@WeakStorageFeature@@IEBA_NXZ
     * @hash   -465129054
     */
    MCAPI bool _isSet() const;
    /**
     * @symbol ??4WeakStorageFeature@@IEAAAEAV0@$$QEAV0@@Z
     * @hash   1167715632
     */
    MCAPI class WeakStorageFeature & operator=(class WeakStorageFeature &&);

protected:

};