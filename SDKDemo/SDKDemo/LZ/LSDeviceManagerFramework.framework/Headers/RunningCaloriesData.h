//
//  RunningCaloriesData.h
//  LSWearable
//
//  Created by lifesense－mac on 16/8/25.
//  Copyright © 2016年 lifesense. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BraceletReceiveData.h"
#import "LSDMConstants.h"

/**
 *  跑步卡路里
 */
@interface RunningCaloriesData : BraceletReceiveData

/// 卡路里数据类型，新或旧，如果是新的，则sportMode和subMode的值有意义。 如果是旧的，则sportMode和subMode无意义，不要使用
@property (nonatomic, assign) LSDMSportCaloriesDataType type;
/// 产生卡路里的运动类型
@property (nonatomic, assign) LSDMSportModeType sportMode;
/// 运动子模式
@property (nonatomic, assign) LSDMSubModeType subMode;
/// utc偏移量
@property (nonatomic, assign) int utcoffset;
/// 卡路里列表
@property (nonatomic, strong) NSArray<NSNumber *> *calorieList;
/// 原始数据
@property (nonatomic, strong)NSData *sourceData;
/// 当前数据条数
@property(nonatomic,assign)NSInteger currentCount;
/// 测量时间
@property (nonatomic, assign) long long *measurementTime;

@end
