/**
 * @file  Path.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

enum NodeType;
enum PathCompletionType;

#undef BEFORE_EXTRA

/**
 * @brief MC class Path.
 *
 */
class Path {

#define AFTER_EXTRA
// Add Member There
public:
    class Node
    {
        BlockPos mPos;
        enum NodeType mType;
    };

    std::vector<Node> mNodes;
    size_t mIndex;
    enum PathCompletionType mCompletionType;

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_PATH
public:
    class Path& operator=(class Path const &) = delete;
    Path(class Path const &) = delete;
#endif

public:
    /**
     * @symbol ??0Path@@QEAA@XZ
     * @hash   -832068863
     */
    MCAPI Path();
    /**
     * @symbol ?currentPos@Path@@QEBA?AVVec3@@PEBVActor@@@Z
     * @hash   -1131075692
     */
    MCAPI class Vec3 currentPos(class Actor const *) const;
    /**
     * @symbol ?currentPos@Path@@QEBAAEBVBlockPos@@XZ
     * @hash   -769014072
     */
    MCAPI class BlockPos const & currentPos() const;
    /**
     * @symbol ?endsInXZ@Path@@QEAA_NAEBVVec3@@@Z
     * @hash   237098225
     */
    MCAPI bool endsInXZ(class Vec3 const &);
    /**
     * @symbol ?getCompletionType@Path@@QEBA?AW4PathCompletionType@@XZ
     * @hash   1546240032
     */
    MCAPI enum PathCompletionType getCompletionType() const;
    /**
     * @symbol ?getEndPos@Path@@QEBA?AVVec3@@XZ
     * @hash   -491483296
     */
    MCAPI class Vec3 getEndPos() const;
    /**
     * @symbol ?getIndex@Path@@QEBA_KXZ
     * @hash   1082506615
     */
    MCAPI unsigned __int64 getIndex() const;
    /**
     * @symbol ?getLastPos@Path@@QEBAAEBVBlockPos@@XZ
     * @hash   -353616158
     */
    MCAPI class BlockPos const & getLastPos() const;
    /**
     * @symbol ?getNodePos@Path@@QEBAAEBVBlockPos@@_K@Z
     * @hash   49967728
     */
    MCAPI class BlockPos const & getNodePos(unsigned __int64) const;
    /**
     * @symbol ?getNodeType@Path@@QEBA?AW4NodeType@@_K@Z
     * @hash   -1766241016
     */
    MCAPI enum NodeType getNodeType(unsigned __int64) const;
    /**
     * @symbol ?getPos@Path@@QEBA?AVVec3@@PEBVActor@@_K@Z
     * @hash   227775566
     */
    MCAPI class Vec3 getPos(class Actor const *, unsigned __int64) const;
    /**
     * @symbol ?getSize@Path@@QEBA_KXZ
     * @hash   -818613505
     */
    MCAPI unsigned __int64 getSize() const;
    /**
     * @symbol ?isDone@Path@@QEBA_NXZ
     * @hash   1348063020
     */
    MCAPI bool isDone() const;
    /**
     * @symbol ?isValid@Path@@QEBA_NXZ
     * @hash   -272882566
     */
    MCAPI bool isValid() const;
    /**
     * @symbol ?makeCopy@Path@@QEBA?AV?$unique_ptr@VPath@@U?$default_delete@VPath@@@std@@@std@@XZ
     * @hash   -1956315926
     */
    MCAPI std::unique_ptr<class Path> makeCopy() const;
    /**
     * @symbol ?next@Path@@QEAAXXZ
     * @hash   -468954075
     */
    MCAPI void next();
    /**
     * @symbol ?sameAs@Path@@QEBA_NPEAV1@@Z
     * @hash   256660536
     */
    MCAPI bool sameAs(class Path *) const;
    /**
     * @symbol ?setIndex@Path@@QEAAX_K@Z
     * @hash   1544372787
     */
    MCAPI void setIndex(unsigned __int64);
    /**
     * @symbol ?setSize@Path@@QEAAX_K@Z
     * @hash   -1073498821
     */
    MCAPI void setSize(unsigned __int64);
    /**
     * @symbol ??1Path@@QEAA@XZ
     * @hash   -965678065
     */
    MCAPI ~Path();

//private:
    /**
     * @symbol ?buildFromNodes@Path@@AEAAX$$QEAV?$vector@VNode@Path@@V?$allocator@VNode@Path@@@std@@@std@@W4PathCompletionType@@@Z
     * @hash   -217442867
     */
    MCAPI void buildFromNodes(std::vector<class Path::Node> &&, enum PathCompletionType);

private:

};