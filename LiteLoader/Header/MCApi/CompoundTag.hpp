// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#include <Global.h>
//#include "Tag.hpp"
#include <NBTAPI.h>
class CompoundTag : public Tag {
public:
    virtual ~CompoundTag();
    virtual void deleteChildren();
    virtual void write(class IDataOutput&);
    virtual void load(class IDataInput&);
    virtual std::string toString();
    virtual void unk_vfn_5();
    virtual bool equals(class Tag const&);
    virtual void print(std::string const&, class PrintStream&);
    virtual std::unique_ptr<class Tag> copy();
    virtual unsigned __int64 hash();

public:
    MCAPI void append(class CompoundTag const&);
    MCAPI void clear();
    MCAPI std::unique_ptr<class CompoundTag> clone() const;
    MCAPI bool contains(class gsl::basic_string_span<char const, -1>) const;
    MCAPI bool contains(class gsl::basic_string_span<char const, -1>, int /* enum Tag::Type*/) const;
    MCAPI void deepCopy(class CompoundTag const&);
    MCAPI class Tag* get(class gsl::basic_string_span<char const, -1>);
    MCAPI class Tag const* get(class gsl::basic_string_span<char const, -1>) const;
    MCAPI bool getBoolean(class gsl::basic_string_span<char const, -1>) const;
    MCAPI unsigned char getByte(class gsl::basic_string_span<char const, -1>) const;
    MCAPI struct TagMemoryChunk const& getByteArray(class gsl::basic_string_span<char const, -1>) const;
    MCAPI class CompoundTag* getCompound(class gsl::basic_string_span<char const, -1>);
    MCAPI class CompoundTag const* getCompound(class gsl::basic_string_span<char const, -1>) const;
    MCAPI float getFloat(class gsl::basic_string_span<char const, -1>) const;
    MCAPI int getInt(class gsl::basic_string_span<char const, -1>) const;
    MCAPI __int64 getInt64(class gsl::basic_string_span<char const, -1>) const;
    MCAPI class Int64Tag const* getInt64Tag(class gsl::basic_string_span<char const, -1>) const;
    MCAPI class Int64Tag* getInt64Tag(class gsl::basic_string_span<char const, -1>);
    MCAPI class IntTag const* getIntTag(class gsl::basic_string_span<char const, -1>) const;
    MCAPI class CompoundTag& operator=(class CompoundTag&&);
    MCAPI class ListTag* getList(class gsl::basic_string_span<char const, -1>);
    MCAPI class ListTag const* getList(class gsl::basic_string_span<char const, -1>) const;
    MCAPI short getShort(class gsl::basic_string_span<char const, -1>) const;
    MCAPI std::string const& getString(class gsl::basic_string_span<char const, -1>) const;
    MCAPI bool isEmpty() const;
    MCAPI class Tag& put(std::string, class Tag&&);
    MCAPI class Tag* put(std::string, std::unique_ptr<class Tag>);
    MCAPI void putBoolean(std::string, bool);
    MCAPI unsigned char& putByte(std::string, unsigned char);
    MCAPI struct TagMemoryChunk& putByteArray(std::string, struct TagMemoryChunk);
    MCAPI class CompoundTag& putCompound(std::string, class CompoundTag);
    MCAPI class CompoundTag* putCompound(std::string, std::unique_ptr<class CompoundTag>);
    MCAPI float& putFloat(std::string, float);
    MCAPI int& putInt(std::string, int);
    MCAPI __int64& putInt64(std::string, __int64);
    MCAPI short& putShort(std::string, short);
    MCAPI std::string& putString(std::string, std::string);
    MCAPI bool remove(class gsl::basic_string_span<char const, -1>);
    MCAPI void rename(class gsl::basic_string_span<char const, -1>, std::string);
};