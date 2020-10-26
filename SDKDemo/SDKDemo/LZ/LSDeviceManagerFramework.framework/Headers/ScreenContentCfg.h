//
//  ScreenContentCfg.h
//  LSWearable
//
//  Created by lifesense－mac on 16/8/15.
//  Copyright © 2016年 lifesense. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 自定义显示页面类型 (!!!枚举的值 请与sdk保持一致)
 */
#pragma clang diagnostic ignored "-Wdocumentation"
typedef enum : NSUInteger {
    ScreenContentTime,          ///< 时间
    ScreenContentStep,          ///< 步数
    ScreenContentCalorie,       ///< 卡路里
    ScreenContentDistance,      ///< 距离
    ScreenContentHR,            ///< 心率
    ScreenContentRunning,       ///< 跑步
    ScreenContentWalking,       ///< 健走
    ScreenContentCycling,       ///< 骑行
    ScreenContentSwimming,      ///< 游泳
    ScreenContentFitness,       ///< 健身
    ScreenContentMountainClimbing,///< 登山
    ScreenContentDailyData,     ///< 日常数据
    ScreenContentStopwatch,     ///< 秒表
    ScreenContentWeather,        ///< 天气
    ScreenContentBattery,        ///< 电量
    
    //室内跑
    ScreenContentIndoorRun = 0x0f,
    //椭圆机
    ScreenContentCycleMaction = 0x10,
    //有氧运动
    ScreenContentOxSport = 0x11,
    
    // 篮球
    ScreenContentBasketball = 0x12, // 枚举的值必须和对应的 UI列表对应的数值对应 参见0x7E命令
    // 足球
    ScreenContentFootball = 0x13,
    // 羽毛球
    ScreenContentBadminton = 0x14,
    // 排球
    ScreenContentVolleyball = 0x15,
    // 乒乓球
    ScreenContentTableTennis = 0x16,
    // 瑜伽
    ScreenContentYoga = 0x17,
    // 电竞
    ScreenContentESport = 0x18,
    
    ScreenContent12MinutesRunMode = 0x19,
    
    ScreenContent6MinutesRunMode =0x1a,
//    ScreenContentCount,         //<! 不要使用，仅计数用  Xwei delete 2017.11.10
    
    ScreenContentAliPayMode =0x1b,
    
    ScreenContentGymDance = 0x1c,
    
    ScreenContentTaiji = 0x1d,
    
} ScreenContentType;


/// 页面功能开关对象
@interface ScreenContentSwitch : NSObject

/// 类型
@property (nonatomic, assign) ScreenContentType type;
/// 开/关
@property (nonatomic, assign) BOOL state;

@end

/// 自定义显示页面类
@interface ScreenContentCfg : NSObject

/// 自定义页面
@property (nonatomic, strong) NSArray<NSDictionary *> *content;

@end
