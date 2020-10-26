//
//  RunningData.h
//  LSBluetooth-Library
//
//  Created by Dylan on 16/1/16.
//  Copyright © 2016年 Lifesense. All rights reserved.
//

#import "LSBaseSportData.h"
#import "LSDMConstants.h"

@interface RunningState : NSObject

/** 跑步的开始时间 */
@property(nonatomic,assign)long long startTime;

/** 跑步的结束时间 */
@property(nonatomic,assign)long long endTime;

/** 跑步状态(暂停、开始、停止、重新开始) */
@property(nonatomic,assign)int status;

@property (nonatomic, strong) NSString *dataId;
@end

@interface RunningData : LSBaseSportData
/// 跑步总步数
@property(nonatomic,assign)int totalStep;
/// 运动频率数据
@property(nonatomic,strong)NSArray <RunningState *> *runningStates;
@end
