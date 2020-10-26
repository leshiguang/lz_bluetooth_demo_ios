//
//  LSUSportState.h
//  LSBluetooth-Library
//
//  Created by lifesense on 16/11/2.
//  Copyright © 2016年 Lifesense. All rights reserved.
//
#import "LSUBaseModel.h"

@interface LSUSportState : LSUBaseModel
/**
 *  功能检测
 */
@property (nonatomic,assign) LSFunctionTestType functionTest;
/**
 *  开关状态 0x00：开始   0x01：结束
 */
@property (nonatomic,assign) int state;

// 运动类型，0x00：预留,0x01：跑步,0x02：健走,0x03：骑行,0x04：游泳,0x05：健身
@property (nonatomic, assign) int type;

@end
