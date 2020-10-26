//
//  LSDSportHRRemind.h
//  LSBluetooth-Library
//
//  Created by lshenrong on 17/3/8.
//  Copyright © 2017年 Lifesense. All rights reserved.
//

#import "LSDBaseModel.h"

@interface LSDSportHRRemind : LSDBaseModel
/** 心率上限*/
@property (nonatomic ,assign) NSInteger heartRateMax;
/** 心率下限*/
@property (nonatomic ,assign) NSInteger heartRateMin;
/** 心率提醒开关*/
@property (nonatomic ,assign) BOOL isOpen;
@end
