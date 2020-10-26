//
//  HeartrateSwitchCfg.h
//  LSWearable
//
//  Created by lifesense－mac on 16/8/12.
//  Copyright © 2016年 lifesense. All rights reserved.
//  连续心率监测

#import <Foundation/Foundation.h>

/**
 智能心率设置类型
 */
typedef enum : NSUInteger {
    HeartrateSwitchTypeClose, ///< 关闭心率监测
    HeartrateSwitchTypePowerSave, ///<<! 省电心率监测
    HeartrateSwitchTypeNotPowerSave, ///<<! 连续心率监测
} HeartrateSwitchType;


/// 智能心率设置
@interface HeartrateSwitchCfg : NSObject

/// 设置类型
@property (nonatomic, assign) HeartrateSwitchType type;

@end
