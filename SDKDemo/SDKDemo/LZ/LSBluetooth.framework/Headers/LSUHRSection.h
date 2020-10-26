//
//  LSUHRSection.h
//  LSBluetooth-Library
//
//  Created by lifesense－mac on 16/8/3.
//  Copyright © 2016年 Lifesense. All rights reserved.
//

#import "LSUBaseModel.h"

@interface LSUHRSection : LSUBaseModel

@property (nonatomic, assign) long long utc;
/**
 * 心率区间I 累计时间，单位：2秒
 * 每个单位值代表2s，如：30表示心率区间I累计时间是60s
 */
@property (nonatomic, assign) NSUInteger hrSectionTime1;

/**
 * 心率区间II 累计时间，单位：2秒
 * 每个单位值代表2s，如：30表示心率区间I累计时间是60s
 */
@property (nonatomic, assign) NSUInteger hrSectionTime2;

/**
 * 心率区间III 累计时间，单位：2秒
 * 每个单位值代表2s，如：30表示心率区间I累计时间是60s
 */
@property (nonatomic, assign) NSUInteger hrSectionTime3;


@end
