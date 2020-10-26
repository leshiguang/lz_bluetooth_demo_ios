//
//  LSDSettingTime.h
//  LSBluetooth-Library
//
//  Created by lshenrong on 17/3/2.
//  Copyright © 2017年 Lifesense. All rights reserved.
//

#import "LSDBaseModel.h"
#import "LSConst.h"

@interface LSDSettingTime : LSDBaseModel
/** Flag标志*/
@property (nonatomic ,assign) LSTimeFlagType flagType;
/** utc时间*/
@property (nonatomic ,assign) NSUInteger utc;
/** 时区*/
@property (nonatomic ,assign) NSUInteger timeZone;
/** 日期 */
@property (nonatomic ,strong) NSDate *date;

@end
