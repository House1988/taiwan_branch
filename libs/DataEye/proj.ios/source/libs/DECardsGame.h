//
//  DCCardGame.h
//  SDKTest
//
//  Created by HuiTong on 13-10-25.
//  Copyright (c) 2013年 HuiTong. All rights reserved.
//
#ifndef __DataEye__DECardsGameh__
#define __DataEye__DECardsGameh__

#import <Foundation/Foundation.h>

@interface DECardsGame : NSObject

/**
 *  @brief 玩家房间完成一局游戏后调用
 *  @brief lostOrGainCoin    获得或者丢失的虚拟币数量（不能为零）
 *  @param taxCoin  完成一局游戏时系统需要回收的虚拟币数量（税收）
 *  @param leftCoin   玩家剩余的虚拟币总量
 */
+(void)play:(NSString*)roomId label:(NSString*)label lostOrGainCoin:(const int)coinNum taxCoin:(const int)tax leftCoin:(const int)left;

/**
 *  @brief 玩家房间内丢失虚拟币时调用（完成一局游戏调用play接口后不必再调用该接口）
 *  @brief reason    虚拟币丢失原因
 *  @param lostCoin  丢失的虚拟币数量
 *  @param leftCoin   剩余的虚拟币数量
 */
+(void)lost:(NSString*)roomId reason:(NSString*)reason lostCoin:(const int)lost leftCoin:(const int)left;

/**
 *  @brief 玩家房间内获得虚拟币时调用（完成一局游戏调用play接口后不必再调用该接口）
 *  @param reason    虚拟币获得原因
 *  @param gainCoin   赢得的虚拟币数量
 *  @param leftCoin  剩余的虚拟币数量
 */
+(void)gain:(NSString*)roomId reason:(NSString*)reason gainCoin:(const int)gain leftCoin:(const int)left;

@end
#endif