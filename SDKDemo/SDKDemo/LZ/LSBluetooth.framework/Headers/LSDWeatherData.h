//
//  LSDWeatherData.h
//  LSBluetooth-Library
//
//  Created by lifesense on 17/1/4.
//  Copyright © 2017年 Lifesense. All rights reserved.
//

#import "LSDBaseModel.h"
#import "LSConst.h"
@interface LSFutureWeatherModel : NSObject

/**
 *  天气气象类型
 */
@property (nonatomic, assign) LSWeatherType type;

/**
 *  温度范围1
 */
@property (nonatomic, assign) int temperatureOne;

/**
 *  温度范围2
 */
@property (nonatomic, assign) int temperatureTwo;

/**
 *  空气质量指数AQI
 */
@property (nonatomic, assign) int AQI;
@end
@interface LSDWeatherData : LSDBaseModel

/**
 *  天气更新的UTC(天气获取时刻的时间，不是手机系统的时间)
 */
@property (nonatomic, assign) long long utc;

/**
 *  查看已经添加的未来天气信息对象(只读)
 */
@property (nonatomic, readonly) NSArray<LSFutureWeatherModel*> *weatherModels;

/**
 *  添加天气未来天气信息
 *
 *  @param model LSFutureWeatherModel 未来天气信息对象
 */
- (void)addWeatherData:(LSFutureWeatherModel *)model;
@end
