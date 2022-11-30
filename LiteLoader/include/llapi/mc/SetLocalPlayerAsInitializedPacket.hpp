/**
 * @file  SetLocalPlayerAsInitializedPacket.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Packet.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC class SetLocalPlayerAsInitializedPacket.
 *
 */
class SetLocalPlayerAsInitializedPacket : public Packet {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SETLOCALPLAYERASINITIALIZEDPACKET
public:
    class SetLocalPlayerAsInitializedPacket& operator=(class SetLocalPlayerAsInitializedPacket const &) = delete;
    SetLocalPlayerAsInitializedPacket(class SetLocalPlayerAsInitializedPacket const &) = delete;
#endif

public:
    /**
     * @vftbl  0
     * @hash   -1381432978
     */
    virtual ~SetLocalPlayerAsInitializedPacket();
    /**
     * @vftbl  1
     * @symbol ?getId@SetLocalPlayerAsInitializedPacket@@UEBA?AW4MinecraftPacketIds@@XZ
     * @hash   -1780544946
     */
    virtual enum class MinecraftPacketIds getId() const;
    /**
     * @vftbl  2
     * @symbol ?getName@SetLocalPlayerAsInitializedPacket@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
     * @hash   310379771
     */
    virtual std::string getName() const;
    /**
     * @vftbl  3
     * @symbol ?write@SetLocalPlayerAsInitializedPacket@@UEBAXAEAVBinaryStream@@@Z
     * @hash   -602733076
     */
    virtual void write(class BinaryStream &) const;
    /**
     * @vftbl  6
     * @symbol ?_read@SetLocalPlayerAsInitializedPacket@@EEAA?AW4StreamReadResult@@AEAVReadOnlyBinaryStream@@@Z
     * @hash   -1880030612
     */
    virtual enum class StreamReadResult _read(class ReadOnlyBinaryStream &);
    /**
     * @symbol ??0SetLocalPlayerAsInitializedPacket@@QEAA@XZ
     * @hash   -1730246276
     */
    MCAPI SetLocalPlayerAsInitializedPacket();

};