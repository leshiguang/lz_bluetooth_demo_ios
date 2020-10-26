//
//  LSUSwimData.h
//  LSBluetooth-Library
//
//  Created by lifesense on 16/1/17.
//  Copyright © 2016年 Lifesense. All rights reserved.
//

#import "LSUBaseModel.h"

@interface LSUSwimData : LSUBaseModel

/**
 *  运动模式
 */
@property(nonatomic,assign) LSSportModeType sportMode;

/**
 *  运动子模式
 */
@property (nonatomic,assign) LSSwimSubModeType swimSubMode;

/**
 *  开始时间
 */
@property (nonatomic, assign) long long startUTC;

/**
 *  结束时间
 */
@property (nonatomic, assign) long long endUTC;

/**
 *  游泳时长
 */
@property (nonatomic, assign) int duration;

/**
 *  圈数
 */
@property (nonatomic, assign) int laps;

/**
 *  游泳总消耗卡路里 (单位:0.1 Kcal)
 */
@property (nonatomic, assign)  double calories;

@end
