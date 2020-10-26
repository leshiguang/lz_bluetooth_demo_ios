//
//  WalkingData.h
//  LSBluetooth-Library
//
//  Created by Dylan on 16/1/16.
//  Copyright © 2016年 Lifesense. All rights reserved.
//

#import "BraceletReceiveData.h"

@interface WalkingData : BraceletReceiveData

/// 步数
@property (nonatomic, copy) NSNumber *step;
/// 卡路里
@property (nonatomic, copy) NSNumber *calories;
/// 里程
@property (nonatomic, copy) NSNumber *distance;
/// 数据来源
@property (nonatomic, copy) NSNumber *dataSource;
/// 请求上传时间 可以为null
@property (nonatomic, copy) NSNumber *requestTime;
/// 测量时间
@property (nonatomic, copy) NSNumber *measurementTime;



/// 运动量
//@property (nonatomic, copy) NSNumber *examount;
/// 运动时间
//@property(nonatomic,assign)int exerciseTime;
/// 运动强度等级
//@property (nonatomic, copy) NSNumber *sportLevel;
/// 电压
//@property (nonatomic, copy) NSNumber *batteryVoltage;



@end
