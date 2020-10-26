//
//  HeartRateData.h
//  LSBluetooth-Library
//
//  Created by Dylan on 16/1/23.
//  Copyright © 2016年 Lifesense. All rights reserved.
//

#import "BraceletReceiveData.h"

@interface HeartRateData : BraceletReceiveData

/// 测量开始时间
@property (nonatomic, copy) NSNumber *measurementDate;

/// utc偏移量
@property (nonatomic, copy) NSNumber *utcoffset;

/// 心率数据列表
@property(nonatomic,strong)NSArray <NSNumber *>*heartRateList;

/// 原始数据
@property (nonatomic, strong)NSData *srcData;

@end
