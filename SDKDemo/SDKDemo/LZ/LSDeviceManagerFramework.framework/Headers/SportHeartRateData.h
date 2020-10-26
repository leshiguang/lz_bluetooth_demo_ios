//
//  SportHeartRateData.h
//  LSBluetooth-Library
//
//  Created by Dylan on 16/1/23.
//  Copyright © 2016年 Lifesense. All rights reserved.
//

#import "BraceletReceiveData.h"

@interface SportHeartRateData : BraceletReceiveData
/// 偏移量
@property(nonatomic,assign)int utcoffset;
/// 心率数据列表
@property(nonatomic,strong)NSArray <NSNumber *>*heartRates;
/// 原始数据
@property (nonatomic, strong)NSData *sourceData;
/// 当前数据条数
@property(nonatomic,assign)NSInteger currentCount;
/// 测量开始时间
@property (nonatomic,strong) NSNumber *measurementTime;

@end
