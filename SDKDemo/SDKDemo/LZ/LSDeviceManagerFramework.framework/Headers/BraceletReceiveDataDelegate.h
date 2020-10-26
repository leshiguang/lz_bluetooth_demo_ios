//
//  BraceletReceiveDataDelegate.h
//  LSDeviceManagerFrameworkTests
//
//  Created by wm on 2020/9/16.
//  Copyright © 2020 Wenzheng Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BraceletReceiveDataState.h"

NS_ASSUME_NONNULL_BEGIN

@protocol BraceletReceiveDataDelegate <NSObject>

/// 手环测量数据
/// @param data 数据model
/// @param type 数据枚举类型
- (void)onReceiveBraceletData:(id)data dataType:(BraceletReceiveDataType)type;

/// 接收实时心率数据
/// @param realTimeHRData 实时心率
/// @param device 设备信息
- (void)onReceiveRealTimeHeartRateData:(LSURealTimeHRData *)realTimeHRData targetDeviceInfo:(LSDeviceInfo *)device;

/// 电量状态有改变时回调
/// @param status 设备状态
- (void)onDeviceStatusChange:(DeviceStatus *)status;


@end

NS_ASSUME_NONNULL_END
