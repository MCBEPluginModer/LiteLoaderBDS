/**
 * @file  OnScreenTextureAnimationPacket.hpp
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
 * @brief MC class OnScreenTextureAnimationPacket.
 *
 */
class OnScreenTextureAnimationPacket : public Packet {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ONSCREENTEXTUREANIMATIONPACKET
public:
    class OnScreenTextureAnimationPacket& operator=(class OnScreenTextureAnimationPacket const &) = delete;
    OnScreenTextureAnimationPacket(class OnScreenTextureAnimationPacket const &) = delete;
#endif

public:
    /**
     * @vftbl  0
     * @hash   1994403942
     */
    virtual ~OnScreenTextureAnimationPacket();
    /**
     * @vftbl  1
     * @symbol ?getId@OnScreenTextureAnimationPacket@@UEBA?AW4MinecraftPacketIds@@XZ
     * @hash   1901710738
     */
    virtual enum class MinecraftPacketIds getId() const;
    /**
     * @vftbl  2
     * @symbol ?getName@OnScreenTextureAnimationPacket@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
     * @hash   1961204799
     */
    virtual std::string getName() const;
    /**
     * @vftbl  3
     * @symbol ?write@OnScreenTextureAnimationPacket@@UEBAXAEAVBinaryStream@@@Z
     * @hash   -1046802264
     */
    virtual void write(class BinaryStream &) const;
    /**
     * @vftbl  6
     * @symbol ?_read@OnScreenTextureAnimationPacket@@EEAA?AW4StreamReadResult@@AEAVReadOnlyBinaryStream@@@Z
     * @hash   -1347379544
     */
    virtual enum class StreamReadResult _read(class ReadOnlyBinaryStream &);
    /**
     * @symbol ??0OnScreenTextureAnimationPacket@@QEAA@XZ
     * @hash   910381016
     */
    MCAPI OnScreenTextureAnimationPacket();
    /**
     * @symbol ??0OnScreenTextureAnimationPacket@@QEAA@I@Z
     * @hash   329862269
     */
    MCAPI OnScreenTextureAnimationPacket(unsigned int);

};