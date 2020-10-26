//
//  HRSectionStatisticData.h
//  LSWearable
//
//  Created by lifesense－mac on 16/8/29.
//  Copyright © 2016年 lifesense. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSBaseSportData.h"

@interface HRSectionStatisticData : LSBaseSportData

/**
 * 心率区间I 累计时间，单位：秒
 */
@property (nonatomic, assign) NSUInteger hrSectionTime1;

/**
 * 心率区间II 累计时间，单位：秒
 */
@property (nonatomic, assign) NSUInteger hrSectionTime2;

/**
 * 心率区间III 累计时间，单位：秒
 */
@property (nonatomic, assign) NSUInteger hrSectionTime3;

@end
