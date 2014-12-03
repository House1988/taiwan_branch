//
//  DCAgentIOS.h
//  coco2d-sdk
//
//  Created by HuiTong on 13-11-4.
//
//
#ifndef __DCAGENT_IOS_H__
#define __DCAGENT_IOS_H__
#include <map>
#include <string>
#include "cocos2d.h"

using namespace cocos2d;

typedef enum
{
    accountAnonymous = 0,
    accountRegistered = 1,     // 显性注册帐户
    accountSianWeibo = 2,      // 新浪微博
    accountQQ = 3,             // QQ帐户
    accountTencentWeibo = 4,   // 腾讯微博
    accountND91 = 5,           // 91帐户
    accountType1 = 11,         // 预留1
    accountType2 = 12,         // 预留2
    accountType3 = 13,         // 预留3
    accountType4 = 14,         // 预留4
    accountType5 = 15,         // 预留5
    accountType6 = 16,         // 预留6
    accountType7 = 17,         // 预留7
    accountType8 = 18,         // 预留8
    accountType9 = 19,         // 预留9
    accountType10 = 20
}AccountType;

// 性别
typedef enum {
    genderUnknown = 0,     // 未知
    genderMale = 1,        // 男
    genderFemale = 2       // 女
} DataeyeGender;

typedef enum{
    TaskGuideLine = 1,
    TaskMainLine,
    TaskBranchLine,
    TaskDaily,
    TaskActivity,
    TaskOther
}DataeyeTaskType;

class DCAgent
{
public:
    static void onStart(const char* appId, const char* channelId);
    static void setLogOn();
};

class DCAccount
{
public:
    static void login(const char* accountId);
    
    static void logout();

    static void setAccountType(AccountType accountType);

    static void setLevel(int level);

    static void setGender(DataeyeGender gender);

    static void setAge(int age);

    static void setGameServer(const char* gameServer);
    static void tag(const char* tag);
    static void unTag(const char* tag);
};

class DCVirtualCurrency
{
public:
    static void onCharge(const char* orderId, const char* iapId, double currencyAmount, const char* currencyType, const char* paymentType);
    
    static void onChargeSuccess(const char* orderId);
    
    static void onChargeOnlySuccess(double currencyAmount, const char* currencyType, const char* paymentType);
};

class DCItem
{
public:
    static void buy(const char* itemId, const char* itemType, int itemCount, int virtualCurrency, const char* currencyType);
    static void get(const char* itemId, const char* itemType, int itemCount, const char* reason);
    static void consume(const char* itemId, const char* itemType, int itemCount, const char* reason);
};

class DCTask
{
public:
    static void begin(const char* taskId, DataeyeTaskType type);
    static void complete(const char* taskId);
    static void fail(const char* taskId, const char* reason);
};

class DCEvent
{
public:
    static void onEventCount(const char* eventId);
    static void onEvent(const char* eventId);
    static void onEvent(const char* eventId, const char* label);
    static void onEvent(const char* eventId, std::map<std::string, std::string>* map);
    
    static void onEventDuration(const char* eventId, long duration);
    static void onEventDuration(const char* eventId, const char* label, long duration);
    static void onEventDuration(const char* eventId, std::map<std::string, std::string>* map, long duration);
    
    static void onEventBegin(const char* eventId);
    static void onEventBegin(const char* eventId, std::map<std::string, std::string>* map);
    static void onEventEnd(const char* eventId);
    
    static void onEventBegin(const char* eventId, std::map<std::string, std::string>* map, const char* flag);
    static void onEventEnd(const char* eventId, const char* flag);
};

class DCCoin
{
public:
    static void setCoinNum(int total, const char* coinType);
    static void lost(const char* reason, int lost, int left, const char* coinType);
    static void gain(const char* reason, int gain, int left, const char* coinType);
};

class DCMonitor
{
public:
    static void onMonitor(const char* monitorName, bool isSucces, int costTime);
};

#define DCCONFIGPARAMS_UPDATE_SUCCESS "DataeyeConfigParamsSuccess"

static void DCConfig_UpdateSuccess(const char* event);

class DCConfigParams:public CCObject
{
public:
    static void update();
    static const char* getParameterString(const char* key, const char* defaultValue);
    static int getParameterInt(const char* key, int defaultValue);
    static bool getParameterBool(const char* key, bool defaultValue);
};

class DCLevels
{
public:
	static void begin(int levelNumber, const char* levelId);
	static void complete(const char* levelId);
	static void fail(const char* levelId, const char* failPoint);
};

#endif
