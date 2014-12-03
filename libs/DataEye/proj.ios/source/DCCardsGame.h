//
//  DCCardGame_Interface.h
//  DataEyeSDK
//
//  Created by HuiTong on 13-11-11.
//  Copyright (c) 2013年 HuiTong. All rights reserved.
//

#ifndef __DataEyeSDK__DCCardGameIOS__
#define __DataEyeSDK__DCCardGameIOS__

#include <iostream>

class DCCardsGame
{
public:
    /**
     *  @brief 玩家房间完成一局游戏后调用
     *  @brief lostOrGainCoin    获得或者丢失的虚拟币数量（不能为零）
     *  @param taxCoin  完成一局游戏时系统需要回收的虚拟币数量（税收）
     *  @param leftCoin   玩家剩余的虚拟币总量
     */
    static void play(const char* roomId, const char* label, int lostOrGainCoin, int taxCoin, int leftCoin);
    
    /**
     *  @brief 玩家房间内丢失虚拟币时调用（完成一局游戏调用play接口后不必再调用该接口）
     *  @brief reason    虚拟币丢失原因
     *  @param lostCoin  丢失的虚拟币数量
     *  @param leftCoin   剩余的虚拟币数量
     */
    static void lost(const char* roomId, const char* reason, int lostCoin, int leftCoin);
    
    /**
     *  @brief 玩家房间内获得虚拟币时调用（完成一局游戏调用play接口后不必再调用该接口）
     *  @param reason    虚拟币获得原因
     *  @param gainCoin   赢得的虚拟币数量
     *  @param leftCoin  剩余的虚拟币数量
     */
    static void gain(const char* roomId, const char* reason, int gainCoin, int leftCoin);
};

#endif /* defined(__DataEyeSDK__DCCardGame_Interface__) */
