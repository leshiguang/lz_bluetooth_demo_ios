//
//  ScalesReceiveDataDelegate.h
//  LSDeviceManagerFrameworkTests
//
//  Created by wm on 2020/9/17.
//  Copyright © 2020 Wenzheng Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WeightData.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ScalesReceiveDataDelegate <NSObject>

/// 接收体重数据
/// @param weightData model
- (void)onReceiveScalesWeightData:(WeightData *)weightData;

/// wifi扫描结果回调
/// @param ssidNameAry model
- (void)onReceiveSaclesSsidName:(LSScaleWifiModel *)wifiMode;

/// 接收wifi连接状态回调
/// @param state 0成功 1失败
- (void)onReceiveScalesWifiConnectState:(NSInteger *)state;

@end

NS_ASSUME_NONNULL_END
