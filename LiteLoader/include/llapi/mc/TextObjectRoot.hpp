/**
 * @file  TextObjectRoot.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Json.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC class TextObjectRoot.
 *
 */
class TextObjectRoot {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_TEXTOBJECTROOT
public:
    class TextObjectRoot& operator=(class TextObjectRoot const &) = delete;
    TextObjectRoot(class TextObjectRoot const &) = delete;
    TextObjectRoot() = delete;
#endif

public:
    /**
     * @vftbl  0
     * @hash   728688024
     */
    virtual ~TextObjectRoot();
    /**
     * @vftbl  1
     * @symbol ?asString@TextObjectRoot@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
     * @hash   -865801985
     */
    virtual std::string asString() const;
    /**
     * @vftbl  2
     * @symbol ?asJsonValue@TextObjectRoot@@UEBA?AVValue@Json@@XZ
     * @hash   -873354257
     */
    virtual class Json::Value asJsonValue() const;
    /**
     * @vftbl  3
     * @symbol ?resolve@TextObjectRoot@@UEBA?AVValue@Json@@AEBUResolveData@@@Z
     * @hash   275012656
     */
    virtual class Json::Value resolve(struct ResolveData const &) const;
    /**
     * @symbol ?addChild@TextObjectRoot@@QEAAXV?$unique_ptr@VITextObject@@U?$default_delete@VITextObject@@@std@@@std@@@Z
     * @hash   874371650
     */
    MCAPI void addChild(std::unique_ptr<class ITextObject>);
    /**
     * @symbol ?clear@TextObjectRoot@@QEAAXXZ
     * @hash   257542131
     */
    MCAPI void clear();
    /**
     * @symbol ?isEmpty@TextObjectRoot@@QEBA_NXZ
     * @hash   1926503066
     */
    MCAPI bool isEmpty() const;
    /**
     * @symbol ?resolveRoot@TextObjectRoot@@QEBA?AVResolvedTextObject@@AEBVActor@@AEBVScoreboard@@@Z
     * @hash   -838260254
     */
    MCAPI class ResolvedTextObject resolveRoot(class Actor const &, class Scoreboard const &) const;

};