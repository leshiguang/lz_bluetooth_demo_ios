//
//  BraceletReceiveDataManager.h
//  LSDeviceManagerFrameworkTests
//
//  Created by wm on 2020/9/16.
//  Copyright © 2020 Wenzheng Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BraceletReceiveDataState : NSObject

//定义数据类型枚举
typedef enum : NSUInteger {
    WalkingDataType,            ///<步数数据
    HeartRateDataType,          ///<日常心率
    SportHeartRateDataType,     ///<运动心率
    SleepingDataType,           ///<睡眠
    UWalkingDataType,           ///<健走
    SportStateDataType,         ///<手环通知手机进入运动模式数据
    SwimmingDataType,           ///<游泳
    RunningDataType,            ///<跑步数据
    LSCyclingDataType,          ///<骑行
    LSYogaDataType,             ///<瑜伽
    LSFitnessDataType,          ///<健身
    LSBasketballDataType,       ///<篮球
    LSFootballDataType,         ///<足球
    LSBadmintonDataType,        ///<羽毛球
    LSVolleyballDataType,       ///<排球
    LSTableTennisDataType,      ///<乒乓球
    ExsportDataType,            ///<电竞
    LSTaiJiDataType,            ///<太极
    IndoorRunSportDataType,     ///<室内跑
    EllipticalTrainerSportDataType, ///<椭圆机
    OxSportDataType,            ///<有氧运动
    GymDanceType,               ///<健身舞
    RunningCaloriesDataType,        ///<步数卡路里数据
} BraceletReceiveDataType;      


/// 数据类型（BraceletReceiveDataType）和 数据model具有映射关系，通过这个方法可以按到对应的类名
/// @param state 运动类型
extern NSString * NSStringFromTransactionState(BraceletReceiveDataType state);

@end

NS_ASSUME_NONNULL_END
