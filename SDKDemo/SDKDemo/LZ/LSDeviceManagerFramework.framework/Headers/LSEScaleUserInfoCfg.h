//
//  LSEScaleUserInfoCfg.h
//  LSDeviceManagerFrameworkTests
//
//  Created by boluobill on 2018/8/8.
//  Copyright © 2018 Wenzheng Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LSEScaleUserInfoCfg : NSObject

/** 用户号 */
@property (nonatomic ,assign) NSUInteger userNumber;
/** 性别 */
@property (nonatomic ,assign) int gender;
/** 年龄 */
@property (nonatomic ,assign) NSUInteger age;
/** 身高cm */
@property (nonatomic ,assign) NSUInteger height;
/** 类型 */
@property (nonatomic ,assign) int peopleType;
/** 运动水平 */
@property (nonatomic ,assign) NSUInteger sportLevel;
/** 体重 */
@property (nonatomic ,assign) double weight;


@end
