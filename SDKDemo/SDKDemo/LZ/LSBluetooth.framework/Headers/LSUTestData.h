//
//  LSUTestData.h
//  LSBluetooth-Library
//
//  Created by Xwei on 2017/11/29.
//  Copyright © 2017年 Lifesense. All rights reserved.
//

#import "LSUBaseModel.h"
#import "LSConst.h"


@interface LSUTestDataInfo : NSObject
/*
 * G-Sensor
 */
@property(nonatomic, assign) NSUInteger gsensor;
/*
* PPG
*/
@property(nonatomic, assign) NSUInteger ppg;
/*
* heartrate
*/
@property(nonatomic, assign) NSUInteger heartrate;

@end

@interface LSUTestData : LSUBaseModel

/*
 * 运动模式
 */
@property(nonatomic, assign) LSSportModeType sportModel;
/*
 * flag
 */
@property(nonatomic, assign) NSUInteger flag;
/**
 * start time
 */
@property(nonatomic, assign) NSUInteger startTime;
/*
 * 采样频率
 */
@property(nonatomic, assign) NSUInteger sampleRate;

/*
 * 测试数据列表
 */
@property(nonatomic, readonly) NSArray<LSUTestDataInfo *> *testDatas;

@end
