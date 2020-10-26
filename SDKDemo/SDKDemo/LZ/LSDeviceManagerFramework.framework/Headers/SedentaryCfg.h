//
//  SedentaryCfg.h
//  LSBluetooth-Library
//
//  Created by Dylan on 16/1/16.
//  Copyright © 2016年 Lifesense. All rights reserved.
//  久坐提醒

#import <Foundation/Foundation.h>

@interface SedentaryCfg : NSObject

/// 是否打开闹钟
@property(nonatomic,assign)BOOL enable;
/// 闹钟开始时间（时）
@property(nonatomic,assign)int startHour;
/// 闹钟开始时间（分）
@property(nonatomic,assign)int startMin;
/// 闹钟结束时间（时）
@property(nonatomic,assign)int endHour;
/// 闹钟结束时间（分）
@property(nonatomic,assign)int endMin;
/// 久坐提醒的频次 (min)
@property(nonatomic,assign)int sedentaryTime;
/// 重复时间
@property(nonatomic,copy) NSString *weeks;

@end
