//
//  LSURunningData.h
//  LSBluetooth-Library
//
//  Created by hanfeng.li on 2017/1/16.
//  Copyright © 2017年 Lifesense. All rights reserved.
//

#import "LSUBaseModel.h"

@interface LSRunningStepFreqInfo : NSObject

/**
 *  新跑步状态对应时间UTC
 */
@property (nonatomic, assign) long long utc;
/**
 *  新跑步状态
 */
@property (nonatomic, assign) LSRunningStepStatus status;

@end


@interface LSURunningData : LSUBaseModel

//运动模式
@property (nonatomic, assign) LSSportModeType sportMode;

//运动子模式
@property (nonatomic, assign) LSRunningSubModeType runningSubMode;

//跑步时长
@property (nonatomic, assign) int time;

//跑步总步数
@property (nonatomic, assign) int step;

//跑步消耗卡路里（单位：0.1Kcal）
@property (nonatomic, assign) double calories;

//跑步最大心率
@property (nonatomic, assign) int maxHR;

//跑步平均心率
@property (nonatomic, assign) int avgHR;

//跑步最大速度（0.01Km/h）
@property (nonatomic, assign) float maxSpeed;

//跑步平均速度（0.01Km/h）
@property (nonatomic, assign) float avgSpeed;

//跑步距离
@property (nonatomic, assign) NSUInteger distance;

 //预留字段flags启用
@property (nonatomic ,assign) NSInteger flags;

//跑步最大步频
@property (nonatomic, assign) NSInteger maxRunningFrequency;

//跑步平均步频
@property (nonatomic, assign) NSInteger avgRunningFrequency;

//跑步频率信息
@property (nonatomic, readonly) NSArray<LSRunningStepFreqInfo *> *stepFreqList;

@end



