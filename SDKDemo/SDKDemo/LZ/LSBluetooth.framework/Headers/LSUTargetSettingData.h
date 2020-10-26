//
//  LSUTargetSettingData.h
//  LSBluetooth-Library
//
//  Created by lshenrong on 17/3/3.
//  Copyright © 2017年 Lifesense. All rights reserved.
//

#import "LSUBaseModel.h"

@interface LSUTargetSettingData : LSUBaseModel
/** 用户号*/
@property (nonatomic ,assign) int userNumber;
/** 目标类型*/
@property (nonatomic ,assign) LSTargetType targetType;
/** 目标体重值*/
@property (nonatomic ,assign) double targetValue;


@end
