//
//  LSUUserData.h
//  LSBluetooth-Library
//
//  Created by lshenrong on 17/3/2.
//  Copyright © 2017年 Lifesense. All rights reserved.
//

#import "LSUBaseModel.h"

@interface LSUUserData : LSUBaseModel
/** 用户号*/
@property (nonatomic ,assign) int userNumber;
/** 性别*/
@property (nonatomic ,assign) LSGender gender;
/** 年龄*/
@property (nonatomic ,assign) int age;
/** 身高 cm */
@property (nonatomic ,assign) NSUInteger height;
/** 类型*/
@property (nonatomic ,assign) LSPeopleType sport;
/** 运动水平*/
@property (nonatomic ,assign) int sportLevel;
/** 体重*/
@property (nonatomic ,assign) double weight;

@end
