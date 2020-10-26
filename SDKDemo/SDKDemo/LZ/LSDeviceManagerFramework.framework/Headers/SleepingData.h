//
//  SleepingData.h
//  LSBluetooth-Library
//
//  Created by Dylan on 16/1/23.
//  Copyright © 2016年 Lifesense. All rights reserved.
//

#import "BraceletReceiveData.h"

@interface SleepingData : BraceletReceiveData

/// 原始数据唯一ID uuid
@property (nonatomic, copy) NSString *id;
/// 设备剩余多少条数据
@property(nonatomic,assign)int restCount;
/// 每次测量的时间偏移单位
@property(nonatomic,assign)int utcoffset;
/// 睡眠状态数据列表
@property(nonatomic,strong)NSArray<NSNumber*>*statusList;
/// 原始数据
@property (nonatomic, strong)NSData *sourceData;
/// 当前数据条数
@property(nonatomic,assign)NSInteger currentCount;
/// 测量时间
@property (nonatomic, copy) NSNumber *measurementTime;
/// 创建时间
@property (nonatomic, copy) NSNumber *createTime;
@end
