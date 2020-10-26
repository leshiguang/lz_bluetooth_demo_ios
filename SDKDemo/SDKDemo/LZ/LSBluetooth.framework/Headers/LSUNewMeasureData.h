//
//  LSUNewMeasureData.h
//  LSBluetooth-Library
//
//  Created by Xwei on 2017/11/28.
//  Copyright © 2017年 Lifesense. All rights reserved.
//

#import "LSUBaseModel.h"

/*
 * flag 字段解析转换
 */
typedef NS_OPTIONS(NSUInteger, LSMeasureDataFlag) {
    LSMeasureDataFlagNoGsensor = 1, // 没有Gsensor 数据
    LSMeasureDataFlag1ByteGsensor = (1<<1), // Gsensor 1 byte
    LSMeasureDataFlag2ByteGsensor = (1<<2),// Gsensor 2 byte
    LSMeasureDataFlag3ByteGsensor = (1<<3),// Gsensor 3 byte
    LSMeasureDataFlagNoHeartrate = (1<<4),// 没有Heartrate 数据
    LSMeasureDataFlag1ByteHeartrate = (1<<5),// Heartrate 1 byte
    LSMeasureDataFlag2ByteHeartrate = (1<<6),// Heartrate 2 byte
    LSMeasureDataFlag3ByteHeartrate = (1<<7),// Heartrate 3 byte
    LSMeasureDataFlagNoStep = (1<<8),// 没有step 数据
    LSMeasureDataFlag1ByteStep = (1<<9),// step 1 byte
    LSMeasureDataFlag2ByteStep = (1<<10),// step 2 byte
    LSMeasureDataFlag3ByteStep = (1<<11),// step 3 byte
};

@interface LSNewMeasureDataInfo : NSObject

// G-Sensor
@property(nonatomic, assign) NSUInteger x;

@property(nonatomic, assign) NSUInteger y;

@property(nonatomic, assign) NSUInteger z;

// 心率数据
@property(nonatomic, assign) NSUInteger heartrate;

// 步数数据
@property(nonatomic, assign) NSUInteger step;

@end

@interface LSUNewMeasureData : LSUBaseModel

/*
 * flag
 */
@property(nonatomic, assign) LSMeasureDataFlag dataFlag;
/**
 * 第一笔数据测量时间
 */
@property(nonatomic, assign) NSUInteger firstTime;
/**
 * 每组数据测量时间的间隔
 */
@property(nonatomic, assign) NSUInteger offsetTime;
/*
 * 新的测量数据
 */
@property(nonatomic, readonly) NSArray<LSNewMeasureDataInfo *> *measureDatas;

@end
