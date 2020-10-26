//
//  LSDeviceBleExceptionDelegate.h
//  LSDeviceManager
//
//  Created by apple on 2017/10/19.
//  Copyright © 2017年 Wenzheng Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSBleExceptionRecord.h"

@protocol LSDeviceBleExceptionDelegate <NSObject>

- (void)onBluetoothExceptionRecord:(LSBleExceptionRecord *)model;

@end
