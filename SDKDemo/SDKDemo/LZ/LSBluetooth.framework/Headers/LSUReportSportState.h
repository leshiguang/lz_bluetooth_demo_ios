//
//  LSDSportState.h
//  LSBluetooth-Library
//
//  Created by lifesense on 16/11/2.
//  Copyright © 2016年 Lifesense. All rights reserved.
//

#import "LSUBaseModel.h"
#import "model.h"
#import "LSConst.h"

@interface LSUReportSportState : LSUBaseModel

/**
 *  上报类型
 0x00：预留
 0x01：App申请发起运动
 */
@property (nonatomic,assign) int reportType;


// 运动类型
@property (nonatomic, assign) LSSportModeType type;

/**
 *  状态
 0x00：手环同意开启运动
 0x01：手环状态不对/忙
 其他：保留给其他错误原因
 */
@property (nonatomic,assign) int state;
@end
