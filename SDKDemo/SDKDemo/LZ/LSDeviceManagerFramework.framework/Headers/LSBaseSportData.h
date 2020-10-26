//
//  LSBaseSportData.h
//  LSDeviceManagerFramework
//
//  Created by lifesense on 2017/11/15.
//  Copyright © 2017年 Wenzheng Zhang. All rights reserved.
//

#import "BraceletReceiveData.h"

@interface LSBaseSportData : BraceletReceiveData

/// 上传服务器锻炼类型 (1,"跑步"),(2,"健走"),(3,"骑行"),(4,"游泳"),(5,"健身"),(6,"篮球"),(7,"足球"),(8,"羽毛球"),(9,"排球"),(10,"乒乓球"),(11,"瑜伽"),(12,"电竞"),(15,"室内跑"),(16,"椭圆机"),(19,"健身操"),(20,"打太极"),(21,"力量训练")
@property (nonatomic, assign) NSInteger exerciseType;

/// 子运动模式
@property(nonatomic, assign) int sportSubMode;

/// 运动模式 (骑行0x03 健身0x05 篮球0x0a 足球0x0b 羽毛0x0c 排球0x0d 乒乓球0x0e 瑜伽0x0f)
@property(nonatomic, assign) int sportMode;

/// 开始时间
@property(nonatomic, copy) NSNumber *startTime;

/// 结束时间
@property(nonatomic, copy) NSNumber *endTime;

/// 运动时间
@property(nonatomic, assign) int exerciseTime;

/// 消耗卡路里
@property(nonatomic, assign) double calories;

/// 最大心率
@property(nonatomic, assign) int maxHeartRate;

/// 平均心率
@property(nonatomic, assign) int avgHeartRate;

/// 平均步频
@property (nonatomic, assign) NSInteger avgSportFrequency;

/// 最大步频
@property (nonatomic, assign) NSInteger maxSportFrequency;

/// 最大速度（km/h）
@property(nonatomic, assign) double maxSpeed;

/// 运动平均速度
@property (nonatomic, assign)  float avgSpeed;

/// 距离
@property (nonatomic, copy) NSNumber *distance;



@end
