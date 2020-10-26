//
//  BraceletSyncData.h
//  LSDeviceManagerFrameworkTests
//
//  Created by wm on 2020/9/17.
//  Copyright © 2020 Wenzheng Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WalkingData.h"
#import "SleepingData.h"
#import "HeartRateData.h"
#import "SportHeartRateData.h"
#import "LSBaseSportData.h"
#import "RunningCaloriesData.h"

NS_ASSUME_NONNULL_BEGIN

@interface LSBraceletSyncDataManager : NSObject

+ (instancetype)shareInstance;

/// 同步手环步数数据
/// @param walkingDatas models
- (void)syncBindStep:(NSArray <WalkingData *> *)walkingDatas;

/// 同步睡眠数据
/// @param sleepingDatas models
- (void)syncSleepData:(NSArray <SleepingData *> *)sleepingDatas;

/// 同步常规心率数据
/// @param heartRateDatas models
- (void)syncHeartRateData:(NSArray <HeartRateData *> *)heartRateDatas;

/// 同步运动心率数据
/// @param sportHeartRateDatas models
- (void)syncSportHeartRateData:(NSArray <SportHeartRateData *> *)sportHeartRateDatas;

/// 同步有氧运动数据
/// @param oxSportDatas models
- (void)syncOxSportData:(NSArray <LSBaseSportData *> *)oxSportDatas;

/// 同步运动数据
/// @param sportDatas models
- (void)syncSportData:(NSArray <LSBaseSportData *> *)sportDatas;

/// 同步运动卡路里数据
/// @param calories models
- (void)syncRunCaloriesData:(NSArray <RunningCaloriesData *> *)calories;

@end

NS_ASSUME_NONNULL_END
