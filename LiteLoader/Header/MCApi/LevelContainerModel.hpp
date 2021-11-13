// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#include <Global.h>
#include "ContainerModel.hpp"
class LevelContainerModel : public ContainerModel {
public:
    virtual void containerContentChanged(int);
    virtual ~LevelContainerModel();
    virtual void postInit();
    virtual void releaseResources();
    virtual void unk_vfn_6();
    virtual class ContainerWeakRef getContainerWeakRef();
    virtual void unk_vfn_9();
    virtual void unk_vfn_11();
    virtual void unk_vfn_12();
    virtual bool isValid();
    virtual void unk_vfn_15();
    virtual void unk_vfn_16();
    virtual void unk_vfn_17();
    virtual void unk_vfn_18();
    virtual void unk_vfn_19();
    virtual class Container* _getContainer();
    virtual int _getContainerOffset();
    virtual void _onItemChanged(int, class ItemStack const&, class ItemStack const&);

public:
    MCAPI static class Container* getContainerHelper(class Player&, enum BlockActorType, class BlockPos const&);

private:
    MCAPI class Actor* _getEntity() const;
    MCAPI void _refreshSlot(int);
};