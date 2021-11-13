// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#include <Global.h>
#include "LootItemFunction.hpp"
class SetBannerDetailsFunction : public LootItemFunction {
public:
    virtual ~SetBannerDetailsFunction();
    virtual void apply(class ItemInstance&, class Random&, class LootTableContext&);
    virtual void apply(class ItemStack&, class Random&, class LootTableContext&);

private:
    MCAPI void _apply(class ItemStackBase&, class Random&, class LootTableContext&) const;

    MCAPI static void _parseBannerPattern(std::vector<struct std::pair<unsigned char, enum ItemColor>>&, class Json::Value const&);
};