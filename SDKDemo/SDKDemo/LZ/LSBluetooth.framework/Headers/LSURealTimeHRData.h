//
//  LSURealTimeHRData.h
//  LSBluetooth-Library
//
//  Created by apple on 2017/10/17.
//  Copyright © 2017年 Lifesense. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSConst.h"
@interface LSURealTimeHRData : NSObject

/**
 *  实时心率值
 */
@property (nonatomic, strong) NSNumber *hrValue;

/**
 *  心率传感器接触状态
 */
@property (nonatomic, assign) LSSensorContactStatus status;
@end
