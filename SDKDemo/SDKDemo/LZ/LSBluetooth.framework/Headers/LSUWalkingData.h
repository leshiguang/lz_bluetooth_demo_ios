//
//  LSUWalkingData.h
//  LSBluetooth-Library
//
//  Created by lifesense on 17/1/6.
//  Copyright © 2017年 Lifesense. All rights reserved.
//

#import "LSUBaseModel.h"
#import "LSConst.h"
@interface LSSwalkingFreqInfo : NSObject

/**
 *  健走状态对应时间UTC
 */
@property (nonatomic, assign) long long utc;
/**
 *  健走状态
 */
@property (nonatomic, assign) LSWalkFreq status;

@end

@interface LSUWalkingData : LSUBaseModel
/**
 *  运动模式
 */
@property(nonatomic,assign) LSSportModeType sportMode;

/**
 *  运动子模式
 */
@property (nonatomic,assign) LSWalkingSubModeType walkingSubMode;

/**
 *  健走时间(从健走开始到健走结束，不包括暂停的健走时间)
 */
@property (nonatomic, assign)  int time;

/**
 *  健走总步数
 */
@property (nonatomic, assign)  int step;

/**
 *  健走总消耗卡路里
 */
@property (nonatomic, assign)  double calories;

/**
 *  健走最大心率
 */
@property (nonatomic, assign)  int maxHR;

/**
 *  健走平均心率
 */
@property (nonatomic, assign)  int avgHR;

/**
 *  健走最大速度
 */
@property (nonatomic, assign)  float maxSpeed;

/**
 *  健走平均速度
 */
@property (nonatomic, assign)  float avgSpeed;

/**
 *  健走距离
 */
@property (nonatomic, assign)  NSUInteger distance;

/**
 *  预留字段flags启用
 */
@property (nonatomic ,assign) NSInteger flags;


/**
 *  健走最大步频
 */
@property (nonatomic, assign) NSInteger maxWalkFrequency;
/**
 *  健走平均步频
 */
@property (nonatomic, assign) NSInteger avgWalkFrequency;

/**
 *  获取健走频率信息(只读)
 */
@property (nonatomic, readonly)  NSArray<LSSwalkingFreqInfo *> *walkFreqList;
@end
