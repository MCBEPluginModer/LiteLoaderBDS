/**
 * @file  Player.hpp
 *
 */
#pragma once
#define AUTO_GENERATED
#include "llapi/Global.h"
#include "Actor.hpp"
#include "Bedrock.hpp"
#include "Editor.hpp"
#include "Mob.hpp"

#define BEFORE_EXTRA
// Add include headers & pre-declares
class ServerPlayer;
class Player;
class NetworkIdentifier;
class Certificate; 
class Container;
class CompoundTag;
class LayeredAbilities;

class Biome;
#include "UserEntityIdentifierComponent.hpp"
#include "ScorePacketInfo.hpp"
#include "DataItem.hpp"
#include "../I18nAPI.h"
#undef BEFORE_EXTRA

/**
 * @brief The player
 */
class Player : public Mob {

#define AFTER_EXTRA
    // Add new members to class
public:
    enum class PositionMode : char {
        NORMAL,
        RESPAWN,
        TELEPORT,
        HEAD_ROTATION,
    };

    enum class NbtDataType :int {
        Snbt,
        Binary,
        Json,
        Unknown,
    };
    
    LIAPI std::string getName();

    /**
     * @brief Get the real name of the player.
     * 
     * @return The real name of the player
     * 
     * @note This method gets the XBOX account name of the player.
     */
    LIAPI std::string getRealName();

    LIAPI std::string getUuid();
    LIAPI unsigned char getClientSubId();
    LIAPI string getDeviceTypeName();
    LIAPI int getAvgPing();
    LIAPI int getLastPing();
    LIAPI std::string getIP();
    LIAPI string getLanguageCode();
    LIAPI string getServerAddress();
    LIAPI NetworkIdentifier* getNetworkIdentifier();
    LIAPI Certificate* getCertificate();
    LIAPI Container* getEnderChestContainer();
    LIAPI std::pair<BlockPos, int> getRespawnPosition();
    LIAPI float getAvgPacketLoss();
    LIAPI float getLastPacketLoss();
    LIAPI string getClientId();
    LIAPI int getDeviceType();
    LIAPI bool isOperator();
    LIAPI bool isOP();

    LIAPI int getCurrentExperience();
    LIAPI bool setCurrentExperience(int exp);
    LIAPI size_t getTotalExperience();
    LIAPI bool setTotalExperience(size_t exp);
    LIAPI bool reduceExperience(size_t exp);

    LIAPI void setAbility(AbilitiesIndex index, bool value);
	
    // Experience required to upgrade to level from (level-1)
    LIAPI static int getXpNeededForLevel(int level);

    // Experience required to upgrade to level from level 0
    LIAPI static size_t getTotalXpNeededForLevel(int level);

    template <typename... Args>
    inline std::string trImpl(HMODULE hPlugin, const std::string& format, Args&&... args) {
        return Translation::trlImpl(hPlugin, this->getLanguageCode(), format, std::forward<Args>(args)...);
    }

    template <typename... Args>
    inline std::string tr(const std::string& format, Args&&... args) {
        return trImpl(GetCurrentModule(), format, std::forward<Args>(args)...);
    }

    LIAPI bool sendText(const std::string& text, TextType type = TextType::RAW);

    template <TextType ttype = TextType::RAW, typename... Args>
    inline bool trSendText(const std::string& text, Args&&... args) {
        return sendText(this->tr(text, std::forward<Args>(args)...), ttype);
    }
    template <typename... Args>
    inline bool sendFormattedText(const std::string& text, Args&&... args) {
        if constexpr (0 == sizeof...(args)) {
            // Avoid fmt if only one argument
            return sendText(text);
        } else {
            return sendText(fmt::format(text, std::forward<Args>(args)...));
        }
    }

    LIAPI bool kick(const string& msg);
    LIAPI bool crashClient();
    LIAPI bool talkAs(const string& msg);

    /**
     * @brief Give the player items.
     * 
     * @param item The items to give
     * @return True if the player is successfully given the items; otherwise false
     */
    LIAPI bool giveItem(ItemStack* item);
    LIAPI bool giveItem(std::string typeName, int amount);
    LIAPI bool giveItem(ItemStack* item, int amount);

    [[deprecated]] LIAPI int clearItem(std::string typeName);
    LIAPI unsigned int clearItem(std::string_view typeName, unsigned int clearCount);
    LIAPI bool runcmd(const string& cmd);
    LIAPI bool transferServer(const std::string& address, unsigned short port);
    LIAPI bool setSidebar(const std::string& title, const std::vector<std::pair<std::string, int>>& data, ObjectiveSortOrder sortOrder);
    LIAPI bool removeSidebar();

    LIAPI std::unique_ptr<CompoundTag> getNbt();
    LIAPI bool setNbt(CompoundTag* nbt);

    LIAPI static bool setPlayerNbt(mce::UUID const& uuid, CompoundTag* nbt);
    LIAPI static bool setPlayerNbtTags(mce::UUID const& uuid, CompoundTag* nbt, const vector<string>& tags);
    LIAPI static bool deletePlayerNbt(mce::UUID const& uuid);
    LIAPI static std::unique_ptr<CompoundTag> getPlayerNbt(mce::UUID const& uuid);
    LIAPI static std::vector<string> getAllUuid(bool includeSelfSignedId);

    LIAPI bool refreshAttribute(class Attribute const& attribute);
    LIAPI bool refreshAttributes(std::vector<Attribute const*> const& attributes);
    LIAPI void addBossEvent(int64_t uid, string name, float percent, BossEventColour colour, int overlay = 0);
    LIAPI void removeBossEvent(int64_t uid);
    LIAPI void updateBossEvent(int64_t uid, string name, float percent, BossEventColour colour, int overlay = 0);

    LIAPI int getScore(const string& key);
    LIAPI bool setScore(const string& key, int value);
    LIAPI bool addScore(const string& key, int value);
    LIAPI bool reduceScore(const string& key, int value);
    LIAPI bool deleteScore(const string& key);

    // Form
    LIAPI bool sendSimpleForm(const string& title, const string& content, const vector<string>& buttons, const std::vector<std::string>& images, std::function<void(Player*, int)> callback) const;
    LIAPI bool sendModalForm(const string& title, const string& content, const string& confirmButton, const string& cancelButton, std::function<void(Player*, bool)> callback) const;
    LIAPI bool sendCustomForm(const std::string& data, std::function<void(Player*, string)> callback) const;

    // Packet
    LIAPI bool sendTextPacket(string text, TextType Type = TextType::RAW) const;

    /**
     * @brief Display a title on the player's screen.
     * 
     * @param text The texts of the title
     * @param Type The type of the title
     * @param FadeInDuration The fade in duration
     * @param RemainDuration The lasting time
     * @param FadeOutDuration The fade out duration
     * @return True if the title is successfully shown; otherwise false
     */
    LIAPI bool sendTitlePacket(string text, TitleType Type, int FadeInDuration, int RemainDuration, int FadeOutDuration) const;

    LIAPI bool sendNotePacket(unsigned int tone);
    LIAPI bool sendSpawnParticleEffectPacket(Vec3 spawnPos, int dimid, string ParticleName, int64_t EntityUniqueID = -1) const;
    /*bad*/ LIAPI bool sendPlaySoundPacket(string SoundName, Vec3 Position, float Volume, float Pitch) const;
    LIAPI bool sendAddItemEntityPacket(unsigned long long runtimeID, class Item const& item, int stackSize, short aux, Vec3 pos, vector<std::unique_ptr<DataItem>> dataItems = {}) const;
    LIAPI bool sendAddEntityPacket(unsigned long long runtimeID, string entityType, Vec3 pos, Vec2 rotation, float headYaw, vector<std::unique_ptr<DataItem>> dataItems = {});
    LIAPI bool sendUpdateBlockPacket(BlockPos const& blockPos, unsigned int runtimeId, UpdateBlockFlags flag = UpdateBlockFlags::BlockUpdateAll, UpdateBlockLayer layer = UpdateBlockLayer::UpdateBlockDefault);
    LIAPI bool sendUpdateBlockPacket(BlockPos const& blockPos, const Block& block, UpdateBlockFlags flag = UpdateBlockFlags::BlockUpdateAll, UpdateBlockLayer layer = UpdateBlockLayer::UpdateBlockDefault);
    LIAPI bool sendTransferPacket(const string& address, short port) const;
    LIAPI bool sendSetDisplayObjectivePacket(const string& title, const string& name, char sortOrder) const;
    LIAPI bool sendSetScorePacket(char type, const vector<ScorePacketInfo>& data);
    LIAPI bool sendBossEventPacket(BossEvent type, string name, float percent, BossEventColour colour, int overlay = 0);
    LIAPI bool sendCommandRequestPacket(const string& cmd);
    LIAPI bool sendTextTalkPacket(const string& msg);
    LIAPI bool sendTextTalkPacket(const string& msg, Player* target /* = nullptr*/);

    LIAPI bool sendRawFormPacket(unsigned formId, const string& data) const;
    LIAPI bool sendToastPacket(string title, string msg);

    LIAPI static bool isValid(Player* player);

    // For compatibility
    inline string getDeviceName() {
        return getDeviceTypeName();
    }
    LIAPI bool sendSimpleFormPacket(const string& title, const string& content, const vector<string>& buttons, const std::vector<std::string>& images, std::function<void(int)> callback) const;
    LIAPI bool sendModalFormPacket(const string& title, const string& content, const string& button1, const string& button2, std::function<void(bool)> callback);
    LIAPI bool sendCustomFormPacket(const std::string& data, std::function<void(string)> callback);
    LIAPI std::pair<Vec3, int> getLastDeathPosition();

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_PLAYER
public:
    class Player& operator=(class Player const &) = delete;
    Player(class Player const &) = delete;
    Player() = delete;
#endif

public:
    /**
     * @vftbl 10
     * @symbol ?reloadHardcoded\@Player\@\@UEAAXW4InitializationMethod\@Actor\@\@AEBVVariantParameterList\@\@\@Z
     */
    virtual void reloadHardcoded(enum class Actor::InitializationMethod, class VariantParameterList const &);
    /**
     * @vftbl 12
     * @symbol ?initializeComponents\@Player\@\@UEAAXW4InitializationMethod\@Actor\@\@AEBVVariantParameterList\@\@\@Z
     */
    virtual void initializeComponents(enum class Actor::InitializationMethod, class VariantParameterList const &);
    /**
     * @vftbl 14
     * @symbol ?_serverInitItemStackIds\@Player\@\@MEAAXXZ
     */
    virtual void _serverInitItemStackIds();
    /**
     * @vftbl 16
     * @symbol __unk_vfn_16
     */
    virtual void __unk_vfn_16();
    /**
     * @vftbl 17
     * @symbol ?resetUserPos\@Player\@\@UEAAX_N\@Z
     */
    virtual void resetUserPos(bool);
    /**
     * @vftbl 19
     * @symbol ?remove\@Player\@\@UEAAXXZ
     */
    virtual void remove();
    /**
     * @vftbl 26
     * @symbol ?getAttachPos\@Player\@\@UEBA?AVVec3\@\@W4ActorLocation\@\@M\@Z
     */
    virtual class Vec3 getAttachPos(enum class ActorLocation, float) const;
    /**
     * @vftbl 28
     * @symbol ?move\@Player\@\@UEAAXAEBVVec3\@\@\@Z
     */
    virtual void move(class Vec3 const &);
    /**
     * @vftbl 29
     * @symbol ?move\@Player\@\@UEBAXAEAUIActorMovementProxy\@\@AEBVVec3\@\@\@Z
     */
    virtual void move(struct IActorMovementProxy &, class Vec3 const &) const;
    /**
     * @vftbl 36
     * @symbol ?getInterpolatedRidingOffset\@Player\@\@UEBA?AVVec3\@\@MH\@Z
     */
    virtual class Vec3 getInterpolatedRidingOffset(float, int) const;
    /**
     * @vftbl 40
     * @symbol ?isFireImmune\@Player\@\@UEBA_NXZ
     */
    virtual bool isFireImmune() const;
    /**
     * @vftbl 41
     * @symbol __unk_vfn_41
     */
    virtual void __unk_vfn_41();
    /**
     * @vftbl 44
     * @symbol ?teleportTo\@Player\@\@UEAAXAEBVVec3\@\@_NHH1\@Z
     */
    virtual void teleportTo(class Vec3 const &, bool, int, int, bool);
    /**
     * @vftbl 48
     * @symbol ?tryCreateAddActorPacket\@Player\@\@UEAA?AV?$unique_ptr\@VAddActorBasePacket\@\@U?$default_delete\@VAddActorBasePacket\@\@\@std\@\@\@std\@\@XZ
     */
    virtual std::unique_ptr<class AddActorBasePacket> tryCreateAddActorPacket();
    /**
     * @vftbl 49
     * @symbol ?normalTick\@Player\@\@UEAAXXZ
     */
    virtual void normalTick();
    /**
     * @vftbl 51
     * @symbol ?passengerTick\@Player\@\@UEAAXXZ
     */
    virtual void passengerTick();
    /**
     * @vftbl 62
     * @symbol __unk_vfn_62
     */
    virtual void __unk_vfn_62();
    /**
     * @vftbl 66
     * @symbol ?getFormattedNameTag\@Player\@\@UEBA?AV?$basic_string\@DU?$char_traits\@D\@std\@\@V?$allocator\@D\@2\@\@std\@\@XZ
     */
    virtual std::string getFormattedNameTag() const;
    /**
     * @vftbl 69
     * @symbol __unk_vfn_69
     */
    virtual void __unk_vfn_69();
    /**
     * @vftbl 76
     * @symbol ?setBlockMovementSlowdownMultiplier\@Player\@\@UEAAXAEBVBlockLegacy\@\@AEBVVec3\@\@\@Z
     */
    virtual void setBlockMovementSlowdownMultiplier(class BlockLegacy const &, class Vec3 const &);
    /**
     * @vftbl 78
     * @symbol ?getCameraOffset\@Player\@\@UEBAMXZ
     */
    virtual float getCameraOffset() const;
    /**
     * @vftbl 80
     * @symbol ?getShadowRadius\@Player\@\@UEBAMXZ
     */
    virtual float getShadowRadius() const;
    /**
     * @vftbl 82
     * @symbol __unk_vfn_82
     */
    virtual void __unk_vfn_82();
    /**
     * @vftbl 85
     * @symbol __unk_vfn_85
     */
    virtual void __unk_vfn_85();
    /**
     * @vftbl 88
     * @symbol __unk_vfn_88
     */
    virtual void __unk_vfn_88();
    /**
     * @vftbl 92
     * @symbol ?isImmobile\@Player\@\@UEBA_NXZ
     */
    virtual bool isImmobile() const;
    /**
     * @vftbl 94
     * @symbol ?isSilentObserver\@Player\@\@UEBA_NXZ
     */
    virtual bool isSilentObserver() const;
    /**
     * @vftbl 96
     * @symbol __unk_vfn_96
     */
    virtual void __unk_vfn_96();
    /**
     * @vftbl 97
     * @symbol ?isSleeping\@Player\@\@UEBA_NXZ
     */
    virtual bool isSleeping() const;
    /**
     * @vftbl 98
     * @symbol ?setSleeping\@Player\@\@UEAAX_N\@Z
     */
    virtual void setSleeping(bool);
    /**
     * @vftbl 99
     * @symbol __unk_vfn_99
     */
    virtual void __unk_vfn_99();
    /**
     * @vftbl 101
     * @symbol ?isBlocking\@Player\@\@UEBA_NXZ
     */
    virtual bool isBlocking() const;
    /**
     * @vftbl 102
     * @symbol ?isDamageBlocked\@Player\@\@UEBA_NAEBVActorDamageSource\@\@\@Z
     */
    virtual bool isDamageBlocked(class ActorDamageSource const &) const;
    /**
     * @vftbl 106
     * @symbol __unk_vfn_106
     */
    virtual void __unk_vfn_106();
    /**
     * @vftbl 108
     * @symbol __unk_vfn_108
     */
    virtual void __unk_vfn_108();
    /**
     * @vftbl 109
     * @symbol __unk_vfn_109
     */
    virtual void __unk_vfn_109();
    /**
     * @vftbl 111
     * @symbol __unk_vfn_111
     */
    virtual void __unk_vfn_111();
    /**
     * @vftbl 116
     * @symbol ?attack\@Player\@\@UEAA_NAEAVActor\@\@AEBW4ActorDamageCause\@\@\@Z
     */
    virtual bool attack(class Actor &, enum class ActorDamageCause const &);
    /**
     * @vftbl 134
     * @symbol ?isInvulnerableTo\@Player\@\@UEBA_NAEBVActorDamageSource\@\@\@Z
     */
    virtual bool isInvulnerableTo(class ActorDamageSource const &) const;
    /**
     * @vftbl 139
     * @symbol ?onBounceStarted\@Player\@\@MEAAXAEBVBlockPos\@\@AEBVBlock\@\@\@Z
     */
    virtual void onBounceStarted(class BlockPos const &, class Block const &);
    /**
     * @vftbl 140
     * @symbol ?feed\@Player\@\@UEAAXH\@Z
     */
    virtual void feed(int);
    /**
     * @vftbl 141
     * @symbol ?handleEntityEvent\@Player\@\@UEAAXW4ActorEvent\@\@H\@Z
     */
    virtual void handleEntityEvent(enum class ActorEvent, int);
    /**
     * @vftbl 143
     * @symbol ?getActorRendererId\@Player\@\@UEBAAEBVHashedString\@\@XZ
     */
    virtual class HashedString const & getActorRendererId() const;
    /**
     * @vftbl 149
     * @symbol ?awardKillScore\@Player\@\@UEAAXAEAVActor\@\@H\@Z
     */
    virtual void awardKillScore(class Actor &, int);
    /**
     * @vftbl 150
     * @symbol ?setArmor\@Player\@\@UEAAXW4ArmorSlot\@\@AEBVItemStack\@\@\@Z
     */
    virtual void setArmor(enum class ArmorSlot, class ItemStack const &);
    /**
     * @vftbl 158
     * @symbol ?setCarriedItem\@Player\@\@UEAAXAEBVItemStack\@\@\@Z
     */
    virtual void setCarriedItem(class ItemStack const &);
    /**
     * @vftbl 159
     * @symbol ?getCarriedItem\@Player\@\@UEBAAEBVItemStack\@\@XZ
     */
    virtual class ItemStack const & getCarriedItem() const;
    /**
     * @vftbl 160
     * @symbol ?setOffhandSlot\@Player\@\@UEAAXAEBVItemStack\@\@\@Z
     */
    virtual void setOffhandSlot(class ItemStack const &);
    /**
     * @vftbl 161
     * @symbol ?getEquippedTotem\@Player\@\@UEBAAEBVItemStack\@\@XZ
     */
    virtual class ItemStack const & getEquippedTotem() const;
    /**
     * @vftbl 162
     * @symbol ?consumeTotem\@Player\@\@UEAA_NXZ
     */
    virtual bool consumeTotem();
    /**
     * @vftbl 167
     * @symbol ?getEntityTypeId\@Player\@\@UEBA?AW4ActorType\@\@XZ
     */
    virtual enum class ActorType getEntityTypeId() const;
    /**
     * @vftbl 171
     * @symbol ?canFreeze\@Player\@\@UEBA_NXZ
     */
    virtual bool canFreeze() const;
    /**
     * @vftbl 175
     * @symbol ?getPortalCooldown\@Player\@\@UEBAHXZ
     */
    virtual int getPortalCooldown() const;
    /**
     * @vftbl 176
     * @symbol ?getPortalWaitTime\@Player\@\@UEBAHXZ
     */
    virtual int getPortalWaitTime() const;
    /**
     * @vftbl 177
     * @symbol ?canChangeDimensionsUsingPortal\@Player\@\@UEBA_NXZ
     */
    virtual bool canChangeDimensionsUsingPortal() const;
    /**
     * @vftbl 178
     * @symbol __unk_vfn_178
     */
    virtual void __unk_vfn_178();
    /**
     * @vftbl 187
     * @symbol ?onSynchedDataUpdate\@Player\@\@UEAAXH\@Z
     */
    virtual void onSynchedDataUpdate(int);
    /**
     * @vftbl 188
     * @symbol ?canAddPassenger\@Player\@\@UEBA_NAEAVActor\@\@\@Z
     */
    virtual bool canAddPassenger(class Actor &) const;
    /**
     * @vftbl 190
     * @symbol ?canBePulledIntoVehicle\@Player\@\@UEBA_NXZ
     */
    virtual bool canBePulledIntoVehicle() const;
    /**
     * @vftbl 192
     * @symbol __unk_vfn_192
     */
    virtual void __unk_vfn_192();
    /**
     * @vftbl 194
     * @symbol ?sendMotionPacketIfNeeded\@Player\@\@UEAAXXZ
     */
    virtual void sendMotionPacketIfNeeded();
    /**
     * @vftbl 197
     * @symbol ?startSwimming\@Player\@\@UEAAXXZ
     */
    virtual void startSwimming();
    /**
     * @vftbl 198
     * @symbol ?stopSwimming\@Player\@\@UEAAXXZ
     */
    virtual void stopSwimming();
    /**
     * @vftbl 200
     * @symbol ?getCommandPermissionLevel\@Player\@\@UEBA?AW4CommandPermissionLevel\@\@XZ
     */
    virtual enum class CommandPermissionLevel getCommandPermissionLevel() const;
    /**
     * @vftbl 212
     * @symbol ?canObstructSpawningAndBlockPlacement\@Player\@\@UEBA_NXZ
     */
    virtual bool canObstructSpawningAndBlockPlacement() const;
    /**
     * @vftbl 213
     * @symbol ?getAnimationComponent\@Player\@\@UEAAAEAVAnimationComponent\@\@XZ
     */
    virtual class AnimationComponent & getAnimationComponent();
    /**
     * @vftbl 216
     * @symbol ?useItem\@Player\@\@UEAAXAEAVItemStackBase\@\@W4ItemUseMethod\@\@_N\@Z
     */
    virtual void useItem(class ItemStackBase &, enum class ItemUseMethod, bool);
    /**
     * @vftbl 217
     * @symbol __unk_vfn_217
     */
    virtual void __unk_vfn_217();
    /**
     * @vftbl 218
     * @symbol __unk_vfn_218
     */
    virtual void __unk_vfn_218();
    /**
     * @vftbl 220
     * @symbol ?getMapDecorationRotation\@Player\@\@UEBAMXZ
     */
    virtual float getMapDecorationRotation() const;
    /**
     * @vftbl 222
     * @symbol ?isWorldBuilder\@Player\@\@UEBA_NXZ
     */
    virtual bool isWorldBuilder() const;
    /**
     * @vftbl 223
     * @symbol ?isCreative\@Player\@\@UEBA_NXZ
     */
    virtual bool isCreative() const;
    /**
     * @vftbl 224
     * @symbol ?isAdventure\@Player\@\@UEBA_NXZ
     */
    virtual bool isAdventure() const;
    /**
     * @vftbl 225
     * @symbol ?isSurvival\@Player\@\@UEBA_NXZ
     */
    virtual bool isSurvival() const;
    /**
     * @vftbl 226
     * @symbol ?isSpectator\@Player\@\@UEBA_NXZ
     */
    virtual bool isSpectator() const;
    /**
     * @vftbl 228
     * @symbol ?add\@Player\@\@UEAA_NAEAVItemStack\@\@\@Z
     */
    virtual bool add(class ItemStack &);
    /**
     * @vftbl 229
     * @symbol ?drop\@Player\@\@UEAA_NAEBVItemStack\@\@_N\@Z
     */
    virtual bool drop(class ItemStack const &, bool);
    /**
     * @vftbl 237
     * @symbol ?startSpinAttack\@Player\@\@UEAAXXZ
     */
    virtual void startSpinAttack();
    /**
     * @vftbl 238
     * @symbol ?stopSpinAttack\@Player\@\@UEAAXXZ
     */
    virtual void stopSpinAttack();
    /**
     * @vftbl 240
     * @symbol __unk_vfn_240
     */
    virtual void __unk_vfn_240();
    /**
     * @vftbl 243
     * @symbol __unk_vfn_243
     */
    virtual void __unk_vfn_243();
    /**
     * @vftbl 245
     * @symbol ?die\@Player\@\@UEAAXAEBVActorDamageSource\@\@\@Z
     */
    virtual void die(class ActorDamageSource const &);
    /**
     * @vftbl 246
     * @symbol ?shouldDropDeathLoot\@Player\@\@UEBA_NXZ
     */
    virtual bool shouldDropDeathLoot() const;
    /**
     * @vftbl 252
     * @symbol ?getLastDeathPos\@Player\@\@UEBA?AV?$optional\@VBlockPos\@\@\@std\@\@XZ
     */
    virtual class std::optional<class BlockPos> getLastDeathPos() const;
    /**
     * @vftbl 253
     * @symbol ?getLastDeathDimension\@Player\@\@UEBA?AV?$optional\@V?$AutomaticID\@VDimension\@\@H\@\@\@std\@\@XZ
     */
    virtual class std::optional<class AutomaticID<class Dimension, int>> getLastDeathDimension() const;
    /**
     * @vftbl 254
     * @symbol ?hasDiedBefore\@Player\@\@UEBA_NXZ
     */
    virtual bool hasDiedBefore() const;
    /**
     * @vftbl 256
     * @symbol ?_shouldProvideFeedbackOnHandContainerItemSet\@Player\@\@MEBA_NW4HandSlot\@\@AEBVItemStack\@\@\@Z
     */
    virtual bool _shouldProvideFeedbackOnHandContainerItemSet(enum class HandSlot, class ItemStack const &) const;
    /**
     * @vftbl 257
     * @symbol ?_shouldProvideFeedbackOnArmorSet\@Player\@\@MEBA_NW4ArmorSlot\@\@AEBVItemStack\@\@\@Z
     */
    virtual bool _shouldProvideFeedbackOnArmorSet(enum class ArmorSlot, class ItemStack const &) const;
    /**
     * @vftbl 260
     * @symbol __unk_vfn_260
     */
    virtual void __unk_vfn_260();
    /**
     * @vftbl 261
     * @symbol ?_hurt\@Player\@\@MEAA_NAEBVActorDamageSource\@\@M_N1\@Z
     */
    virtual bool _hurt(class ActorDamageSource const &, float, bool, bool);
    /**
     * @vftbl 264
     * @symbol ?readAdditionalSaveData\@Player\@\@MEAAXAEBVCompoundTag\@\@AEAVDataLoadHelper\@\@\@Z
     */
    virtual void readAdditionalSaveData(class CompoundTag const &, class DataLoadHelper &);
    /**
     * @vftbl 265
     * @symbol ?addAdditionalSaveData\@Player\@\@MEBAXAEAVCompoundTag\@\@\@Z
     */
    virtual void addAdditionalSaveData(class CompoundTag &) const;
    /**
     * @vftbl 268
     * @symbol __unk_vfn_268
     */
    virtual void __unk_vfn_268();
    /**
     * @vftbl 274
     * @symbol ?_onSizeUpdated\@Player\@\@EEAAXXZ
     */
    virtual void _onSizeUpdated();
    /**
     * @vftbl 275
     * @symbol __unk_vfn_275
     */
    virtual void __unk_vfn_275();
    /**
     * @vftbl 281
     * @symbol ?getSpeed\@Player\@\@UEBAMXZ
     */
    virtual float getSpeed() const;
    /**
     * @vftbl 282
     * @symbol ?setSpeed\@Player\@\@UEAAXM\@Z
     */
    virtual void setSpeed(float);
    /**
     * @vftbl 286
     * @symbol ?travel\@Player\@\@UEAAXMMM_N\@Z
     */
    virtual void travel(float, float, float, bool);
    /**
     * @vftbl 288
     * @symbol ?aiStep\@Player\@\@UEAAXXZ
     */
    virtual void aiStep();
    /**
     * @vftbl 289
     * @symbol ?aiStep\@Player\@\@UEBAXAEAUIMobMovementProxy\@\@\@Z
     */
    virtual void aiStep(struct IMobMovementProxy &) const;
    /**
     * @vftbl 296
     * @symbol ?getItemUseDuration\@Player\@\@UEBAHXZ
     */
    virtual int getItemUseDuration() const;
    /**
     * @vftbl 297
     * @symbol ?getItemUseStartupProgress\@Player\@\@UEBAMXZ
     */
    virtual float getItemUseStartupProgress() const;
    /**
     * @vftbl 298
     * @symbol ?getItemUseIntervalProgress\@Player\@\@UEBAMXZ
     */
    virtual float getItemUseIntervalProgress() const;
    /**
     * @vftbl 301
     * @symbol __unk_vfn_301
     */
    virtual void __unk_vfn_301();
    /**
     * @vftbl 305
     * @symbol __unk_vfn_305
     */
    virtual void __unk_vfn_305();
    /**
     * @vftbl 321
     * @symbol ?getAllHand\@Player\@\@UEBA?AV?$vector\@PEBVItemStack\@\@V?$allocator\@PEBVItemStack\@\@\@std\@\@\@std\@\@XZ
     */
    virtual std::vector<class ItemStack const *> getAllHand() const;
    /**
     * @vftbl 322
     * @symbol ?getAllEquipment\@Player\@\@UEBA?AV?$vector\@PEBVItemStack\@\@V?$allocator\@PEBVItemStack\@\@\@std\@\@\@std\@\@XZ
     */
    virtual std::vector<class ItemStack const *> getAllEquipment() const;
    /**
     * @vftbl 324
     * @symbol ?dropEquipmentOnDeath\@Player\@\@UEAAXAEBVActorDamageSource\@\@H\@Z
     */
    virtual void dropEquipmentOnDeath(class ActorDamageSource const &, int);
    /**
     * @vftbl 325
     * @symbol ?dropEquipmentOnDeath\@Player\@\@UEAAXXZ
     */
    virtual void dropEquipmentOnDeath();
    /**
     * @vftbl 326
     * @symbol ?clearVanishEnchantedItemsOnDeath\@Player\@\@UEAAXXZ
     */
    virtual void clearVanishEnchantedItemsOnDeath();
    /**
     * @vftbl 327
     * @symbol ?sendInventory\@Player\@\@UEAAX_N\@Z
     */
    virtual void sendInventory(bool);
    /**
     * @vftbl 338
     * @symbol ?canExistWhenDisallowMob\@Player\@\@UEBA_NXZ
     */
    virtual bool canExistWhenDisallowMob() const;
    /**
     * @vftbl 343
     * @symbol ?initBodyControl\@Player\@\@EEAA?AV?$unique_ptr\@VBodyControl\@\@U?$default_delete\@VBodyControl\@\@\@std\@\@\@std\@\@XZ
     */
    virtual std::unique_ptr<class BodyControl> initBodyControl();
    /**
     * @vftbl 344
     * @symbol ?jumpFromGround\@Player\@\@UEAAXAEBVIConstBlockSource\@\@\@Z
     */
    virtual void jumpFromGround(class IConstBlockSource const &);
    /**
     * @vftbl 345
     * @symbol ?jumpFromGround\@Player\@\@UEBAXAEAUIMobMovementProxy\@\@AEBVIConstBlockSource\@\@\@Z
     */
    virtual void jumpFromGround(struct IMobMovementProxy &, class IConstBlockSource const &) const;
    /**
     * @vftbl 350
     * @symbol ?updateGliding\@Player\@\@MEAAXXZ
     */
    virtual void updateGliding();
    /**
     * @vftbl 351
     * @symbol __unk_vfn_351
     */
    virtual void __unk_vfn_351();
    /**
     * @vftbl 353
     * @symbol ?prepareRegion\@Player\@\@UEAAXAEAVChunkSource\@\@\@Z
     */
    virtual void prepareRegion(class ChunkSource &);
    /**
     * @vftbl 354
     * @symbol ?destroyRegion\@Player\@\@UEAAXXZ
     */
    virtual void destroyRegion();
    /**
     * @vftbl 355
     * @symbol ?suspendRegion\@Player\@\@UEAAXXZ
     */
    virtual void suspendRegion();
    /**
     * @vftbl 356
     * @symbol ?resendAllChunks\@Player\@\@UEAAXXZ
     */
    virtual void resendAllChunks();
    /**
     * @vftbl 357
     * @symbol ?_fireWillChangeDimension\@Player\@\@UEAAXXZ
     */
    virtual void _fireWillChangeDimension();
    /**
     * @vftbl 358
     * @symbol ?_fireDimensionChanged\@Player\@\@UEAAXXZ
     */
    virtual void _fireDimensionChanged();
    /**
     * @vftbl 359
     * @symbol ?changeDimensionWithCredits\@Player\@\@UEAAXV?$AutomaticID\@VDimension\@\@H\@\@\@Z
     */
    virtual void changeDimensionWithCredits(class AutomaticID<class Dimension, int>);
    /**
     * @vftbl 360
     * @symbol ?tickWorld\@Player\@\@UEAAXAEBUTick\@\@\@Z
     */
    virtual void tickWorld(struct Tick const &);
    /**
     * @vftbl 361
     * @symbol __unk_vfn_361
     */
    virtual void __unk_vfn_361() = 0;
    /**
     * @vftbl 362
     * @symbol ?getTickingOffsets\@Player\@\@UEBAAEBV?$vector\@VChunkPos\@\@V?$allocator\@VChunkPos\@\@\@std\@\@\@std\@\@XZ
     */
    virtual std::vector<class ChunkPos> const & getTickingOffsets() const;
    /**
     * @vftbl 363
     * @symbol ?moveView\@Player\@\@UEAAXXZ
     */
    virtual void moveView();
    /**
     * @vftbl 364
     * @symbol ?moveSpawnView\@Player\@\@UEAAXAEBVVec3\@\@V?$AutomaticID\@VDimension\@\@H\@\@\@Z
     */
    virtual void moveSpawnView(class Vec3 const &, class AutomaticID<class Dimension, int>);
    /**
     * @vftbl 365
     * @symbol ?setName\@Player\@\@UEAAXAEBV?$basic_string\@DU?$char_traits\@D\@std\@\@V?$allocator\@D\@2\@\@std\@\@\@Z
     */
    virtual void setName(std::string const &);
    /**
     * @vftbl 366
     * @symbol ?getTravelledMethod\@Player\@\@UEBA?AW4TravelMethod\@\@XZ
     */
    virtual enum class TravelMethod getTravelledMethod() const;
    /**
     * @vftbl 367
     * @symbol ?checkMovementStats\@Player\@\@UEAAXAEBVVec3\@\@\@Z
     */
    virtual void checkMovementStats(class Vec3 const &);
    /**
     * @vftbl 368
     * @symbol __unk_vfn_368
     */
    virtual void __unk_vfn_368();
    /**
     * @vftbl 369
     * @symbol __unk_vfn_369
     */
    virtual void __unk_vfn_369();
    /**
     * @vftbl 370
     * @symbol ?respawn\@Player\@\@UEAAXXZ
     */
    virtual void respawn();
    /**
     * @vftbl 371
     * @symbol __unk_vfn_371
     */
    virtual void __unk_vfn_371();
    /**
     * @vftbl 372
     * @symbol __unk_vfn_372
     */
    virtual void __unk_vfn_372();
    /**
     * @vftbl 373
     * @symbol ?hasResource\@Player\@\@UEAA_NH\@Z
     */
    virtual bool hasResource(int);
    /**
     * @vftbl 374
     * @symbol ?completeUsingItem\@Player\@\@UEAAXXZ
     */
    virtual void completeUsingItem();
    /**
     * @vftbl 375
     * @symbol ?startDestroying\@Player\@\@UEAAXXZ
     */
    virtual void startDestroying();
    /**
     * @vftbl 376
     * @symbol ?stopDestroying\@Player\@\@UEAAXXZ
     */
    virtual void stopDestroying();
    /**
     * @vftbl 377
     * @symbol __unk_vfn_377
     */
    virtual void __unk_vfn_377();
    /**
     * @vftbl 378
     * @symbol __unk_vfn_378
     */
    virtual void __unk_vfn_378();
    /**
     * @vftbl 379
     * @symbol ?openTrading\@Player\@\@UEAAXAEBUActorUniqueID\@\@_N\@Z
     */
    virtual void openTrading(struct ActorUniqueID const &, bool);
    /**
     * @vftbl 380
     * @symbol ?canOpenContainerScreen\@Player\@\@UEAA_NXZ
     */
    virtual bool canOpenContainerScreen();
    /**
     * @vftbl 381
     * @symbol __unk_vfn_381
     */
    virtual void __unk_vfn_381();
    /**
     * @vftbl 382
     * @symbol ?openNpcInteractScreen\@Player\@\@UEAAXV?$shared_ptr\@UINpcDialogueData\@\@\@std\@\@\@Z
     */
    virtual void openNpcInteractScreen(class std::shared_ptr<struct INpcDialogueData>);
    /**
     * @vftbl 383
     * @symbol ?openInventory\@Player\@\@UEAAXXZ
     */
    virtual void openInventory();
    /**
     * @vftbl 384
     * @symbol __unk_vfn_384
     */
    virtual void __unk_vfn_384();
    /**
     * @vftbl 385
     * @symbol __unk_vfn_385
     */
    virtual void __unk_vfn_385();
    /**
     * @vftbl 386
     * @symbol ?displayTextObjectMessage\@Player\@\@UEAAXAEBVTextObjectRoot\@\@AEBV?$basic_string\@DU?$char_traits\@D\@std\@\@V?$allocator\@D\@2\@\@std\@\@1\@Z
     */
    virtual void displayTextObjectMessage(class TextObjectRoot const &, std::string const &, std::string const &);
    /**
     * @vftbl 387
     * @symbol ?displayTextObjectWhisperMessage\@Player\@\@UEAAXAEBVResolvedTextObject\@\@AEBV?$basic_string\@DU?$char_traits\@D\@std\@\@V?$allocator\@D\@2\@\@std\@\@1\@Z
     */
    virtual void displayTextObjectWhisperMessage(class ResolvedTextObject const &, std::string const &, std::string const &);
    /**
     * @vftbl 388
     * @symbol ?displayTextObjectWhisperMessage\@Player\@\@UEAAXAEBV?$basic_string\@DU?$char_traits\@D\@std\@\@V?$allocator\@D\@2\@\@std\@\@00\@Z
     */
    virtual void displayTextObjectWhisperMessage(std::string const &, std::string const &, std::string const &);
    /**
     * @vftbl 389
     * @symbol ?displayWhisperMessage\@Player\@\@UEAAXAEBV?$basic_string\@DU?$char_traits\@D\@std\@\@V?$allocator\@D\@2\@\@std\@\@000\@Z
     */
    virtual void displayWhisperMessage(std::string const &, std::string const &, std::string const &, std::string const &);
    /**
     * @vftbl 390
     * @symbol ?startSleepInBed\@Player\@\@UEAA?AW4BedSleepingResult\@\@AEBVBlockPos\@\@\@Z
     */
    virtual enum class BedSleepingResult startSleepInBed(class BlockPos const &);
    /**
     * @vftbl 391
     * @symbol ?stopSleepInBed\@Player\@\@UEAAX_N0\@Z
     */
    virtual void stopSleepInBed(bool, bool);
    /**
     * @vftbl 392
     * @symbol ?canStartSleepInBed\@Player\@\@UEAA_NXZ
     */
    virtual bool canStartSleepInBed();
    /**
     * @vftbl 393
     * @symbol ?getSleepTimer\@Player\@\@UEBAHXZ
     */
    virtual int getSleepTimer() const;
    /**
     * @vftbl 394
     * @symbol ?getPreviousTickSleepTimer\@Player\@\@UEBAHXZ
     */
    virtual int getPreviousTickSleepTimer() const;
    /**
     * @vftbl 395
     * @symbol __unk_vfn_395
     */
    virtual void __unk_vfn_395();
    /**
     * @vftbl 396
     * @symbol __unk_vfn_396
     */
    virtual void __unk_vfn_396();
    /**
     * @vftbl 397
     * @symbol ?isHostingPlayer\@Player\@\@UEBA_NXZ
     */
    virtual bool isHostingPlayer() const;
    /**
     * @vftbl 398
     * @symbol ?isLoading\@Player\@\@UEBA_NXZ
     */
    virtual bool isLoading() const;
    /**
     * @vftbl 399
     * @symbol ?isPlayerInitialized\@Player\@\@UEBA_NXZ
     */
    virtual bool isPlayerInitialized() const;
    /**
     * @vftbl 400
     * @symbol __unk_vfn_400
     */
    virtual void __unk_vfn_400();
    /**
     * @vftbl 401
     * @symbol ?registerTrackedBoss\@Player\@\@UEAAXUActorUniqueID\@\@\@Z
     */
    virtual void registerTrackedBoss(struct ActorUniqueID);
    /**
     * @vftbl 402
     * @symbol ?unRegisterTrackedBoss\@Player\@\@UEAAXUActorUniqueID\@\@\@Z
     */
    virtual void unRegisterTrackedBoss(struct ActorUniqueID);
    /**
     * @vftbl 403
     * @symbol ?setPlayerGameType\@Player\@\@UEAAXW4GameType\@\@\@Z
     */
    virtual void setPlayerGameType(enum class GameType);
    /**
     * @vftbl 404
     * @symbol ?initHUDContainerManager\@Player\@\@UEAAXXZ
     */
    virtual void initHUDContainerManager();
    /**
     * @vftbl 405
     * @symbol ?_crit\@Player\@\@UEAAXAEAVActor\@\@\@Z
     */
    virtual void _crit(class Actor &);
    /**
     * @vftbl 406
     * @symbol ?getEventing\@Player\@\@UEBAPEAVIMinecraftEventing\@\@XZ
     */
    virtual class IMinecraftEventing * getEventing() const;
    /**
     * @vftbl 407
     * @symbol __unk_vfn_407
     */
    virtual void __unk_vfn_407();
    /**
     * @vftbl 408
     * @symbol ?sendEventPacket\@Player\@\@UEBAXAEAVEventPacket\@\@\@Z
     */
    virtual void sendEventPacket(class EventPacket &) const;
    /**
     * @vftbl 409
     * @symbol ?addExperience\@Player\@\@UEAAXH\@Z
     */
    virtual void addExperience(int);
    /**
     * @vftbl 410
     * @symbol ?addLevels\@Player\@\@UEAAXH\@Z
     */
    virtual void addLevels(int);
    /**
     * @vftbl 411
     * @symbol ?setContainerData\@ServerPlayer\@\@UEAAXAEAVIContainerManager\@\@HH\@Z
     */
    virtual void setContainerData(class IContainerManager &, int, int) = 0;
    /**
     * @vftbl 412
     * @symbol ?slotChanged\@ServerPlayer\@\@UEAAXAEAVIContainerManager\@\@AEAVContainer\@\@HAEBVItemStack\@\@2_N\@Z
     */
    virtual void slotChanged(class IContainerManager &, class Container &, int, class ItemStack const &, class ItemStack const &, bool) = 0;
    /**
     * @vftbl 413
     * @symbol ?inventoryChanged\@Player\@\@UEAAXAEAVContainer\@\@HAEBVItemStack\@\@1_N\@Z
     */
    virtual void inventoryChanged(class Container &, int, class ItemStack const &, class ItemStack const &, bool);
    /**
     * @vftbl 414
     * @symbol ?refreshContainer\@ServerPlayer\@\@UEAAXAEAVIContainerManager\@\@\@Z
     */
    virtual void refreshContainer(class IContainerManager &) = 0;
    /**
     * @vftbl 415
     * @symbol ?deleteContainerManager\@Player\@\@UEAAXXZ
     */
    virtual void deleteContainerManager();
    /**
     * @vftbl 416
     * @symbol ?isActorRelevant\@Player\@\@UEAA_NAEBVActor\@\@\@Z
     */
    virtual bool isActorRelevant(class Actor const &);
    /**
     * @vftbl 417
     * @symbol ?isTeacher\@ServerPlayer\@\@UEBA_NXZ
     */
    virtual bool isTeacher() const = 0;
    /**
     * @vftbl 418
     * @symbol ?onSuspension\@Player\@\@UEAAXXZ
     */
    virtual void onSuspension();
    /**
     * @vftbl 419
     * @symbol ?onLinkedSlotsChanged\@Player\@\@UEAAXXZ
     */
    virtual void onLinkedSlotsChanged();
    /**
     * @vftbl 420
     * @symbol ?startCooldown\@Player\@\@UEAAXPEBVItem\@\@_N\@Z
     */
    virtual void startCooldown(class Item const *, bool);
    /**
     * @vftbl 421
     * @symbol ?getItemCooldownLeft\@Player\@\@UEBAHAEBVHashedString\@\@\@Z
     */
    virtual int getItemCooldownLeft(class HashedString const &) const;
    /**
     * @vftbl 422
     * @symbol ?getItemCooldownLeft\@Player\@\@UEBAH_K\@Z
     */
    virtual int getItemCooldownLeft(unsigned __int64) const;
    /**
     * @vftbl 423
     * @symbol ?getMaxItemCooldownLeft\@Player\@\@UEBAHXZ
     */
    virtual int getMaxItemCooldownLeft() const;
    /**
     * @vftbl 424
     * @symbol ?isItemOnCooldown\@Player\@\@UEBA_NAEBVHashedString\@\@\@Z
     */
    virtual bool isItemOnCooldown(class HashedString const &) const;
    /**
     * @vftbl 425
     * @symbol ?sendInventoryTransaction\@ServerPlayer\@\@UEBAXAEBVInventoryTransaction\@\@\@Z
     */
    virtual void sendInventoryTransaction(class InventoryTransaction const &) const = 0;
    /**
     * @vftbl 426
     * @symbol ?sendComplexInventoryTransaction\@ServerPlayer\@\@UEBAXV?$unique_ptr\@VComplexInventoryTransaction\@\@U?$default_delete\@VComplexInventoryTransaction\@\@\@std\@\@\@std\@\@\@Z
     */
    virtual void sendComplexInventoryTransaction(std::unique_ptr<class ComplexInventoryTransaction>) const = 0;
    /**
     * @vftbl 427
     * @symbol ?sendNetworkPacket\@Player\@\@UEBAXAEAVPacket\@\@\@Z
     */
    virtual void sendNetworkPacket(class Packet &) const;
    /**
     * @vftbl 428
     * @symbol ?getPlayerEventCoordinator\@ServerPlayer\@\@UEAAAEAVPlayerEventCoordinator\@\@XZ
     */
    virtual class PlayerEventCoordinator & getPlayerEventCoordinator() = 0;
    /**
     * @vftbl 429
     * @symbol ?tryGetMoveInputHandler\@ServerPlayer\@\@UEBAPEAVMoveInputHandler\@\@XZ
     */
    virtual class MoveInputHandler * tryGetMoveInputHandler() const = 0;
    /**
     * @vftbl 430
     * @symbol ?getInputMode\@ServerPlayer\@\@UEBA?AW4InputMode\@\@XZ
     */
    virtual enum class InputMode getInputMode() const = 0;
    /**
     * @vftbl 431
     * @symbol ?getPlayMode\@ServerPlayer\@\@UEBA?AW4ClientPlayMode\@\@XZ
     */
    virtual enum class ClientPlayMode getPlayMode() const = 0;
    /**
     * @vftbl 432
     * @symbol ?reportMovementTelemetry\@Player\@\@UEAAXW4MovementEventType\@\@\@Z
     */
    virtual void reportMovementTelemetry(enum class MovementEventType);
    /**
     * @vftbl 433
     * @symbol __unk_vfn_433
     */
    virtual void __unk_vfn_433();
    /**
     * @vftbl 434
     * @symbol ?getXuid\@Player\@\@UEBA?AV?$basic_string\@DU?$char_traits\@D\@std\@\@V?$allocator\@D\@2\@\@std\@\@XZ
     */
    virtual std::string getXuid() const;
    /**
     * @vftbl 435
     * @symbol ?getMovementSettings\@Player\@\@UEBAAEBUPlayerMovementSettings\@\@XZ
     */
    virtual struct PlayerMovementSettings const & getMovementSettings() const;
    /**
     * @vftbl 436
     * @symbol __unk_vfn_436
     */
    virtual void __unk_vfn_436();
    /**
     * @vftbl 437
     * @symbol ?onMovePlayerPacketNormal\@Player\@\@MEAAXAEBVVec3\@\@AEBVVec2\@\@M\@Z
     */
    virtual void onMovePlayerPacketNormal(class Vec3 const &, class Vec2 const &, float);
    /**
     * @vftbl 438
     * @symbol ?_createChunkSource\@Player\@\@MEAA?AV?$shared_ptr\@VChunkViewSource\@\@\@std\@\@AEAVChunkSource\@\@\@Z
     */
    virtual class std::shared_ptr<class ChunkViewSource> _createChunkSource(class ChunkSource &);
    /**
     * @vftbl 439
     * @symbol ?setAbilities\@Player\@\@UEAAXAEBVLayeredAbilities\@\@\@Z
     */
    virtual void setAbilities(class LayeredAbilities const &);
    /**
     * @vftbl 440
     * @symbol ?getEditorPlayer\@ServerPlayer\@\@UEBA?AV?$NonOwnerPointer\@VIEditorPlayer\@Editor\@\@\@Bedrock\@\@XZ
     */
    virtual class Bedrock::NonOwnerPointer<class Editor::IEditorPlayer> getEditorPlayer() const = 0;
    /**
     * @vftbl 441
     * @symbol ?destroyEditorPlayer\@ServerPlayer\@\@UEAAXXZ
     */
    virtual void destroyEditorPlayer() = 0;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_PLAYER
    /**
     * @symbol ?addSavedChunk\@Player\@\@UEAAXAEBVChunkPos\@\@\@Z
     */
    MCVAPI void addSavedChunk(class ChunkPos const &);
    /**
     * @symbol ?canInteractWithOtherEntitiesInGame\@Player\@\@UEBA_NXZ
     */
    MCVAPI bool canInteractWithOtherEntitiesInGame() const;
    /**
     * @symbol ?displayChatMessage\@Player\@\@UEAAXAEBV?$basic_string\@DU?$char_traits\@D\@std\@\@V?$allocator\@D\@2\@\@std\@\@0\@Z
     */
    MCVAPI void displayChatMessage(std::string const &, std::string const &);
    /**
     * @symbol ?displayClientMessage\@Player\@\@UEAAXAEBV?$basic_string\@DU?$char_traits\@D\@std\@\@V?$allocator\@D\@2\@\@std\@\@\@Z
     */
    MCVAPI void displayClientMessage(std::string const &);
    /**
     * @symbol ?getAlwaysShowNameTag\@Player\@\@UEBA_NXZ
     */
    MCVAPI bool getAlwaysShowNameTag() const;
    /**
     * @symbol ?getCurrentStructureFeature\@Player\@\@UEBA?AW4StructureFeatureType\@\@XZ
     */
    MCVAPI enum class StructureFeatureType getCurrentStructureFeature() const;
    /**
     * @symbol ?getUserId\@Player\@\@UEBAIXZ
     */
    MCVAPI unsigned int getUserId() const;
    /**
     * @symbol ?isAutoJumpEnabled\@Player\@\@UEBA_NXZ
     */
    MCVAPI bool isAutoJumpEnabled() const;
    /**
     * @symbol ?isCreativeModeAllowed\@Player\@\@UEAA_NXZ
     */
    MCVAPI bool isCreativeModeAllowed();
    /**
     * @symbol ?isInTrialMode\@Player\@\@UEAA_NXZ
     */
    MCVAPI bool isInTrialMode();
    /**
     * @symbol ?isPlayer\@Player\@\@UEBA_NXZ
     */
    MCVAPI bool isPlayer() const;
    /**
     * @symbol ?isShootable\@Player\@\@UEAA_NXZ
     */
    MCVAPI bool isShootable();
    /**
     * @symbol ?isSimulated\@Player\@\@UEBA_NXZ
     */
    MCVAPI bool isSimulated() const;
    /**
     * @symbol ?openBook\@Player\@\@UEAAXH_NHPEAVBlockActor\@\@\@Z
     */
    MCVAPI void openBook(int, bool, int, class BlockActor *);
    /**
     * @symbol ?openChalkboard\@Player\@\@UEAAXAEAVChalkboardBlockActor\@\@_N\@Z
     */
    MCVAPI void openChalkboard(class ChalkboardBlockActor &, bool);
    /**
     * @symbol ?openPortfolio\@Player\@\@UEAAXXZ
     */
    MCVAPI void openPortfolio();
    /**
     * @symbol ?openSign\@Player\@\@UEAAXAEBVBlockPos\@\@\@Z
     */
    MCVAPI void openSign(class BlockPos const &);
    /**
     * @symbol ?playEmote\@Player\@\@UEAAXAEBV?$basic_string\@DU?$char_traits\@D\@std\@\@V?$allocator\@D\@2\@\@std\@\@_N\@Z
     */
    MCVAPI void playEmote(std::string const &, bool);
    /**
     * @symbol ?resetRot\@Player\@\@UEAAXXZ
     */
    MCVAPI void resetRot();
    /**
     * @symbol ?stopLoading\@Player\@\@UEAAXXZ
     */
    MCVAPI void stopLoading();
    /**
     * @symbol __unk_destructor_-1
     */
    MCVAPI ~Player();
#endif
    /**
     * @symbol ??0Player\@\@QEAA\@AEAVLevel\@\@AEAVPacketSender\@\@W4GameType\@\@AEBVNetworkIdentifier\@\@W4SubClientId\@\@VUUID\@mce\@\@AEBV?$basic_string\@DU?$char_traits\@D\@std\@\@V?$allocator\@D\@2\@\@std\@\@6V?$unique_ptr\@VCertificate\@\@U?$default_delete\@VCertificate\@\@\@std\@\@\@9\@AEAVEntityContext\@\@66\@Z
     */
    MCAPI Player(class Level &, class PacketSender &, enum class GameType, class NetworkIdentifier const &, enum class SubClientId, class mce::UUID, std::string const &, std::string const &, std::unique_ptr<class Certificate>, class EntityContext &, std::string const &, std::string const &);
    /**
     * @symbol ?applyExhaustion\@Player\@\@QEAAXAEBVVec3\@\@\@Z
     */
    MCAPI void applyExhaustion(class Vec3 const &);
    /**
     * @symbol ?broadcastPlayerSpawnedMobEvent\@Player\@\@QEAAXW4ActorType\@\@W4MobSpawnMethod\@\@\@Z
     */
    MCAPI void broadcastPlayerSpawnedMobEvent(enum class ActorType, enum class MobSpawnMethod);
    /**
     * @symbol ?canBeSeenOnMap\@Player\@\@QEBA_NXZ
     */
    MCAPI bool canBeSeenOnMap() const;
    /**
     * @symbol ?canDestroy\@Player\@\@QEBA_NAEBVBlock\@\@\@Z
     */
    MCAPI bool canDestroy(class Block const &) const;
    /**
     * @symbol ?canSleep\@Player\@\@QEBA_NXZ
     */
    MCAPI bool canSleep() const;
    /**
     * @symbol ?canStackInOffhand\@Player\@\@QEBA_NAEBVItemStack\@\@\@Z
     */
    MCAPI bool canStackInOffhand(class ItemStack const &) const;
    /**
     * @symbol ?canUseAbility\@Player\@\@QEBA_NW4AbilitiesIndex\@\@\@Z
     */
    MCAPI bool canUseAbility(enum class AbilitiesIndex) const;
    /**
     * @symbol ?canUseOperatorBlocks\@Player\@\@QEBA_NXZ
     */
    MCAPI bool canUseOperatorBlocks() const;
    /**
     * @symbol ?causeFoodExhaustion\@Player\@\@QEAAXM\@Z
     */
    MCAPI void causeFoodExhaustion(float);
    /**
     * @symbol ?clearRespawnPosition\@Player\@\@QEAAXXZ
     */
    MCAPI void clearRespawnPosition();
    /**
     * @symbol ?eat\@Player\@\@QEAAXHM\@Z
     */
    MCAPI void eat(int, float);
    /**
     * @symbol ?eat\@Player\@\@QEAAXAEBVItemStack\@\@\@Z
     */
    MCAPI void eat(class ItemStack const &);
    /**
     * @symbol ?equippedArmorItemCanBeMoved\@Player\@\@QEBA_NAEBVItemStack\@\@\@Z
     */
    MCAPI bool equippedArmorItemCanBeMoved(class ItemStack const &) const;
    /**
     * @symbol ?fireDimensionChangedEvent\@Player\@\@QEAAXV?$AutomaticID\@VDimension\@\@H\@\@0\@Z
     */
    MCAPI void fireDimensionChangedEvent(class AutomaticID<class Dimension, int>, class AutomaticID<class Dimension, int>);
    /**
     * @symbol ?forceAllowEating\@Player\@\@QEBA_NXZ
     */
    MCAPI bool forceAllowEating() const;
    /**
     * @symbol ?getAbilities\@Player\@\@QEBAAEBVLayeredAbilities\@\@XZ
     */
    MCAPI class LayeredAbilities const & getAbilities() const;
    /**
     * @symbol ?getAbilities\@Player\@\@QEAAAEAVLayeredAbilities\@\@XZ
     */
    MCAPI class LayeredAbilities & getAbilities();
    /**
     * @symbol ?getAgent\@Player\@\@QEBAPEAVAgent\@\@XZ
     */
    MCAPI class Agent * getAgent() const;
    /**
     * @symbol ?getAgentID\@Player\@\@QEBA?AUActorUniqueID\@\@XZ
     */
    MCAPI struct ActorUniqueID getAgentID() const;
    /**
     * @symbol ?getAgentIfAllowed\@Player\@\@QEBAPEAVAgent\@\@_NUActorUniqueID\@\@\@Z
     */
    MCAPI class Agent * getAgentIfAllowed(bool, struct ActorUniqueID) const;
    /**
     * @symbol ?getBedPosition\@Player\@\@QEBAAEBVBlockPos\@\@XZ
     */
    MCAPI class BlockPos const & getBedPosition() const;
    /**
     * @symbol ?getBlockedUsingDamagedShieldTimeStamp\@Player\@\@QEBA_JXZ
     */
    MCAPI __int64 getBlockedUsingDamagedShieldTimeStamp() const;
    /**
     * @symbol ?getBlockedUsingShieldTimeStamp\@Player\@\@QEBA_JXZ
     */
    MCAPI __int64 getBlockedUsingShieldTimeStamp() const;
    /**
     * @symbol ?getBlockingStartTimeStamp\@Player\@\@QEBA_JXZ
     */
    MCAPI __int64 getBlockingStartTimeStamp() const;
    /**
     * @symbol ?getCapePos\@Player\@\@QEAA?AVVec3\@\@M\@Z
     */
    MCAPI class Vec3 getCapePos(float);
    /**
     * @symbol ?getChunkRadius\@Player\@\@QEBAIXZ
     */
    MCAPI unsigned int getChunkRadius() const;
    /**
     * @symbol ?getContainerManager\@Player\@\@QEAA?AV?$weak_ptr\@VIContainerManager\@\@\@std\@\@XZ
     */
    MCAPI class std::weak_ptr<class IContainerManager> getContainerManager();
    /**
     * @symbol ?getCurrentActiveShield\@Player\@\@QEBAAEBVItemStack\@\@XZ
     */
    MCAPI class ItemStack const & getCurrentActiveShield() const;
    /**
     * @symbol ?getDestroyProgress\@Player\@\@QEBAMAEBVBlock\@\@\@Z
     */
    MCAPI float getDestroyProgress(class Block const &) const;
    /**
     * @symbol ?getDestroySpeed\@Player\@\@QEBAMAEBVBlock\@\@\@Z
     */
    MCAPI float getDestroySpeed(class Block const &) const;
    /**
     * @symbol ?getDirection\@Player\@\@QEBAHXZ
     */
    MCAPI int getDirection() const;
    /**
     * @symbol ?getEnchantmentSeed\@Player\@\@QEBAHXZ
     */
    MCAPI int getEnchantmentSeed() const;
    /**
     * @symbol ?getExpectedSpawnDimensionId\@Player\@\@QEBA?AV?$AutomaticID\@VDimension\@\@H\@\@XZ
     */
    MCAPI class AutomaticID<class Dimension, int> getExpectedSpawnDimensionId() const;
    /**
     * @symbol ?getExpectedSpawnPosition\@Player\@\@QEBAAEBVBlockPos\@\@XZ
     */
    MCAPI class BlockPos const & getExpectedSpawnPosition() const;
    /**
     * @symbol ?getInteractText\@Player\@\@QEBA?AV?$basic_string\@DU?$char_traits\@D\@std\@\@V?$allocator\@D\@2\@\@std\@\@XZ
     */
    MCAPI std::string getInteractText() const;
    /**
     * @symbol ?getInventory\@Player\@\@QEAAAEAVContainer\@\@XZ
     */
    MCAPI class Container & getInventory();
    /**
     * @symbol ?getItemInUse\@Player\@\@QEBAAEBVItemStack\@\@XZ
     */
    MCAPI class ItemStack const & getItemInUse() const;
    /**
     * @symbol ?getItemInteractText\@Player\@\@QEBA?AV?$basic_string\@DU?$char_traits\@D\@std\@\@V?$allocator\@D\@2\@\@std\@\@AEBVItem\@\@\@Z
     */
    MCAPI std::string getItemInteractText(class Item const &) const;
    /**
     * @symbol ?getItemStackNetManager\@Player\@\@QEBAPEBVItemStackNetManagerBase\@\@XZ
     */
    MCAPI class ItemStackNetManagerBase const * getItemStackNetManager() const;
    /**
     * @symbol ?getItemStackNetManager\@Player\@\@QEAAPEAVItemStackNetManagerBase\@\@XZ
     */
    MCAPI class ItemStackNetManagerBase * getItemStackNetManager();
    /**
     * @symbol ?getLuck\@Player\@\@QEAAMXZ
     */
    MCAPI float getLuck();
    /**
     * @symbol ?getMapIndex\@Player\@\@QEAAHXZ
     */
    MCAPI int getMapIndex();
    /**
     * @symbol ?getMoveInputHandler\@Player\@\@QEBAPEAVMoveInputHandler\@\@XZ
     */
    MCAPI class MoveInputHandler * getMoveInputHandler() const;
    /**
     * @symbol ?getName\@Player\@\@QEBAAEBV?$basic_string\@DU?$char_traits\@D\@std\@\@V?$allocator\@D\@2\@\@std\@\@XZ
     */
    MCAPI std::string const & getName() const;
    /**
     * @symbol ?getNewEnchantmentSeed\@Player\@\@QEAAXXZ
     */
    MCAPI void getNewEnchantmentSeed();
    /**
     * @symbol ?getPickupArea\@Player\@\@QEBA?AVAABB\@\@XZ
     */
    MCAPI class AABB getPickupArea() const;
    /**
     * @symbol ?getPlatform\@Player\@\@QEBA?AW4BuildPlatform\@\@XZ
     */
    MCAPI enum class BuildPlatform getPlatform() const;
    /**
     * @symbol ?getPlatformOnlineId\@Player\@\@QEBAAEBV?$basic_string\@DU?$char_traits\@D\@std\@\@V?$allocator\@D\@2\@\@std\@\@XZ
     */
    MCAPI std::string const & getPlatformOnlineId() const;
    /**
     * @symbol ?getPlayerGameType\@Player\@\@QEBA?AW4GameType\@\@XZ
     */
    MCAPI enum class GameType getPlayerGameType() const;
    /**
     * @symbol ?getPlayerIndex\@Player\@\@QEBAHXZ
     */
    MCAPI int getPlayerIndex() const;
    /**
     * @symbol ?getPlayerLevel\@Player\@\@QEBAHXZ
     */
    MCAPI int getPlayerLevel() const;
    /**
     * @symbol ?getPlayerPermissionLevel\@Player\@\@QEBA?AW4PlayerPermissionLevel\@\@XZ
     */
    MCAPI enum class PlayerPermissionLevel getPlayerPermissionLevel() const;
    /**
     * @symbol ?getPlayerSessionId\@Player\@\@QEBAAEBV?$basic_string\@DU?$char_traits\@D\@std\@\@V?$allocator\@D\@2\@\@std\@\@XZ
     */
    MCAPI std::string const & getPlayerSessionId() const;
    /**
     * @symbol ?getPlayerUIItem\@Player\@\@QEAAAEBVItemStack\@\@W4PlayerUISlot\@\@\@Z
     */
    MCAPI class ItemStack const & getPlayerUIItem(enum class PlayerUISlot);
    /**
     * @symbol ?getRespawnAnchorPosition\@Player\@\@QEBAAEBVBlockPos\@\@XZ
     */
    MCAPI class BlockPos const & getRespawnAnchorPosition() const;
    /**
     * @symbol ?getSelectedItem\@Player\@\@QEBAAEBVItemStack\@\@XZ
     */
    MCAPI class ItemStack const & getSelectedItem() const;
    /**
     * @symbol ?getSelectedItemSlot\@Player\@\@QEBAHXZ
     */
    MCAPI int getSelectedItemSlot() const;
    /**
     * @symbol ?getSkin\@Player\@\@QEBAAEBVSerializedSkin\@\@XZ
     */
    MCAPI class SerializedSkin const & getSkin() const;
    /**
     * @symbol ?getSkin\@Player\@\@QEAAAEAVSerializedSkin\@\@XZ
     */
    MCAPI class SerializedSkin & getSkin();
    /**
     * @symbol ?getSleepRotation\@Player\@\@QEBAMXZ
     */
    MCAPI float getSleepRotation() const;
    /**
     * @symbol ?getSpawnDimension\@Player\@\@QEBA?AV?$AutomaticID\@VDimension\@\@H\@\@XZ
     */
    MCAPI class AutomaticID<class Dimension, int> getSpawnDimension() const;
    /**
     * @symbol ?getSpawnPosition\@Player\@\@QEBAAEBVBlockPos\@\@XZ
     */
    MCAPI class BlockPos const & getSpawnPosition() const;
    /**
     * @symbol ?getSupplies\@Player\@\@QEBAAEBVPlayerInventory\@\@XZ
     */
    MCAPI class PlayerInventory const & getSupplies() const;
    /**
     * @symbol ?getSupplies\@Player\@\@QEAAAEAVPlayerInventory\@\@XZ
     */
    MCAPI class PlayerInventory & getSupplies();
    /**
     * @symbol ?getTrackedBosses\@Player\@\@QEAAAEBV?$vector\@UActorUniqueID\@\@V?$allocator\@UActorUniqueID\@\@\@std\@\@\@std\@\@XZ
     */
    MCAPI std::vector<struct ActorUniqueID> const & getTrackedBosses();
    /**
     * @symbol ?getUnmappedPlayerGameType\@Player\@\@QEBA?AW4GameType\@\@XZ
     */
    MCAPI enum class GameType getUnmappedPlayerGameType() const;
    /**
     * @symbol ?getUsedPotion\@Player\@\@QEAA_NXZ
     */
    MCAPI bool getUsedPotion();
    /**
     * @symbol ?getXpEarnedAtCurrentLevel\@Player\@\@QEBAHXZ
     */
    MCAPI int getXpEarnedAtCurrentLevel() const;
    /**
     * @symbol ?getXpNeededForLevelRange\@Player\@\@QEBAIHH\@Z
     */
    MCAPI unsigned int getXpNeededForLevelRange(int, int) const;
    /**
     * @symbol ?getXpNeededForNextLevel\@Player\@\@QEBAHXZ
     */
    MCAPI int getXpNeededForNextLevel() const;
    /**
     * @symbol ?hasBedPosition\@Player\@\@QEBA_NXZ
     */
    MCAPI bool hasBedPosition() const;
    /**
     * @symbol ?hasOpenContainer\@Player\@\@QEBA_NXZ
     */
    MCAPI bool hasOpenContainer() const;
    /**
     * @symbol ?hasOpenContainerOfContainerType\@Player\@\@QEBA_NW4ContainerType\@\@\@Z
     */
    MCAPI bool hasOpenContainerOfContainerType(enum class ContainerType) const;
    /**
     * @symbol ?hasOwnedChunkSource\@Player\@\@QEBA_NXZ
     */
    MCAPI bool hasOwnedChunkSource() const;
    /**
     * @symbol ?hasResource\@Player\@\@QEAA_NAEBVItemDescriptor\@\@\@Z
     */
    MCAPI bool hasResource(class ItemDescriptor const &);
    /**
     * @symbol ?hasRespawnAnchorPosition\@Player\@\@QEBA_NXZ
     */
    MCAPI bool hasRespawnAnchorPosition() const;
    /**
     * @symbol ?hasRespawnPosition\@Player\@\@QEBA_NXZ
     */
    MCAPI bool hasRespawnPosition() const;
    /**
     * @symbol ?interact\@Player\@\@QEAA_NAEAVActor\@\@AEBVVec3\@\@\@Z
     */
    MCAPI bool interact(class Actor &, class Vec3 const &);
    /**
     * @symbol ?is2DPositionRelevant\@Player\@\@QEAA_NV?$AutomaticID\@VDimension\@\@H\@\@AEBVBlockPos\@\@\@Z
     */
    MCAPI bool is2DPositionRelevant(class AutomaticID<class Dimension, int>, class BlockPos const &);
    /**
     * @symbol ?isFlying\@Player\@\@QEBA_NXZ
     */
    MCAPI bool isFlying() const;
    /**
     * @symbol ?isForcedRespawn\@Player\@\@QEBA_NXZ
     */
    MCAPI bool isForcedRespawn() const;
    /**
     * @symbol ?isHiddenFrom\@Player\@\@QEBA_NAEAVMob\@\@\@Z
     */
    MCAPI bool isHiddenFrom(class Mob &) const;
    /**
     * @symbol ?isHungry\@Player\@\@QEBA_NXZ
     */
    MCAPI bool isHungry() const;
    /**
     * @symbol ?isHurt\@Player\@\@QEAA_NXZ
     */
    MCAPI bool isHurt();
    /**
     * @symbol ?isInCreativeMode\@Player\@\@QEBA_NXZ
     */
    MCAPI bool isInCreativeMode() const;
    /**
     * @symbol ?isInRaid\@Player\@\@QEBA_NXZ
     */
    MCAPI bool isInRaid() const;
    /**
     * @symbol ?isRespawningFromTheEnd\@Player\@\@QEBA_NXZ
     */
    MCAPI bool isRespawningFromTheEnd() const;
    /**
     * @symbol ?isSleepingLongEnough\@Player\@\@QEBA_NXZ
     */
    MCAPI bool isSleepingLongEnough() const;
    /**
     * @symbol ?isSpawned\@Player\@\@QEBA_NXZ
     */
    MCAPI bool isSpawned() const;
    /**
     * @symbol ?isUsingItem\@Player\@\@QEBA_NXZ
     */
    MCAPI bool isUsingItem() const;
    /**
     * @symbol ?isValidSpawn\@Player\@\@QEBA_NXZ
     */
    MCAPI bool isValidSpawn() const;
    /**
     * @symbol ?loadLastDeathLocation\@Player\@\@QEAAXAEBVCompoundTag\@\@\@Z
     */
    MCAPI void loadLastDeathLocation(class CompoundTag const &);
    /**
     * @symbol ?passengerCheckMovementStats\@Player\@\@QEAAXXZ
     */
    MCAPI void passengerCheckMovementStats();
    /**
     * @symbol ?recheckSpawnPosition\@Player\@\@QEAAXXZ
     */
    MCAPI void recheckSpawnPosition();
    /**
     * @symbol ?releaseUsingItem\@Player\@\@QEAAXXZ
     */
    MCAPI void releaseUsingItem();
    /**
     * @symbol ?resetPlayerLevel\@Player\@\@QEAAXXZ
     */
    MCAPI void resetPlayerLevel();
    /**
     * @symbol ?resetPublisherInitialSpawn\@Player\@\@QEAAXXZ
     */
    MCAPI void resetPublisherInitialSpawn();
    /**
     * @symbol ?resetToDefaultGameMode\@Player\@\@QEAAXXZ
     */
    MCAPI void resetToDefaultGameMode();
    /**
     * @symbol ?saveLastDeathLocation\@Player\@\@QEBAXAEAVCompoundTag\@\@\@Z
     */
    MCAPI void saveLastDeathLocation(class CompoundTag &) const;
    /**
     * @symbol ?sendPlayerTeleported\@Player\@\@QEAAXXZ
     */
    MCAPI void sendPlayerTeleported();
    /**
     * @symbol ?sendSpawnExperienceOrbPacketToServer\@Player\@\@QEAAXAEBVVec3\@\@H\@Z
     */
    MCAPI void sendSpawnExperienceOrbPacketToServer(class Vec3 const &, int);
    /**
     * @symbol ?setAgent\@Player\@\@QEAAXPEAVAgent\@\@\@Z
     */
    MCAPI void setAgent(class Agent *);
    /**
     * @symbol ?setBedRespawnPosition\@Player\@\@QEAAXAEBVBlockPos\@\@\@Z
     */
    MCAPI void setBedRespawnPosition(class BlockPos const &);
    /**
     * @symbol ?setBlockRespawnUntilClientMessage\@Player\@\@QEAAX_N\@Z
     */
    MCAPI void setBlockRespawnUntilClientMessage(bool);
    /**
     * @symbol ?setChunkRadius\@Player\@\@QEAAXI\@Z
     */
    MCAPI void setChunkRadius(unsigned int);
    /**
     * @symbol ?setContainerManager\@Player\@\@QEAAXV?$shared_ptr\@VIContainerManager\@\@\@std\@\@\@Z
     */
    MCAPI void setContainerManager(class std::shared_ptr<class IContainerManager>);
    /**
     * @symbol ?setCursorSelectedItem\@Player\@\@QEAAXAEBVItemStack\@\@\@Z
     */
    MCAPI void setCursorSelectedItem(class ItemStack const &);
    /**
     * @symbol ?setCursorSelectedItemGroup\@Player\@\@QEAAXAEBVItemGroup\@\@\@Z
     */
    MCAPI void setCursorSelectedItemGroup(class ItemGroup const &);
    /**
     * @symbol ?setEnchantmentSeed\@Player\@\@QEAAXH\@Z
     */
    MCAPI void setEnchantmentSeed(int);
    /**
     * @symbol ?setHasDied\@Player\@\@QEAAX_N\@Z
     */
    MCAPI void setHasDied(bool);
    /**
     * @symbol ?setHasSeenCredits\@Player\@\@QEAAX_N\@Z
     */
    MCAPI void setHasSeenCredits(bool);
    /**
     * @symbol ?setLastHurtBy\@Player\@\@QEAAXW4ActorType\@\@\@Z
     */
    MCAPI void setLastHurtBy(enum class ActorType);
    /**
     * @symbol ?setMapIndex\@Player\@\@QEAAXH\@Z
     */
    MCAPI void setMapIndex(int);
    /**
     * @symbol ?setPermissions\@Player\@\@QEAAXW4CommandPermissionLevel\@\@\@Z
     */
    MCAPI void setPermissions(enum class CommandPermissionLevel);
    /**
     * @symbol ?setPlatformOnlineId\@Player\@\@QEAAXAEBV?$basic_string\@DU?$char_traits\@D\@std\@\@V?$allocator\@D\@2\@\@std\@\@\@Z
     */
    MCAPI void setPlatformOnlineId(std::string const &);
    /**
     * @symbol ?setPlayerIndex\@Player\@\@QEAAXH\@Z
     */
    MCAPI void setPlayerIndex(int);
    /**
     * @symbol ?setPlayerUIItem\@Player\@\@QEAAXW4PlayerUISlot\@\@AEBVItemStack\@\@\@Z
     */
    MCAPI void setPlayerUIItem(enum class PlayerUISlot, class ItemStack const &);
    /**
     * @symbol ?setRespawnPosition\@Player\@\@QEAAXAEBVBlockPos\@\@V?$AutomaticID\@VDimension\@\@H\@\@\@Z
     */
    MCAPI void setRespawnPosition(class BlockPos const &, class AutomaticID<class Dimension, int>);
    /**
     * @symbol ?setRespawnPositionCandidate\@Player\@\@QEAAXXZ
     */
    MCAPI void setRespawnPositionCandidate();
    /**
     * @symbol ?setRespawnReady\@Player\@\@QEAAXAEBVVec3\@\@\@Z
     */
    MCAPI void setRespawnReady(class Vec3 const &);
    /**
     * @symbol ?setSelectedItem\@Player\@\@QEAAXAEBVItemStack\@\@\@Z
     */
    MCAPI void setSelectedItem(class ItemStack const &);
    /**
     * @symbol ?setSelectedSlot\@Player\@\@QEAAAEBVItemStack\@\@H\@Z
     */
    MCAPI class ItemStack const & setSelectedSlot(int);
    /**
     * @symbol ?setSpawnBlockRespawnPosition\@Player\@\@QEAAXAEBVBlockPos\@\@V?$AutomaticID\@VDimension\@\@H\@\@\@Z
     */
    MCAPI void setSpawnBlockRespawnPosition(class BlockPos const &, class AutomaticID<class Dimension, int>);
    /**
     * @symbol ?setUsedPotion\@Player\@\@QEAAX_N\@Z
     */
    MCAPI void setUsedPotion(bool);
    /**
     * @symbol ?shouldShowCredits\@Player\@\@QEBA_NXZ
     */
    MCAPI bool shouldShowCredits() const;
    /**
     * @symbol ?startCooldown\@Player\@\@QEAAXAEBVHashedString\@\@H_N\@Z
     */
    MCAPI void startCooldown(class HashedString const &, int, bool);
    /**
     * @symbol ?startGliding\@Player\@\@QEAAXXZ
     */
    MCAPI void startGliding();
    /**
     * @symbol ?startUsingItem\@Player\@\@QEAAXAEBVItemStack\@\@H\@Z
     */
    MCAPI void startUsingItem(class ItemStack const &, int);
    /**
     * @symbol ?stopGliding\@Player\@\@QEAAXXZ
     */
    MCAPI void stopGliding();
    /**
     * @symbol ?stopUsingItem\@Player\@\@QEAAXXZ
     */
    MCAPI void stopUsingItem();
    /**
     * @symbol ?take\@Player\@\@QEAA_NAEAVActor\@\@HH\@Z
     */
    MCAPI bool take(class Actor &, int, int);
    /**
     * @symbol ?updateBlockSourceTick\@Player\@\@QEAAXXZ
     */
    MCAPI void updateBlockSourceTick();
    /**
     * @symbol ?updateInventoryTransactions\@Player\@\@QEAAXXZ
     */
    MCAPI void updateInventoryTransactions();
    /**
     * @symbol ?updateSkin\@Player\@\@QEAAXAEBVSerializedSkin\@\@H\@Z
     */
    MCAPI void updateSkin(class SerializedSkin const &, int);
    /**
     * @symbol ?updateSpawnChunkView\@Player\@\@QEAAXXZ
     */
    MCAPI void updateSpawnChunkView();
    /**
     * @symbol ?updateTrackedBosses\@Player\@\@QEAAXXZ
     */
    MCAPI void updateTrackedBosses();
    /**
     * @symbol ?useSelectedItem\@Player\@\@QEAAXW4ItemUseMethod\@\@_N\@Z
     */
    MCAPI void useSelectedItem(enum class ItemUseMethod, bool);
    /**
     * @symbol ?DEFAULT_BB_HEIGHT\@Player\@\@2MB
     */
    MCAPI static float const DEFAULT_BB_HEIGHT;
    /**
     * @symbol ?DEFAULT_BB_WIDTH\@Player\@\@2MB
     */
    MCAPI static float const DEFAULT_BB_WIDTH;
    /**
     * @symbol ?DEFAULT_PLAYER_HEIGHT_OFFSET\@Player\@\@2MB
     */
    MCAPI static float const DEFAULT_PLAYER_HEIGHT_OFFSET;
    /**
     * @symbol ?DEFAULT_WALK_SPEED\@Player\@\@2MB
     */
    MCAPI static float const DEFAULT_WALK_SPEED;
    /**
     * @symbol ?DISTANCE_TO_TRANSFORM_EVENT\@Player\@\@2MB
     */
    MCAPI static float const DISTANCE_TO_TRANSFORM_EVENT;
    /**
     * @symbol ?DISTANCE_TO_TRAVELLED_EVENT\@Player\@\@2MB
     */
    MCAPI static float const DISTANCE_TO_TRAVELLED_EVENT;
    /**
     * @symbol ?EXHAUSTION\@Player\@\@2VAttribute\@\@B
     */
    MCAPI static class Attribute const EXHAUSTION;
    /**
     * @symbol ?EXPERIENCE\@Player\@\@2VAttribute\@\@B
     */
    MCAPI static class Attribute const EXPERIENCE;
    /**
     * @symbol ?GLIDE_STOP_DELAY\@Player\@\@2HB
     */
    MCAPI static int const GLIDE_STOP_DELAY;
    /**
     * @symbol ?HUNGER\@Player\@\@2VAttribute\@\@B
     */
    MCAPI static class Attribute const HUNGER;
    /**
     * @symbol ?ITEM_USE_INTERVAL_COUNT\@Player\@\@2HB
     */
    MCAPI static int const ITEM_USE_INTERVAL_COUNT;
    /**
     * @symbol ?ITEM_USE_INTERVAL_DURATION\@Player\@\@2HB
     */
    MCAPI static int const ITEM_USE_INTERVAL_DURATION;
    /**
     * @symbol ?LEVEL\@Player\@\@2VAttribute\@\@B
     */
    MCAPI static class Attribute const LEVEL;
    /**
     * @symbol ?MAX_ITEM_USE_DURATION\@Player\@\@2HB
     */
    MCAPI static int const MAX_ITEM_USE_DURATION;
    /**
     * @symbol ?PLAYER_ALIVE_HEIGHT\@Player\@\@2MB
     */
    MCAPI static float const PLAYER_ALIVE_HEIGHT;
    /**
     * @symbol ?PLAYER_ALIVE_WIDTH\@Player\@\@2MB
     */
    MCAPI static float const PLAYER_ALIVE_WIDTH;
    /**
     * @symbol ?PLAYER_DEAD_HEIGHT\@Player\@\@2MB
     */
    MCAPI static float const PLAYER_DEAD_HEIGHT;
    /**
     * @symbol ?PLAYER_DEAD_WIDTH\@Player\@\@2MB
     */
    MCAPI static float const PLAYER_DEAD_WIDTH;
    /**
     * @symbol ?PLAYER_DIMENSION_CHANGE_OWNED_MOB_SEARCH_RADIUS\@Player\@\@2HB
     */
    MCAPI static int const PLAYER_DIMENSION_CHANGE_OWNED_MOB_SEARCH_RADIUS;
    /**
     * @symbol ?PLAYER_DOWN_SWIM_SPEED\@Player\@\@2MB
     */
    MCAPI static float const PLAYER_DOWN_SWIM_SPEED;
    /**
     * @symbol ?PLAYER_GLIDING_CAMERA_OFFSET\@Player\@\@2MB
     */
    MCAPI static float const PLAYER_GLIDING_CAMERA_OFFSET;
    /**
     * @symbol ?PLAYER_SLEEPING_CAMERA_OFFSET\@Player\@\@2MB
     */
    MCAPI static float const PLAYER_SLEEPING_CAMERA_OFFSET;
    /**
     * @symbol ?PLAYER_SLEEPING_HEIGHT\@Player\@\@2MB
     */
    MCAPI static float const PLAYER_SLEEPING_HEIGHT;
    /**
     * @symbol ?PLAYER_SLEEPING_WIDTH\@Player\@\@2MB
     */
    MCAPI static float const PLAYER_SLEEPING_WIDTH;
    /**
     * @symbol ?PLAYER_SWIMMING_CAMERA_OFFSET\@Player\@\@2MB
     */
    MCAPI static float const PLAYER_SWIMMING_CAMERA_OFFSET;
    /**
     * @symbol ?PLAYER_SWIM_BREACH_ANGLE\@Player\@\@2MB
     */
    MCAPI static float const PLAYER_SWIM_BREACH_ANGLE;
    /**
     * @symbol ?PLAYER_SWIM_ENTER_THRESHOLD\@Player\@\@2MB
     */
    MCAPI static float const PLAYER_SWIM_ENTER_THRESHOLD;
    /**
     * @symbol ?PLAYER_SWIM_FLY_MULTI\@Player\@\@2MB
     */
    MCAPI static float const PLAYER_SWIM_FLY_MULTI;
    /**
     * @symbol ?PLAYER_UP_SWIM_SPEED\@Player\@\@2MB
     */
    MCAPI static float const PLAYER_UP_SWIM_SPEED;
    /**
     * @symbol ?SATURATION\@Player\@\@2VAttribute\@\@B
     */
    MCAPI static class Attribute const SATURATION;
    /**
     * @symbol ?SPAWN_CHUNK_LARGE_JUMP\@Player\@\@2IB
     */
    MCAPI static unsigned int const SPAWN_CHUNK_LARGE_JUMP;
    /**
     * @symbol ?SPAWN_CHUNK_RADIUS\@Player\@\@2IB
     */
    MCAPI static unsigned int const SPAWN_CHUNK_RADIUS;
    /**
     * @symbol ?_aiStep\@Player\@\@SAXAEAUIPlayerMovementProxy\@\@\@Z
     */
    MCAPI static void _aiStep(struct IPlayerMovementProxy &);
    /**
     * @symbol ?_travel\@Player\@\@SAXAEAUIPlayerMovementProxy\@\@MMM_N\@Z
     */
    MCAPI static void _travel(struct IPlayerMovementProxy &, float, float, float, bool);
    /**
     * @symbol ?canJump\@Player\@\@SA_NAEAUIPlayerMovementProxy\@\@\@Z
     */
    MCAPI static bool canJump(struct IPlayerMovementProxy &);
    /**
     * @symbol ?checkAndFixSpawnPosition\@Player\@\@SA_NAEAVVec3\@\@V?$vector\@V?$not_null\@PEAVBlockSource\@\@\@gsl\@\@V?$allocator\@V?$not_null\@PEAVBlockSource\@\@\@gsl\@\@\@std\@\@\@std\@\@VAABB\@\@_N33333F\@Z
     */
    MCAPI static bool checkAndFixSpawnPosition(class Vec3 &, std::vector<class gsl::not_null<class BlockSource *>>, class AABB, bool, bool, bool, bool, bool, bool, short);
    /**
     * @symbol ?checkNeedAutoJump\@Player\@\@SA_NPEAUIPlayerMovementProxy\@\@MM\@Z
     */
    MCAPI static bool checkNeedAutoJump(struct IPlayerMovementProxy *, float, float);
    /**
     * @symbol ?goDownInWater\@Player\@\@SAXAEAUIActorMovementProxy\@\@\@Z
     */
    MCAPI static void goDownInWater(struct IActorMovementProxy &);
    /**
     * @symbol ?handleJumpEffects\@Player\@\@SAXAEAUIPlayerMovementProxy\@\@\@Z
     */
    MCAPI static void handleJumpEffects(struct IPlayerMovementProxy &);
    /**
     * @symbol ?isDangerousVolume\@Player\@\@SA_NAEAVBlockSource\@\@AEBVAABB\@\@_N\@Z
     */
    MCAPI static bool isDangerousVolume(class BlockSource &, class AABB const &, bool);
    /**
     * @symbol ?tryGetFromComponent\@Player\@\@SAPEAV1\@AEBV?$FlagComponent\@UPlayerComponentFlag\@\@\@\@AEAVActorOwnerComponent\@\@_N\@Z
     */
    MCAPI static class Player * tryGetFromComponent(class FlagComponent<struct PlayerComponentFlag> const &, class ActorOwnerComponent &, bool);
    /**
     * @symbol ?tryGetFromEntity\@Player\@\@SAPEAV1\@AEAVEntityContext\@\@_N\@Z
     */
    MCAPI static class Player * tryGetFromEntity(class EntityContext &, bool);
    /**
     * @symbol ?tryGetFromEntity\@Player\@\@SAPEBV1\@AEBVEntityContext\@\@_N\@Z
     */
    MCAPI static class Player const * tryGetFromEntity(class EntityContext const &, bool);
    /**
     * @symbol ?tryGetFromEntity\@Player\@\@SAPEAV1\@V?$StackRefResultT\@UEntityRefTraits\@\@\@\@_N\@Z
     */
    MCAPI static class Player * tryGetFromEntity(class StackRefResultT<struct EntityRefTraits>, bool);

//protected:
    /**
     * @symbol ?_checkAndFixSpawnPosition\@Player\@\@IEBA_NAEAVVec3\@\@V?$vector\@V?$not_null\@PEAVBlockSource\@\@\@gsl\@\@V?$allocator\@V?$not_null\@PEAVBlockSource\@\@\@gsl\@\@\@std\@\@\@std\@\@_N2222\@Z
     */
    MCAPI bool _checkAndFixSpawnPosition(class Vec3 &, std::vector<class gsl::not_null<class BlockSource *>>, bool, bool, bool, bool, bool) const;
    /**
     * @symbol ?_chooseSpawnArea\@Player\@\@IEAAXXZ
     */
    MCAPI void _chooseSpawnArea();
    /**
     * @symbol ?_chooseSpawnPositionWithinArea\@Player\@\@IEAA_NXZ
     */
    MCAPI bool _chooseSpawnPositionWithinArea();
    /**
     * @symbol ?_registerPlayerAttributes\@Player\@\@IEAAXXZ
     */
    MCAPI void _registerPlayerAttributes();
    /**
     * @symbol ?_setPreDimensionTransferSpawnPosition\@Player\@\@IEAAXVVec3\@\@\@Z
     */
    MCAPI void _setPreDimensionTransferSpawnPosition(class Vec3);
    /**
     * @symbol ?_updateInteraction\@Player\@\@IEAAXXZ
     */
    MCAPI void _updateInteraction();
    /**
     * @symbol ?_validateSpawnPositionAvailability\@Player\@\@IEBA_NAEBVVec3\@\@PEAVBlockSource\@\@QEBV2\@\@Z
     */
    MCAPI bool _validateSpawnPositionAvailability(class Vec3 const &, class BlockSource *, class Vec3 const *const) const;
    /**
     * @symbol ?checkBed\@Player\@\@IEAA_NPEAVBlockSource\@\@QEBVVec3\@\@\@Z
     */
    MCAPI bool checkBed(class BlockSource *, class Vec3 const *const);
    /**
     * @symbol ?checkSpawnBlock\@Player\@\@IEBA_NAEBVBlockSource\@\@\@Z
     */
    MCAPI bool checkSpawnBlock(class BlockSource const &) const;
    /**
     * @symbol ?_isDangerousBlock\@Player\@\@KA_NAEBVBlock\@\@_N\@Z
     */
    MCAPI static bool _isDangerousBlock(class Block const &, bool);

//private:
    /**
     * @symbol ?_addLevels\@Player\@\@AEAAXH\@Z
     */
    MCAPI void _addLevels(int);
    /**
     * @symbol ?_blockUsingShield\@Player\@\@AEAA_NAEBVActorDamageSource\@\@M\@Z
     */
    MCAPI bool _blockUsingShield(class ActorDamageSource const &, float);
    /**
     * @symbol ?_ensureSafeSpawnPosition\@Player\@\@AEAAXAEAVVec3\@\@\@Z
     */
    MCAPI void _ensureSafeSpawnPosition(class Vec3 &);
    /**
     * @symbol ?_findFallbackSpawnPosition\@Player\@\@AEAA_NAEAVVec3\@\@V?$vector\@V?$not_null\@PEAVBlockSource\@\@\@gsl\@\@V?$allocator\@V?$not_null\@PEAVBlockSource\@\@\@gsl\@\@\@std\@\@\@std\@\@I\@Z
     */
    MCAPI bool _findFallbackSpawnPosition(class Vec3 &, std::vector<class gsl::not_null<class BlockSource *>>, unsigned int);
    /**
     * @symbol ?_handleCarriedItemInteractText\@Player\@\@AEAAXXZ
     */
    MCAPI void _handleCarriedItemInteractText();
    /**
     * @symbol ?_isChunkSourceLoaded\@Player\@\@AEBA_NAEBVVec3\@\@AEBVBlockSource\@\@\@Z
     */
    MCAPI bool _isChunkSourceLoaded(class Vec3 const &, class BlockSource const &) const;
    /**
     * @symbol ?_registerElytraLoopSound\@Player\@\@AEAAXXZ
     */
    MCAPI void _registerElytraLoopSound();
    /**
     * @symbol ?_sendShieldUpdatePacket\@Player\@\@AEAAXAEBVShieldItem\@\@AEBVItemStack\@\@1W4ContainerID\@\@H\@Z
     */
    MCAPI void _sendShieldUpdatePacket(class ShieldItem const &, class ItemStack const &, class ItemStack const &, enum class ContainerID, int);
    /**
     * @symbol ?_updateFroglightCountAndTestForAchievement\@Player\@\@AEAA_NAEBVItemStack\@\@0\@Z
     */
    MCAPI bool _updateFroglightCountAndTestForAchievement(class ItemStack const &, class ItemStack const &);

protected:

private:

};
