/**
 * @file  NetherNetServerLocator.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "RakNet.hpp"
#include "StubServerLocator.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC class NetherNetServerLocator.
 *
 */
class NetherNetServerLocator : public StubServerLocator {

#define AFTER_EXTRA
// Add Member There
public:
struct ServerData {
    ServerData() = delete;
    ServerData(ServerData const&) = delete;
    ServerData(ServerData const&&) = delete;
};

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_NETHERNETSERVERLOCATOR
public:
    class NetherNetServerLocator& operator=(class NetherNetServerLocator const &) = delete;
    NetherNetServerLocator(class NetherNetServerLocator const &) = delete;
#endif

public:
    /**
     * @vftbl  0
     * @hash   -1345915016
     */
    virtual ~NetherNetServerLocator();
    /**
     * @vftbl  2
     * @hash   -1315668094
     */
    virtual void __unk_vfn_2();
    /**
     * @vftbl  3
     * @symbol ?startAnnouncingServer@NetherNetServerLocator@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0W4GameType@@HH_N2W4TransportLayer@@@Z
     * @hash   -950502288
     */
    virtual void startAnnouncingServer(std::string const &, std::string const &, enum class GameType, int, int, bool, bool, enum class TransportLayer);
    /**
     * @vftbl  4
     * @symbol ?stopAnnouncingServer@NetherNetServerLocator@@UEAAXXZ
     * @hash   -1923382892
     */
    virtual void stopAnnouncingServer();
    /**
     * @vftbl  5
     * @symbol ?startServerDiscovery@NetherNetServerLocator@@UEAAXUPortPair@@@Z
     * @hash   1541060497
     */
    virtual void startServerDiscovery(struct PortPair);
    /**
     * @vftbl  6
     * @symbol ?stopServerDiscovery@NetherNetServerLocator@@UEAAXXZ
     * @hash   582108532
     */
    virtual void stopServerDiscovery();
    /**
     * @vftbl  7
     * @hash   2086779527
     */
    virtual void __unk_vfn_7();
    /**
     * @vftbl  8
     * @hash   2087703048
     */
    virtual void __unk_vfn_8();
    /**
     * @vftbl  9
     * @symbol ?getServerList@NetherNetServerLocator@@UEBA?AV?$vector@UPingedCompatibleServer@@V?$allocator@UPingedCompatibleServer@@@std@@@std@@XZ
     * @hash   -1370518528
     */
    virtual std::vector<struct PingedCompatibleServer> getServerList() const;
    /**
     * @vftbl  10
     * @symbol ?clearServerList@NetherNetServerLocator@@UEAAXXZ
     * @hash   -408642201
     */
    virtual void clearServerList();
    /**
     * @vftbl  11
     * @symbol ?update@NetherNetServerLocator@@UEAAXXZ
     * @hash   -1704852046
     */
    virtual void update();
    /**
     * @vftbl  12
     * @hash   -291256027
     */
    virtual void __unk_vfn_12();
    /**
     * @vftbl  13
     * @hash   -232580250
     */
    virtual void __unk_vfn_13();
    /**
     * @vftbl  14
     * @hash   -231656729
     */
    virtual void __unk_vfn_14();
    /**
     * @symbol ??0NetherNetServerLocator@@QEAA@XZ
     * @hash   837453066
     */
    MCAPI NetherNetServerLocator();
    /**
     * @symbol ?setNetherNetInstance@NetherNetServerLocator@@QEAAXAEBV?$shared_ptr@UNetherNetInstance@@@std@@@Z
     * @hash   1608218055
     */
    MCAPI void setNetherNetInstance(class std::shared_ptr<struct NetherNetInstance> const &);

//private:
    /**
     * @symbol ?_cacheDiscoveryResponseData@NetherNetServerLocator@@AEAAXAEBUServerData@1@@Z
     * @hash   -725703643
     */
    MCAPI void _cacheDiscoveryResponseData(struct NetherNetServerLocator::ServerData const &);
    /**
     * @symbol ?_isNetherNetOverLANAllowed@NetherNetServerLocator@@AEBA_NXZ
     * @hash   -529164394
     */
    MCAPI bool _isNetherNetOverLANAllowed() const;
    /**
     * @symbol ?_onDiscoveryResponse@NetherNetServerLocator@@AEAAX_KV?$span@$$CBD$0?0@gsl@@@Z
     * @hash   -783732243
     */
    MCAPI void _onDiscoveryResponse(unsigned __int64, class gsl::span<char const, -1>);
    /**
     * @symbol ?_pruneStaleServers@NetherNetServerLocator@@AEAAXV?$duration@_JU?$ratio@$00$00@std@@@chrono@std@@@Z
     * @hash   1006915631
     */
    MCAPI void _pruneStaleServers(class std::chrono::duration<__int64, struct std::ratio<1, 1>>);
    /**
     * @symbol ?_setIsAnnouncing@NetherNetServerLocator@@AEAAX_N@Z
     * @hash   -1739378541
     */
    MCAPI void _setIsAnnouncing(bool);
    /**
     * @symbol ?_setIsDiscovering@NetherNetServerLocator@@AEAAX_N@Z
     * @hash   -412819782
     */
    MCAPI void _setIsDiscovering(bool);

private:

};