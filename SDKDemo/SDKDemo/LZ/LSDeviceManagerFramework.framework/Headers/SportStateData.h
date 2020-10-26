//
//  SportStateData.h
//  LSWearable
//
//  Created by lshenrong on 17/4/6.
//  Copyright © 2017年 lifesense. All rights reserved.
//

#import "BraceletReceiveData.h"


typedef NS_ENUM(NSUInteger,LSEFunctionTestType)
{
    /**
     * 开启GPS功能检测
     */
    LSEFunctionTestTypeGPS = 1,
        
    LSFunctionTestTypeSportState1 = 0x02,
    //    0x02：运动状态,用于手环端结束手机App运动
};


//手环发送运动模式类型
typedef NS_ENUM(NSUInteger,LSESportModeType)
{
    /**
     * 跑步模式
     */
    LSESportModeTypeSportMode = 1 ,
    /**
     * 健走模式
     */
    LSEWalkingModeTypeSportMode,
    /**
     * 骑行模式
     */
    LSECyclingModeTypeSportMode,
    /**
     * 游泳模式
     */
    LSESwimingModeTypeSportMode,
    /**
     * 健身模式
     */
    LSEKeepfitModeTypeSportMode,
    /**
     * 新跑步模式
     */
    LSERunningModeTypeSportMode,
    
    /**
     * 室内跑
     */
    LSEIndoorRunModeTypeSportMode = 0x07,
    
    /**
     * 椭圆机
     */
    LSECycleMactionModeTypeSportMode = 0x08,
    
    /**
     * 有氧运动
     */
    LSEOxSportModeTypeSportMode = 0x09,
    
    /**
     * 篮球
     */
    LSEBasketballModeTypeSportMode = 0x0A,
    /**
     * 足球
     */
    LSEFootballModeTypeSportMode = 0x0B,
    /**
     * 羽毛球
     */
    LSEBadmintonModeTypeSportMode = 0x0C,
    /**
     * 排球
     */
    LSEVolleyballModeTypeSportMode = 0x0D,
    /**
     * 乒乓球
     */
    LSETableTennisModeTypeSportMode = 0x0E,
    /**
     * 瑜伽
     */
    LSEYogaModeTypeSportMode = 0x0F,
    /**
     * 电竞
     */
    LSEEGameModeTypeSportMode = 0x10,
    /**
     * 有氧能力12分钟跑
     */
    LSE12MinutesRunModeTypeSportMode = 0x11,
    /**
     * 有氧能力6分钟跑
     */
    LSE6MinutesRunModeTypeSportMode = 0x12,
    
    
    LSEGymDanceModeTypeSportMode = 0x13,
    
    
    LSETaijiModeTypeSportMode = 0x14,
    
    
};

@interface SportStateData : BraceletReceiveData
/// 功能检测
@property (nonatomic,assign) LSEFunctionTestType functionTest;
/// 开关状态
@property (nonatomic,assign) int state;
// 运动类型，0x00：预留,0x01：跑步,0x02：健走,0x03：骑行,0x04：游泳,0x05：健身
@property (nonatomic, assign) LSESportModeType type;

//@property (nonatomic, assign) BOOL gpsIsEnable;

@end
