//
//  LSDEncourageTypeModel.h
//  LSBluetooth-Library
//
//  Created by lifesense on 17/1/4.
//  Copyright © 2017年 Lifesense. All rights reserved.
//

#import "LSDBaseModel.h"
#import "LSConst.h"
@interface LSDEncourageTypeModel : LSDBaseModel
@property (nonatomic, assign) BOOL isOpen;
@property (nonatomic, assign) LSEncourageTargetType targetType;
/**
 *  卡路里单位:0.1Kcal  目标距离单位:米
 */
@property (nonatomic, assign) float targetValue;
@end
