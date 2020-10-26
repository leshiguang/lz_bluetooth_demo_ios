//
//  LSURideData.h
//  LSBluetooth-Library
//
//  Created by lifesense on 2017/11/6.
//  Copyright © 2017年 Lifesense. All rights reserved.
//

#import "LSUBaseModel.h"
#import "LSConst.h"
#import "LSSportFreqInfo.h"

@interface LSURideData : LSUBaseModel

/**
 *  运动模式
 */
@property(nonatomic,assign) LSSportModeType sportMode;

/**
 *  运动子模式
 */
@property (nonatomic,assign) LSSportBallSubModeType sportSubMode;

/**
 *  运动时间(从运动开始到运动结束，不包括暂停的运动时间)
 */
@property (nonatomic, assign)  int time;

/**
 *  运动总消耗卡路里
 */
@property (nonatomic, assign)  double calories;

/**
 *  运动最大心率
 */
@property (nonatomic, assign)  int maxHR;

/**
 *  运动平均心率
 */
@property (nonatomic, assign)  int avgHR;

/**
 *  运动最大速度
 */
@property (nonatomic, assign)  float maxSpeed;

/**
 *  运动平均速度
 */
@property (nonatomic, assign)  float avgSpeed;

/**
 *  运动距离
 */
@property (nonatomic, assign)  NSUInteger distance;

/**
 *  预留字段flags启用
 */
@property (nonatomic ,assign) NSInteger flags;

/**
 *  获取运动频率信息(只读)
 */
@property (nonatomic, readonly)  NSArray<LSSportFreqInfo *> *sportFreqList;

@end
