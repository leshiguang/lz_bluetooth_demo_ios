//
//  LSUSyncMeasureData.h
//  LSBluetooth-Library
//
//  Created by lshenrong on 17/3/3.
//  Copyright © 2017年 Lifesense. All rights reserved.
//

#import "LSUBaseModel.h"
#import "LSConst.h"

@interface LSUSyncMeasureData : LSUBaseModel

// 传输完本数据包后设备中的剩余数据条目。
@property (nonatomic, assign) NSUInteger restCount;

// 单位
@property (nonatomic, assign) LSWeightUnit unit;

// 数据包中包含有哪些数据
@property (nonatomic, assign) LSMeasureDataType type;

// 体重，单位为0.010kg,可自行根据unit单位来转换
@property (nonatomic, assign) float weight;

// UserNumber
@property (nonatomic, assign) NSUInteger userNumber;

// UTC
@property (nonatomic, assign) NSUInteger utc;

// timezone
@property (nonatomic, assign) NSUInteger timeZone;

// date
@property (nonatomic, assign) NSDate *date;

// bmi,单位:0.1
@property (nonatomic, assign) float bmi;

// bfp,单位:0.1
@property (nonatomic, assign) float bfp;

// bm
@property (nonatomic, assign) NSUInteger bm;

// mp,单位:0.1
@property (nonatomic, assign) float mp;

// mm,单位:0.010kg
@property (nonatomic, assign) float mm;

// ffm,单位:0.010kg
@property (nonatomic, assign) float ffm;

// slm,单位:0.010kg
@property (nonatomic, assign) float slm;

// bwm,单位:0.010kg
@property (nonatomic, assign) float bwm;

// imp,单位:Ω
@property (nonatomic, assign) float imp;

@end
