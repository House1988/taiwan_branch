//
//  DCAgentIOS.m
//  coco2d-sdk
//
//  Created by HuiTong on 13-11-4.
//
//

#import "DCAgent.h"
#import "DEAgent.h"

void DCAgent::onStart(const char* appId, const char* channelId)
{
    NSString* objcAppId = [NSString stringWithCString:appId encoding:NSUTF8StringEncoding];
    NSString* objcChannelId = [NSString stringWithCString:channelId encoding:NSUTF8StringEncoding];
    [DEAgent onStart:objcAppId withChannelId:objcChannelId];
}

void DCAgent::setLogOn()
{
    [DEAgent setLogOn];
}

void DCAccount::login(const char* accountId)
{
    NSString* objcAccountId = [NSString stringWithCString:accountId encoding:NSUTF8StringEncoding];
    [DEAccount login:objcAccountId];
}

void DCAccount::logout()
{
    [DEAccount logout];
}

void DCAccount::setAccountType(AccountType accountType)
{
    [DEAccount setAccountType:(DCSdkAccountType)accountType];
}

void DCAccount::setLevel(int level)
{
    [DEAccount setLevel:level];
}

void DCAccount::setGender(DataeyeGender gender)
{
    [DEAccount setGender:(DCSdkGender)gender];
}

void DCAccount::setAge(int age)
{
    [DEAccount setAge:age];
}

void DCAccount::setGameServer(const char* gameServer)
{
    NSString* objcGameServer = [NSString stringWithCString:gameServer encoding:NSUTF8StringEncoding];
    [DEAccount setGameServer:objcGameServer];
}

void DCAccount::tag(const char* tag)
{
    NSString* objcTag = [NSString stringWithCString:tag encoding:NSUTF8StringEncoding];
    [DEAccount tag:objcTag];
}

void DCAccount::unTag(const char* tag)
{
    NSString* objcTag = [NSString stringWithCString:tag encoding:NSUTF8StringEncoding];
    [DEAccount unTag:objcTag];
}

void DCVirtualCurrency::onCharge(const char *orderId, const char* iapId, double currencyAmount, const char *currencyType, const char *paymentType)
{
    NSString* objcOrderId = [NSString stringWithCString:orderId encoding:NSUTF8StringEncoding];
    NSString* objcIapId = [NSString stringWithCString:iapId encoding:NSUTF8StringEncoding];
    NSString* objcCurrencyType = [NSString stringWithCString:currencyType encoding:NSUTF8StringEncoding];
    NSString* objcPaymentType = [NSString stringWithCString:paymentType encoding:NSUTF8StringEncoding];
    
    [DEVirtualCurrency onCharge:objcOrderId iapId:objcIapId currencyAmount:currencyAmount currencyType:objcCurrencyType paymentType:objcPaymentType];
}

void DCVirtualCurrency::onChargeSuccess(const char *orderId)
{
    NSString* objcOrderId = [NSString stringWithCString:orderId encoding:NSUTF8StringEncoding];
    [DEVirtualCurrency onChargeSuccess:objcOrderId];
}

void DCVirtualCurrency::onChargeOnlySuccess(double currencyAmount, const char* currencyType, const char* paymentType)
{
    NSString* objcCurrencyType = [NSString stringWithCString:currencyType encoding:NSUTF8StringEncoding];
    NSString* objcPaymentType = [NSString stringWithCString:paymentType encoding:NSUTF8StringEncoding];
    
    [DEVirtualCurrency onChargeOnlySuccess:currencyAmount currencyType:objcCurrencyType paymentType:objcPaymentType];
}

void DCItem::buy(const char* itemId, const char* itemType, int itemCount, int virtualCurrency, const char* currencyType)
{
    NSString* objcItemId = [NSString stringWithCString:itemId encoding:NSUTF8StringEncoding];
    NSString* objcItemType = [NSString stringWithCString:itemType encoding:NSUTF8StringEncoding];
    NSString* objcCurrencyType = [NSString stringWithCString:currencyType encoding:NSUTF8StringEncoding];
    
    [DEItem buy:objcItemId type:objcItemType itemCount:itemCount virtualCurrency:virtualCurrency currencyType:objcCurrencyType];
}

void DCItem::get(const char *itemId, const char *itemType, int itemCount, const char *reason)
{
    NSString* objcItemId = [NSString stringWithCString:itemId encoding:NSUTF8StringEncoding];
    NSString* objcItemType = [NSString stringWithCString:itemType encoding:NSUTF8StringEncoding];
    NSString* objcReason = [NSString stringWithCString:reason encoding:NSUTF8StringEncoding];
    
    [DEItem get:objcItemId type:objcItemType itemCount:itemCount reason:objcReason];
}

void DCItem::consume(const char *itemId, const char *itemType, int itemCount, const char *reason)
{
    NSString* objcItemId = [NSString stringWithCString:itemId encoding:NSUTF8StringEncoding];
    NSString* objcItemType = [NSString stringWithCString:itemType encoding:NSUTF8StringEncoding];
    NSString* objcReason = [NSString stringWithCString:reason encoding:NSUTF8StringEncoding];
    
    [DEItem consume:objcItemId type:objcItemType itemCount:itemCount reason:objcReason];
}

void DCTask::begin(const char *taskId, DataeyeTaskType type)
{
    NSString* objcTaskId = [NSString stringWithCString:taskId encoding:NSUTF8StringEncoding];
    
    [DETask begin:objcTaskId taskType:[DETask getType:(int)type]];
}

void DCTask::complete(const char *taskId)
{
    NSString* objcTaskId = [NSString stringWithCString:taskId encoding:NSUTF8StringEncoding];
    
    [DETask complete:objcTaskId];
}

void DCTask::fail(const char *taskId, const char *reason)
{
    NSString* objcTaskId = [NSString stringWithCString:taskId encoding:NSUTF8StringEncoding];
    NSString* objcReason = [NSString stringWithCString:reason encoding:NSUTF8StringEncoding];
    
    [DETask fail:objcTaskId reason:objcReason];
}

void DCEvent::onEvent(const char *eventId)
{
    NSString* objcEventId = [NSString stringWithCString:eventId encoding:NSUTF8StringEncoding];
    [DEEvent onEvent:objcEventId];
}

void DCEvent::onEvent(const char* eventId, const char* label)
{
    NSString* objcEventId = [NSString stringWithCString:eventId encoding:NSUTF8StringEncoding];
    NSString* objcLabel = [NSString stringWithCString:label encoding:NSUTF8StringEncoding];
    [DEEvent onEvent:objcEventId label:objcLabel];
}

void DCEvent::onEvent(const char *eventId, std::map<std::string, std::string>* map)
{
    NSString* objcEventId = [NSString stringWithCString:eventId encoding:NSUTF8StringEncoding];
    
    NSMutableDictionary* dictionary = [[NSMutableDictionary alloc] initWithCapacity:5];
    std::map<std::string, std::string>::iterator it;
    for (it = map->begin(); it != map->end(); ++it) {
        NSString* key = [NSString stringWithCString:it->first.c_str() encoding:NSUTF8StringEncoding];
        NSString* value = [NSString stringWithCString:it->second.c_str() encoding:NSUTF8StringEncoding];
        [dictionary setObject:value forKey:key];
    }
    
    [DEEvent onEvent:objcEventId dictionary:dictionary];
}

void DCEvent::onEventCount(const char *eventId)
{
    NSString* objcEventId = [NSString stringWithCString:eventId encoding:NSUTF8StringEncoding];
    [DEEvent onEventCount:objcEventId];
}

void DCEvent::onEventDuration(const char *eventId, long duration)
{
    NSString* objcEventId = [NSString stringWithCString:eventId encoding:NSUTF8StringEncoding];
    [DEEvent onEventDuration:objcEventId duration:duration];
}

void DCEvent::onEventDuration(const char *eventId, const char *label, long duration)
{
    NSString* objcEventId = [NSString stringWithCString:eventId encoding:NSUTF8StringEncoding];
    NSString* objcLabel = [NSString stringWithCString:label encoding:NSUTF8StringEncoding];
    
    [DEEvent onEventDuration:objcEventId label:objcLabel duration:duration];
}

void DCEvent::onEventDuration(const char *eventId, std::map<std::string, std::string> *map, long duration)
{
    NSString* objcEventId = [NSString stringWithCString:eventId encoding:NSUTF8StringEncoding] ;
    
    NSMutableDictionary* dictionary = [[NSMutableDictionary alloc] initWithCapacity:5];
    std::map<std::string, std::string>::iterator it;
    for (it = map->begin(); it != map->end(); ++it) {
        NSString* key = [NSString stringWithCString:it->first.c_str() encoding:NSUTF8StringEncoding] ;
        NSString* value = [NSString stringWithCString:it->second.c_str() encoding:NSUTF8StringEncoding];
        [dictionary setObject:value forKey:key];
    }
    
    [DEEvent onEventDuration:objcEventId dictionary:dictionary duration:duration];
}

void DCEvent::onEventBegin(const char *eventId)
{
    NSString* objcEventId = [NSString stringWithCString:eventId encoding:NSUTF8StringEncoding];
    
    [DEEvent onEventBegin:objcEventId];
}

void DCEvent::onEventBegin(const char* eventId, std::map<std::string, std::string>* map)
{
    NSString* objcEventId = [NSString stringWithCString:eventId encoding:NSUTF8StringEncoding];
    
    NSMutableDictionary* dictionary = [[NSMutableDictionary alloc] initWithCapacity:5];
    std::map<std::string, std::string>::iterator it;
    for (it = map->begin(); it != map->end(); ++it) {
        NSString* key = [NSString stringWithCString:it->first.c_str() encoding:NSUTF8StringEncoding];
        NSString* value = [NSString stringWithCString:it->second.c_str() encoding:NSUTF8StringEncoding];
        [dictionary setObject:value forKey:key];
    }
    [DEEvent onEventBegin:objcEventId dictionary:dictionary];
}

void DCEvent::onEventEnd(const char *eventId)
{
    NSString* objcEventId = [NSString stringWithCString:eventId encoding:NSUTF8StringEncoding];
    
    [DEEvent onEventEnd:objcEventId];
}

void DCEvent::onEventBegin(const char *eventId, std::map<std::string, std::string> *map, const char *flag)
{
    NSString* objcEventId = [NSString stringWithCString:eventId encoding:NSUTF8StringEncoding];
    NSString* objFlag = [NSString stringWithCString:flag encoding:NSUTF8StringEncoding];
    
    NSMutableDictionary* dictionary = [[NSMutableDictionary alloc] initWithCapacity:5];
    std::map<std::string, std::string>::iterator it;
    for (it = map->begin(); it != map->end(); ++it) {
        NSString* key = [NSString stringWithCString:it->first.c_str() encoding:NSUTF8StringEncoding];
        NSString* value = [NSString stringWithCString:it->second.c_str() encoding:NSUTF8StringEncoding];
        [dictionary setObject:value forKey:key];
    }
    [DEEvent onEventBegin:objcEventId dictionary:dictionary flag:objFlag];
}

void DCEvent::onEventEnd(const char *eventId, const char *flag)
{
    NSString* objcEventId = [NSString stringWithCString:eventId encoding:NSUTF8StringEncoding];
    NSString* objFlag = [NSString stringWithCString:flag encoding:NSUTF8StringEncoding];
    
    [DEEvent onEventEnd:objcEventId flag:objFlag];
}

void DCCoin::setCoinNum(int total, const char* coinType)
{
    NSString* objcCoinType = [NSString stringWithCString:coinType encoding:NSUTF8StringEncoding];
    [DECoin setCoinNum:total coinType:objcCoinType];
}

void DCCoin::lost(const char* reason, int lost, int left, const char* coinType)
{
    NSString* objcReason = [NSString stringWithCString:reason encoding:NSUTF8StringEncoding];
    NSString* objcCoinType = [NSString stringWithCString:coinType encoding:NSUTF8StringEncoding];
    [DECoin lost:objcReason lostCoin:lost leftCoin:left coinType:objcCoinType];
}

void DCCoin::gain(const char* reason, int gain, int left, const char* coinType)
{
    NSString* objcReason = [NSString stringWithCString:reason encoding:NSUTF8StringEncoding];
    NSString* objcCoinType = [NSString stringWithCString:coinType encoding:NSUTF8StringEncoding];
    [DECoin gain:objcReason gainCoin:gain leftCoin:left coinType:objcCoinType];
}

void DCMonitor::onMonitor(const char* monitorName, bool isSuccess, int costTime)
{
    NSString* objcMonitorName = [NSString stringWithCString:monitorName encoding:NSUTF8StringEncoding];
    [DEMonitor onMonitor:objcMonitorName isSuccess:isSuccess costTime:costTime];
}

void DCConfigParams::update()
{
    DEConfigParams* config = [[DEConfigParams alloc] init];
    [config setCallBack:DCConfig_UpdateSuccess];
    [config update];
}

static void DCConfig_UpdateSuccess(const char* event)
{
    if(strcmp(event, DCCONFIGPARAMS_UPDATE_SUCCESS) == 0)
    {
        CCNotificationCenter::sharedNotificationCenter()->postNotification(DCCONFIGPARAMS_UPDATE_SUCCESS);
    }
}

const char* DCConfigParams::getParameterString(const char *key, const char *defaultValue)
{
    NSString* objcKey = [NSString stringWithCString:key encoding:NSUTF8StringEncoding];
    NSString* objcValue = [NSString stringWithCString:defaultValue encoding:NSUTF8StringEncoding];
    NSString* objcResult = [DEConfigParams getParameterString:objcKey defaults:objcValue];
    return [objcResult UTF8String];
}

int DCConfigParams::getParameterInt(const char *key, int defaultValue)
{
    NSString* objcKey = [NSString stringWithCString:key encoding:NSUTF8StringEncoding];
    return [DEConfigParams getParameterInt:objcKey defaults:defaultValue];
}

bool DCConfigParams::getParameterBool(const char *key, bool defaultValue)
{
    NSString* objcKey = [NSString stringWithCString:key encoding:NSUTF8StringEncoding];
    return [DEConfigParams getParameterBool:objcKey defaults:defaultValue];
}

void DCLevels::begin(int levelNumber, const char* levelId)
{
    NSString* objcLevelId = [NSString stringWithCString:levelId encoding:NSUTF8StringEncoding];
    
    [DELevels begin:levelNumber levelId:objcLevelId];
}

void DCLevels::complete(const char *levelId)
{
    NSString* objcLevelId = [NSString stringWithCString:levelId encoding:NSUTF8StringEncoding];
    
    [DELevels complete:objcLevelId];
}

void DCLevels::fail(const char *levelId, const char *failPoint)
{
    NSString* objcLevelId = [NSString stringWithCString:levelId encoding:NSUTF8StringEncoding];
    NSString* objcFailPoint = [NSString stringWithCString:failPoint encoding:NSUTF8StringEncoding];
    
    [DELevels fail:objcLevelId failPoint:objcFailPoint];
}



