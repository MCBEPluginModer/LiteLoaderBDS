// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#include <Global.h>
#include "MineshaftPiece.hpp"
class MineshaftStairs : public MineshaftPiece {
public:
    virtual ~MineshaftStairs();
    virtual void unk_vfn_2();
    virtual int /*enum StructurePieceType*/ getType();
    virtual void addChildren(class StructurePiece&, std::vector<std::unique_ptr<class StructurePiece>>&, class Random&);
    virtual bool postProcess(class BlockSource&, class Random&, class BoundingBox const&);
    virtual void postProcessMobsAt(class BlockSource&, class Random&, class BoundingBox const&);
    virtual int getWorldZ(int, int);
};