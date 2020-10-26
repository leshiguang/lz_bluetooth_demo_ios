//
//  LSDeviceManager+Heartrate.h
//  LSDeviceManagerFrameworkTests
//
//  Created by alex.wu on 2019/9/10.
//  Copyright © 2019 Wenzheng Zhang. All rights reserved.
//

#import "LSDeviceManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface LSDeviceManager (Heartrate)<LSBleDataReceiveDelegate>


/// 开启获取实时心率
/// @param device 设备信息
/// @param completeHandler 开启实时心率结果状态，查看枚举LSRealTimeResultStatus
- (void)enableRealTimeHeartRateAcquisition:(Device *)device completeHandler:(RealTimeHRStatusBlock)completeHandler;


/// 关闭获取实时心率
/// @param device 设备信息
/// @param completeHandler 关闭实时心率结果状态，查看枚举LSRealTimeResultStatus
- (void)disableRealTimeHeartRateAcquisition:(Device *)device completeHandler:(RealTimeHRStatusBlock)completeHandler;

@end

NS_ASSUME_NONNULL_END
