//
//  LSEScaleTargetCfg.h
//  LSWearable
//
//  Created by lshenrong on 17/3/9.
//  Copyright © 2017年 lifesense. All rights reserved.
//

#import <Foundation/Foundation.h>//目标类型
typedef NS_ENUM(NSInteger,LSETargetType)
{
    LSEWeightType = 1,
    LSEOther
};


@interface LSEScaleTargetCfg : NSObject
/** 用户号*/
@property (nonatomic ,assign) int userNumber;
/** 目标类型*/
@property (nonatomic ,assign) LSETargetType targetType;
/** 目标体重值*/
@property (nonatomic ,assign) double targetWeight;
@end
