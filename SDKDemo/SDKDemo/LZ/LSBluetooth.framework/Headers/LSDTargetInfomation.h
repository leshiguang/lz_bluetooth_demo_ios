//
//  LSDTargetInfomation.h
//  LSBluetooth-Library
//
//  Created by lshenrong on 17/3/1.
//  Copyright © 2017年 Lifesense. All rights reserved.
//

#import "LSDBaseModel.h"
#import "LSConst.h"

@interface LSDTargetInfomation : LSDBaseModel
/** 用户号*/
@property (nonatomic ,assign) int userNumber;
/** 目标类型*/
@property (nonatomic ,assign) LSTargetType targetType;
/** 目标体重值*/
@property (nonatomic ,assign) double targetWeight;

@end
