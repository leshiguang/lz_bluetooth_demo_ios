//
//  LSDSpeedModel.h
//  LSBluetooth-Library
//
//  Created by apple on 2017/6/23.
//  Copyright © 2017年 Lifesense. All rights reserved.
//

#import "LSDBaseModel.h"

@interface LSDSpeedModel : LSDBaseModel

//精确到:秒
@property (nonatomic ,assign) NSUInteger speedValue;

//单位:米
@property (nonatomic ,assign) NSUInteger distance;

@end
