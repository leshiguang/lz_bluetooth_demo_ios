//
//  AlarmClockCfg.h
//  LSBluetooth-Library
//
//  Created by Dylan on 16/1/16.
//  Copyright © 2016年 Lifesense. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef NS_ENUM(NSUInteger, LSEClockType) {
       LSGeneralClock =0,
       LSMorningClock =1
};



@interface AlarmClockCfg : NSObject

/// 事件提醒序号
@property (nonatomic, assign) int index;
/// 是否打开闹钟
@property(nonatomic,assign) BOOL enable;
/// 重复时间
@property(nonatomic,copy) NSString *weeks;
/// 闹钟开始时间（时）
@property(nonatomic,assign) int startHour;
/// 闹钟开始时间（分）
@property(nonatomic,assign) int startMin;
/// 震动时间
@property(nonatomic,assign) int shockTime;
/// 闹钟名字
@property(nonatomic, copy) NSString *label;
/// 设置闹铃只响一次
@property(nonatomic,assign)long long ringTime;
/// 闹钟uuid
@property (nonatomic ,strong) NSString *clockUuid;
/// 闹钟类型
@property (nonatomic ,assign) LSEClockType clockType;

-(NSString *)uuidString;

@end
