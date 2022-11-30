/**
 * @file  BigEndianStringByteOutput.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "StringByteOutput.hpp"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

/**
 * @brief MC class BigEndianStringByteOutput.
 *
 */
class BigEndianStringByteOutput : public StringByteOutput {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_BIGENDIANSTRINGBYTEOUTPUT
public:
    class BigEndianStringByteOutput& operator=(class BigEndianStringByteOutput const &) = delete;
    BigEndianStringByteOutput(class BigEndianStringByteOutput const &) = delete;
    BigEndianStringByteOutput() = delete;
#endif

public:
    /**
     * @vftbl  0
     * @hash   1389013315
     */
    virtual ~BigEndianStringByteOutput();
    /**
     * @vftbl  3
     * @symbol ?writeFloat@BigEndianStringByteOutput@@UEAAXM@Z
     * @hash   1884461315
     */
    virtual void writeFloat(float);
    /**
     * @vftbl  4
     * @symbol ?writeDouble@BigEndianStringByteOutput@@UEAAXN@Z
     * @hash   -1812170741
     */
    virtual void writeDouble(double);
    /**
     * @vftbl  6
     * @symbol ?writeShort@BigEndianStringByteOutput@@UEAAXF@Z
     * @hash   1762944307
     */
    virtual void writeShort(short);
    /**
     * @vftbl  7
     * @symbol ?writeInt@BigEndianStringByteOutput@@UEAAXH@Z
     * @hash   1796032397
     */
    virtual void writeInt(int);
    /**
     * @vftbl  8
     * @symbol ?writeLongLong@BigEndianStringByteOutput@@UEAAX_J@Z
     * @hash   -796884176
     */
    virtual void writeLongLong(__int64);

};