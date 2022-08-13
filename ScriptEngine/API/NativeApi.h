#pragma once
#include "APIHelp.h"
#include <string>
#include <dyncall/dyncall.h>
#include <dyncall/dyncall_callback.h>
#include <Tools/Demangler/include/MicrosoftDemangleNodes.h>
#include <concurrent_unordered_map.h>

extern ClassDefine<void> NativeTypeEnumBuilder;

class NativeFunction {
public:
    // TypesEnum
    enum class Types : int {
        Void,
        Bool,
        Char,
        UnsignedChar,
        Short,
        UnsignedShort,
        Int,
        UnsignedInt,
        Long,
        UnsignedLong,
        LongLong,
        UnsignedLongLong,
        Float,
        Double,
        String,
        Pointer,
    };

    template <Types T>
    static Local<Value> getType() {
        return Number::newNumber((int)T);
    }
    //Data Members
    NativeFunction::Types mReturnVal = NativeFunction::Types::Void;
    vector<NativeFunction::Types> mParams = {};
    std::string mSymbol = "unknown";
    void* mFunction = nullptr;

    //Dyncall Helper
    static char getTypeSignature(NativeFunction::Types type);
    static NativeFunction::Types getNativeType(llvm::ms_demangle::Node* type);
    std::string buildDynCallbackSig();

    //Script Helper
    Local<Value> getCallableFunction();
    static Local<Value> callNativeFunction(DCCallVM* vm, NativeFunction* funcSymbol, const Arguments& args);
    static char hookCallbackHandler(DCCallback* cb, DCArgs* args, DCValue* result, void* userdata);

    //Cache Helper
    static Concurrency::concurrent_unordered_map<std::string, NativeFunction> parsedSymbol;
    static NativeFunction getOrParse(const std::string& symbol);

    inline void cloneFrom(const NativeFunction& i) {
        this->mReturnVal = i.mReturnVal;
        this->mParams = i.mParams;
        this->mSymbol = i.mSymbol;
        this->mFunction = i.mFunction;
    }
};

class DynamicHookData : public NativeFunction, public ScriptClass {
public:
    script::ScriptEngine* mEngine = nullptr;
    DCCallback* mNativeCallack = nullptr;
    script::Global<Function> mScriptCallback;
    explicit DynamicHookData(const Local<Object>& scriptObj)
    : ScriptClass(scriptObj) {
    }
    explicit DynamicHookData(const Local<Object>& scriptObj, const NativeFunction& symbol)
    : NativeFunction(symbol), ScriptClass(scriptObj) {
    }
};

class ScriptFunctionSymbol : public NativeFunction, public ScriptClass {
public:
    explicit ScriptFunctionSymbol(const Local<Object>& scriptObj)
    : ScriptClass(scriptObj) {
    }
    static Local<Value> fromSymbol(const Arguments& args);
    static Local<Value> fromDescribe(const Arguments& args);
    Local<Value> setAddress(const Local<Value>& value);
    Local<Value> getAddress();
    Local<Value> hook(const Arguments& args);
};

extern ClassDefine<ScriptFunctionSymbol> NativeCallBuilder;
extern ClassDefine<DynamicHookData> NativeHookBuilder;

class NativePointer : public ScriptClass {
private:
    void* mPtr;

public:
    explicit NativePointer(void*);

    static void* extract(Local<Value> v);

    static Local<Object> newNativePointer(void*);

    void* wrap() {
        return dAccess<void*>(this, 0);
    }

    void* unwrap() {
        return (void*)&(*((int*)mPtr));
    }

    void* get() {
        return mPtr;
    }

    void set(void* ptr) {
        mPtr = ptr;
    };

    static Local<Value> fromSymbol(const Arguments& args);

    Local<Value> getRawPtr(const Arguments& args);

    Local<Value> offset(const Arguments& args);

    void setChar(const Local<Value>& value);
    void setUchar(const Local<Value>& value);
    void setShort(const Local<Value>& value);
    void setUshort(const Local<Value>& value);
    void setInt(const Local<Value>& value);
    void setUint(const Local<Value>& value);
    void setLong(const Local<Value>& value);
    void setUlong(const Local<Value>& value);
    void setLonglong(const Local<Value>& value);
    void setUlonglong(const Local<Value>& value);
    void setFloat(const Local<Value>& value);
    void setDouble(const Local<Value>& value);
    void setString(const Local<Value>& value);
    void setBool(const Local<Value>& value);

    Local<Value> getChar();
    Local<Value> getUchar();
    Local<Value> getShort();
    Local<Value> getUshort();
    Local<Value> getInt();
    Local<Value> getUint();
    Local<Value> getLong();
    Local<Value> getUlong();
    Local<Value> getLonglong();
    Local<Value> getUlonglong();
    Local<Value> getFloat();
    Local<Value> getDouble();
    Local<Value> getString();
    Local<Value> getBool();
};
extern ClassDefine<NativePointer> NativePointerBuilder;