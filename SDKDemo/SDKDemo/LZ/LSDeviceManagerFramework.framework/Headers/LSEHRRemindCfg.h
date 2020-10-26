//
//  LSEHeartRateRemindCfg.h
//  LSWearable
//
//  Created by lshenrong on 17/3/8.
//  Copyright © 2017年 lifesense. All rights reserved.
//  心率预警设置

#import <Foundation/Foundation.h>

@interface LSEHRRemindCfg : NSObject

/// 心率上限
@property (nonatomic ,assign) NSInteger heartRateMax;
/// 心率下限
@property (nonatomic ,assign) NSInteger heartRateMin;
/// 心率提醒开关
@property (nonatomic ,assign) BOOL isOpen;

@end
