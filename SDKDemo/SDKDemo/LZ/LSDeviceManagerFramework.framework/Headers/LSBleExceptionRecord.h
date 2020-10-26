//
//  LSBleExceptionRecord.h
//  LSDeviceManager
//
//  Created by apple on 2017/10/19.
//  Copyright © 2017年 Wenzheng Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LSBleExceptionRecord : NSObject

/**
 错误码 (小类)
 */
@property (nonatomic, assign) NSUInteger errorCode;

/**
 错误类型(大类)
 */
@property (nonatomic, assign) NSUInteger errorCategoryCode;

/**
 固件版本
 */
@property (nonatomic, copy)  NSString *firmwareVersion;

/**
 设备型号
 */
@property (nonatomic, copy)  NSString *modelNumber;

@end
