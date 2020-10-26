//
//  LSDSportState.h
//  LSBluetooth-Library
//
//  Created by lifesense on 16/11/2.
//  Copyright © 2016年 Lifesense. All rights reserved.
//

#import "LSDBaseModel.h"
#import "model.h"
@interface LSDSportState : LSDBaseModel
/**
 *  功能检测
 */
@property (nonatomic,assign) LSFunctionTestType functionTest;
/**
 *  开关状态
 0x00：GPS关
 0x01：GPS开 & 尚未定位
 0x03(0000 0011b)：GPS开 & 定位成功
 0x80(1000 0000b)：手机App拒绝运动发起
 */
@property (nonatomic,assign) LSFunctionGPSType state;
@end
