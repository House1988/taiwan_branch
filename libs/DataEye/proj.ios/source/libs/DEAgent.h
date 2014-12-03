//
//  DCSdk.h
//  DCSdk
//
//  Created by iwanglian on 13-7-8.
//  Copyright (c) 2013年 digitcube. All rights reserved.
//
#ifndef __DataEye__DEAgenth__
#define __DataEye__DEAgenth__

#import <Foundation/Foundation.h>

//这里提供静态方法
@interface DEAgent : NSObject
/**
 *  @brief 程序启动时调用
 *
 *  一般在- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions内调用一次即可
 *  !!!一定要调用，否则后面无法上报,只能调用一次
 *  @param appId         在我们网站上创建游戏时分配的appId,用于标识这款游戏. 注意保密!
 *  @param channelId    渠道id , 方便统计分析你在各渠道的推广效果
 */
+ (void)onStart:(NSString *)appId withChannelId:(NSString*)channelId;

/**
 *  @brief 设置开启Log
 *
 *  (1)打印流程信息
 *  (2)错误提示
 *  默认关闭，开发调试时打开，请在正式发布前关闭。
 */
+(void)setLogOn;

/**
 * @brief 获取设备id
 *
 *  当不需要用户登录时，为标识用户，应用可以为用户分配游戏中设定的设备绑定id
 *  也可以使用此方法提供的
 */
+(NSString*)getDeviceId;

@end

// 帐户类型
typedef enum {
    kAccountAnonymous = 0,      // 匿名帐户
    kAccountRegistered = 1,     // 显性注册帐户
    kAccountSianWeibo = 2,      // 新浪微博
    kAccountQQ = 3,             // QQ帐户
    kAccountTencentWeibo = 4,   // 腾讯微博
    kAccountND91 = 5,           // 91帐户
    kAccountType1 = 11,         // 预留1
    kAccountType2 = 12,         // 预留2
    kAccountType3 = 13,         // 预留3
    kAccountType4 = 14,         // 预留4
    kAccountType5 = 15,         // 预留5
    kAccountType6 = 16,         // 预留6
    kAccountType7 = 17,         // 预留7
    kAccountType8 = 18,         // 预留8
    kAccountType9 = 19,         // 预留9
    kAccountType10 = 20         // 预留10
} DCSdkAccountType;

// 性别
typedef enum {
    kGenderUnknown = 0,     // 未知
    kGenderMale = 1,        // 男
    kGenderFemale = 2       // 女
} DCSdkGender;


@interface DEAccount : NSObject
/**
 *	@brief	设置帐号
 *
 *  ！！！必须调用，上报系统信赖accountId进行数据分析
 *  可以调用多次
 *	@param 	accountId   帐号id，必须分配且唯一。如果无注册系统，可以使用设备绑定的id
 */
+ (void)login:(NSString *)accountId;

/**
 *  @brief 退出时调用
 *
 */
+ (void)logout;

/**
 *  @brief 标记玩家属于哪一类玩家，即给玩家加玩家类型标记，如：任务党、成就党、聊天党等
 *
 */
+(void)tag:(NSString*)tag;

/**
 *  @brief 将一种玩家标记从玩家身上去除
 *
 */
+(void)unTag:(NSString*)tag;

/**
 *	@brief	设置帐号类型
 *	@param 	accountType     账户类型   
 */
+ (void)setAccountType:(DCSdkAccountType)accountType;

/**
 *	@brief	设置帐号等级
 *
 *  !!!用户升级后务必调用
 *	@param 	level       升级之后的等级
 */
+ (void)setLevel:(int)level;

/**
 *	@brief	设置性别
 *	@param 	gender      性别 
 */
+ (void)setGender:(DCSdkGender)gender;

/**
 *	@brief	设置年龄
 *	@param 	age     年龄
 */
+ (void)setAge:(int)age;

/**
 *	@brief	设置区服
 *	@param  gameServer      区服
 */
+ (void)setGameServer:(NSString *)gameServer;

@end

@interface DEVirtualCurrency : NSObject

/**
 *	@brief	虚拟币充值请求简化版，与onChargeRequest相比，少了充值包ID与虚拟币金额等参数
 *
 *  与onChargeSuccess成对使用
 *
 *	@param 	orderId                 订单id     最多32个字符
 *  @param  iapId                   礼包ID，可以为空
 *	@param 	currencyAmount          现金金额
 *	@param 	currencyType            币种       需要使用ISO4217中规范的3字母代码，如美元USD、人民币CNY等 
 *	@param 	paymentType             支付类型    最多16个字符
 */
+ (void)onCharge:(NSString*)orderId
           iapId:(NSString*)iapId
  currencyAmount:(double)currencyAmount
    currencyType:(NSString*)currencyType
     paymentType:(NSString*)paymentType;

/**
 *	@brief	虚拟币充值请求成功
 *
 *  与onChargeRequst或者onCharge成对使用
 *
 *	@param 	orderId                 订单id        
 */
+ (void)onChargeSuccess:(NSString *)orderId;


/**
 *	@brief	虚拟币充值请求，用于只能发起充值请求，无法获取充值完成详情的情形
 *
 *	@param 	currencyAmount          现金金额
 *	@param 	currencyType            币种       需要使用ISO4217中规范的3字母代码，如美元USD、人民币CNY等 
 *	@param 	paymentType             支付类型    最多16个字符
 */
+(void)onChargeOnlySuccess:(double)currencyAmount
              currencyType:(NSString *)currencyType
               paymentType:(NSString *)paymentType;
@end

@interface DEItem : NSObject

/**
 *  @brief 道具购买
 *  @param itemId    道具id或者名称，需要保证该值在游戏中的唯一性，非空，最大32个字符
 *  @param itemType   道具类型，最大32个字符
 *  @param itemCount  购买的道具数量
 *  @param virtualCurrency 购买的道具虚拟价值，非空，最大32字符
 *  @param currencyType 计算道具虚拟价值所用的货币类型，非空，最大32字符
 */
+(void)buy:(NSString*)itemId
      type:(NSString*)itemType
 itemCount:(int)itemCount
virtualCurrency:(int)virtualCurrency
currencyType:(NSString*)currencyType;

/**
 *  @brief 因某种原因消耗道具
 *  @param itemId    道具id或者名称，需要保证该值在游戏中的唯一性，非空，最大32个字符
 *  @param itemType   道具类型，最大32个字符
 *  @param itemCount  消耗的道具数量
 *  @param reason     消耗道具的原因，非空，最大32字符
 */
+(void)consume:(NSString*)itemId
          type:(NSString*)itemType
     itemCount:(int)itemCount
        reason:(NSString*)reason;

/**
 *  @brief 因某种原因获得道具
 *  @param itemId    道具id或者名称，需要保证该值在游戏中的唯一性，非空，最大32个字符
 *  @param itemType   道具类型，最大32个字符
 *  @param itemCount  获得的道具数量
 *  @param reason     获得道具的原因，非空，最大32字符
 */
+(void)get:(NSString*)itemId
      type:(NSString*)itemType
 itemCount:(int)itemCount
    reason:(NSString*)reason;

@end

typedef enum{
    GuideLine = 1,
    MainLine,
    BranchLine,
    Daily,
    Activity,
    Other
}DCSdkTaskType;

@interface DETask : NSObject

+(DCSdkTaskType)getType:(int)type;

/**
 *  @brief 开始任务
 *  @param taskId    任务id或者名称，需要保证该值在游戏中的唯一性，非空，最大32个字符
 *  @param taskType   任务类型
 *  
 */
+(void)begin:(NSString*)taskId taskType:(DCSdkTaskType)type;

/**
 *  @brief 任务完成
 *  @param taskId    任务id或者名称，需要保证该值在游戏中的唯一性，非空，最大32个字符
 *
 */
+(void)complete:(NSString*)taskId;

/**
 *  @brief 任务失败
 *  @param taskId    任务id或者名称，需要保证该值在游戏中的唯一性，非空，最大32个字符
 *  @param taskType   任务失败原因
 *
 */
+(void)fail:(NSString*)taskId reason:(NSString*)reason;

@end

@interface DEEvent : NSObject
/**
 *  @brief 自定义事件
 *  @param eventId    自定义事件ID， 最大32个字符
 *  @param duration   事件发生时长
 *  @param map        事件关注的属性值对
 */
 + (void)onEventCount:(NSString*)eventId;
 + (void)onEventCount:(NSString *)eventId count:(int)count;
 + (void)onEvent : (NSString*)eventId;
 + (void)onEvent : (NSString*)eventId label:(NSString*)label;
 + (void)onEvent : (NSString*)eventId dictionary:(NSDictionary*)dic;

 + (void)onEventDuration : (NSString*)eventId duration:(long)duration;
 + (void)onEventDuration : (NSString*)eventId label:(NSString*)label duration:(long)duration;
 + (void)onEventDuration : (NSString*)eventId dictionary:(NSDictionary*)dic duration:(long)duration;
 
/**
 *  @brief 过程性事件开始接口，用于准确统计该事件发生的时长,注意该事件发生的最小时间为1分钟，否则时间统计不准，或者为0
 *  @eventId 自定义事件ID
 *
 */
 + (void)onEventBegin : (NSString*)eventId;
 + (void)onEventBegin : (NSString*)eventId dictionary:(NSDictionary*)dic;
 + (void)onEventEnd : (NSString*)eventId;
 + (void)onEventEnd : (NSString *)eventId dictionary:(NSDictionary*)dic;

 + (void)onEventBegin : (NSString*)eventId dictionary:(NSDictionary*)dic flag:(NSString*)flag;
 + (void)onEventEnd : (NSString*)eventId flag:(NSString*)flag;
 + (void)onEventEnd : (NSString*)eventId dictionary:(NSDictionary*)dic flag:(NSString*)flag;
 
@end

@interface DECoin : NSObject

/**
 *  @brief 设置玩家金币总量
 *  @param coinType 虚拟币类型
 *
 **/
+(void)setCoinNum:(int)totalCoin coinType:(NSString*)coinType;

/**
 *  @brief 玩家失去虚拟币
 *  @param reason 失去虚拟币原因，后台以该参数作为统计ID
 *  @param lostCoin 失去虚拟币数量
 *  @param leftCoin 剩余虚拟币总量
 *  @param coinType 虚拟币类型
 **/
+(void)lost:(NSString*)reason lostCoin:(int)lost leftCoin:(int)left coinType:(NSString*)coinType;

/**
 *  @brief 玩家获得虚拟币
 *  @param reason 获得虚拟币原因，后台以该参数作为统计ID
 *  @param gainCoin 获得虚拟币数量
 *  @param leftCoin 剩余虚拟币总量
 *  @param coinType 虚拟币类型
 **/
+(void)gain:(NSString*)reason gainCoin:(int)gain leftCoin:(int)left coinType:(NSString*)coinType;
@end

@interface DEMonitor : NSObject

/**
 *	@brief	onMonitor    一项监控
 *	@param 	monitorName   监控名称 最大32个字符
 *  @param  isSuccess 此次调用是否成功
 *  @param   costTime  花费时长，以秒为单位
 */
+(void)onMonitor:(NSString *)monitorName isSuccess:(BOOL)isSuccess costTime:(int)costTime;
@end

#define DATAEYE_CONFIG_PARAMS_UPDATE_SUCCESS    @"DataeyeConfigParamsSuccess"
typedef void (*CALLBACK)(const char* event);

@interface DEConfigParams : NSObject

-(void)update;

+(void)update;

-(void)setCallBack:(CALLBACK)func;

+(int)getParameterInt:(NSString*)key defaults:(int)value;

+(long)getParameterLong:(NSString*)key defaults:(long)value;

+(BOOL)getParameterBool:(NSString*)key defaults:(BOOL)value;

+(NSString*)getParameterString:(NSString*)key defaults:(NSString*)value;
@end

@interface DELevels : NSObject

+(void)begin:(int)levelNumber levelId:(NSString*)levelId;

+(void)complete:(NSString*)levelId;

+(void)fail:(NSString*)levelId failPoint:(NSString*)failPoint;

@end

#endif
