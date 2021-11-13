// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#include <Global.h>
#include "Item.hpp"
class ComponentItem : public Item {
public:
    virtual ~ComponentItem();
    virtual bool initServer(class Json::Value&, class SemVersion const&);
    virtual void tearDown();
    virtual int getMaxUseDuration(class ItemStack const*);
    virtual void unk_vfn_4();
    virtual void unk_vfn_5();
    virtual void executeEvent(class ItemStackBase&, std::string const&, class RenderParams&);
    virtual void unk_vfn_7();
    virtual bool isArmor();
    virtual bool isBlockPlanterItem();
    virtual void unk_vfn_10();
    virtual void unk_vfn_12();
    virtual bool isDamageable();
    virtual bool isDyeable();
    virtual bool isDye();
    virtual int /*enum ItemColor*/ getItemColor();
    virtual bool isFertilizer();
    virtual void unk_vfn_18();
    virtual bool isThrowable();
    virtual bool isUseable();
    virtual class IFoodItemComponent* getFood();
    virtual class FuelItemComponent* getFuel();
    virtual class Item& setMaxDamage(int);
    virtual void unk_vfn_35();
    virtual bool canBeDepleted();
    virtual bool canDestroySpecial(class Block const&);
    virtual int getLevelDataForAuxValue(int);
    virtual short getMaxDamage();
    virtual int getAttackDamage();
    virtual bool isGlint(class ItemStackBase const&);
    virtual void unk_vfn_44();
    virtual void unk_vfn_45();
    virtual void unk_vfn_46();
    virtual bool isWearableThroughLootTable(class CompoundTag const*);
    virtual bool canDestroyInCreative();
    virtual bool isDestructive(int);
    virtual bool isLiquidClipItem(int);
    virtual bool shouldInteractionWithBlockBypassLiquid(class Block const&);
    virtual bool requiresInteract();
    virtual void appendFormattedHovertext(class ItemStackBase const&, class Level&, std::string&, bool);
    virtual bool isValidRepairItem(class ItemStackBase const&, class ItemStackBase const&, class BaseGameVersion const&);
    virtual int getEnchantSlot();
    virtual int getEnchantValue();
    virtual int getArmorValue();
    virtual void unk_vfn_58();
    virtual bool isValidAuxValue(int);
    virtual int getDamageChance(int);
    virtual void unk_vfn_61();
    virtual void unk_vfn_62();
    virtual void unk_vfn_63();
    virtual void unk_vfn_64();
    virtual class mce::Color getColor(class CompoundTag const*, class ItemDescriptor const&);
    virtual bool hasCustomColor(class CompoundTag const*);
    virtual void unk_vfn_67();
    virtual void clearColor(class CompoundTag*);
    virtual void unk_vfn_69();
    virtual void unk_vfn_70();
    virtual void unk_vfn_71();
    virtual void unk_vfn_72();
    virtual void unk_vfn_74();
    virtual void unk_vfn_75();
    virtual void unk_vfn_77();
    virtual class ItemStack& use(class ItemStack&, class Player&);
    virtual bool dispense(class BlockSource&, class Container&, int, class Vec3 const&, unsigned char);
    virtual int /*enum ItemUseMethod*/ useTimeDepleted(class ItemStack&, class Level*, class Player*);
    virtual void releaseUsing(class ItemStack&, class Player*, int);
    virtual float getDestroySpeed(class ItemStackBase const&, class Block const&);
    virtual void hurtActor(class ItemStack&, class Actor&, class Mob&);
    virtual void hitActor(class ItemStack&, class Actor&, class Mob&);
    virtual void hitBlock(class ItemStack&, class Block const&, class BlockPos const&, class Mob&);
    virtual bool mineBlock(class ItemStack&, class Block const&, int, int, int, class Actor*);
    virtual bool mineBlock(class ItemInstance&, class Block const&, int, int, int, class Actor*);
    virtual void unk_vfn_88();
    virtual std::string buildDescriptionId(class ItemDescriptor const&, class CompoundTag const*);
    virtual std::string buildEffectDescriptionName(class ItemStackBase const&);
    virtual unsigned char getMaxStackSize(class ItemDescriptor const&);
    virtual bool inventoryTick(class ItemStack&, class Level&, class Actor&, int, bool);
    virtual void refreshedInContainer(class ItemStackBase const&, class Level&);
    virtual class HashedString const& getCooldownType();
    virtual int getCooldownTime();
    virtual void fixupCommon(class ItemStackBase&, class Level&);
    virtual void unk_vfn_103();
    virtual void unk_vfn_104();
    virtual bool validFishInteraction(int);
    virtual void initClient(class Json::Value&, class SemVersion const&);
    virtual std::string getInteractText(class Player const&);
    virtual int getAnimationFrameFor(class Mob*, bool, class ItemStack const*, bool);
    virtual bool isEmissive(int);
    virtual struct TextureUVCoordinateSet const& getIcon(class ItemStackBase const&, int, bool);
    virtual int getIconYOffset();
    virtual class Item& setIcon(std::string const&, int);
    virtual bool canBeCharged();
    virtual void playSoundIncrementally(class ItemStack const&, class Mob&);
    virtual void unk_vfn_119();
    virtual std::string getAuxValuesDescription();
    virtual bool _checkUseOnPermissions(class Actor&, class ItemStackBase&, unsigned char const&, class BlockPos const&);
    virtual bool _calculatePlacePos(class ItemStackBase&, class Actor&, unsigned char&, class BlockPos&);
    virtual bool _useOn(class ItemStack&, class Actor&, class BlockPos, unsigned char, float, float, float);
    virtual void unk_vfn_126();
    virtual void unk_vfn_127();

public:
    MCAPI void _addCerealItemsToMap();
    MCAPI class std::shared_ptr<class JsonUtil::JsonSchemaObjectNode<class JsonUtil::EmptyClass, class ComponentItem>> _buildItemsFileSchema(class std::shared_ptr<class JsonUtil::JsonSchemaObjectNode<class JsonUtil::EmptyClass, class ComponentItem>>&, bool, class SemVersion);
    MCAPI bool _validateClientSchemaAndInitItem(class Json::Value&, class SemVersion const&);
    MCAPI bool _validateServerSchemaAndInitItem(class Json::Value&, class SemVersion const&);
    MCAPI std::unique_ptr<class CompoundTag> buildNetworkTag() const;
    MCAPI bool checkComponentDataForContentErrors() const;
    MCAPI bool executeTrigger(class ItemStackBase&, class DefinitionTrigger const&, class RenderParams&) const;
    MCAPI class ArmorItemComponent* getArmor() const;
    MCAPI class ItemComponent* getComponent(class HashedString const&) const;
    MCAPI class DamageableItemComponent* getDamageable() const;
    MCAPI class DyeableComponent* getDyeable() const;
    MCAPI class KnockbackResistanceItemComponent* getKnockbackResistance() const;
    MCAPI class ProjectileItemComponent* getProjectile() const;
    MCAPI class RecordItemComponent* getRecordComponent() const;
    MCAPI class RepairableItemComponent* getRepairable() const;
    MCAPI class WearableItemComponent* getWearable() const;
    MCAPI void initializeFromNetwork(class CompoundTag const&);
    MCAPI bool parseJsonEvents(class Json::Value const&, class SemVersion const&);

    MCAPI static void registerItemComponentTypes();

private:
    MCAPI std::unique_ptr<class CompoundTag> _buildItemProperitesNetworkTag() const;
    MCAPI void _loadItemProperitesNetworkTag(class CompoundTag const&);
};