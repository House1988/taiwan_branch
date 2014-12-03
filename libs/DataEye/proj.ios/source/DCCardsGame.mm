//
//  DCCardGame_Interface.mm
//  DataEyeSDK
//
//  Created by HuiTong on 13-11-11.
//  Copyright (c) 2013年 HuiTong. All rights reserved.
//

#include "DCCardsGame.h"
#include "DECardsGame.h"

void DCCardsGame::play(const char* roomId, const char* label, int lostOrGainCoin, int taxCoin, int leftCoin)
{
    NSString* objcRoomId = [NSString stringWithCString:roomId encoding:NSUTF8StringEncoding];
    NSString* objcLabel = [NSString stringWithCString:label encoding:NSUTF8StringEncoding];
    
    [DECardsGame play:objcRoomId label:objcLabel lostOrGainCoin:lostOrGainCoin taxCoin:taxCoin leftCoin:leftCoin];
}

void DCCardsGame::lost(const char* roomId, const char* reason, int lostCoin, int leftCoin)
{
    NSString* objcRoomId = [NSString stringWithCString:roomId encoding:NSUTF8StringEncoding];
    NSString* objcReason = [NSString stringWithCString:reason encoding:NSUTF8StringEncoding];
    
    [DECardsGame lost:objcRoomId reason:objcReason lostCoin:lostCoin leftCoin:leftCoin];
}

void DCCardsGame::gain(const char* roomId, const char* reason, int gainCoin, int leftCoin)
{
    NSString* objcRoomId = [NSString stringWithCString:roomId encoding:NSUTF8StringEncoding];
    NSString* objcReason = [NSString stringWithCString:reason encoding:NSUTF8StringEncoding];
    
    [DECardsGame gain:objcRoomId reason:objcReason gainCoin:gainCoin leftCoin:leftCoin];
}