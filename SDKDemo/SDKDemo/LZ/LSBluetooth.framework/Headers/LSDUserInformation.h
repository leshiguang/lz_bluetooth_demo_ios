//
//  LSDUserInformation.h
//  LSBluetooth-Library
//
//  Created by lshenrong on 17/3/1.
//  Copyright © 2017年 Lifesense. All rights reserved.
//

#import "LSDBaseModel.h"
#import "LSConst.h"

@interface LSDUserInformation : LSDBaseModel

/** 用户号 */
@property (nonatomic ,assign) NSUInteger userNumber;
/** 性别 */
@property (nonatomic ,assign) LSGender gender;
/** 年龄 */
@property (nonatomic ,assign) NSUInteger age;
/** 身高cm */
@property (nonatomic ,assign) NSUInteger height;
/** 类型 */
@property (nonatomic ,assign) LSPeopleType peopleType;
/** 运动水平 */
@property (nonatomic ,assign) NSUInteger sportLevel;
/** 体重 */
@property (nonatomic ,assign) double weight;




@end
