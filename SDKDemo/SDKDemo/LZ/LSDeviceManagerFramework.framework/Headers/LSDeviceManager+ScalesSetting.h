//
//  LSDeviceManager+ScalesSetting.h
//  LSDeviceManagerFrameworkTests
//
//  Created by wm on 2020/9/23.
//  Copyright © 2020 Wenzheng Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSDeviceManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface LSDeviceManager (ScalesSetting)

/// 查询体重单位
/// @param deviceId deviceId
- (UnitType)getWeightUnit:(NSString *)deviceId;

/// 设置体重单位
/// @param deviceId deviceId
/// @param unitType 体重单位
/// @param completion 回调
-(void)setWeightUnit:(NSString *)deviceId unitType:(UnitType)unitType completion:(Completion)completion;

/// 设置A6体重秤目标
/// @param deviceId 设备ID
/// @param target 体重目标值(单位:0.01kg)
/// @param completion 回调
- (void)setScaleTarget:(NSString *)deviceId target:(double)target completion:(Completion)completion;

/// 获取A6体重秤目标设置
/// @param deviceId deviceId
- (float)getScaleTarget:(NSString *)deviceId;

/// 设置A6体重秤的用户信息
/// @param deviceId 设备id
/// @param userInfo 用户信息
/// @param completion 回调
- (void)setScaleUserInfo:(NSString *)deviceId userInfo:(LSEScaleUserInfoCfg *)userInfo completion:(Completion)completion;

/// 扫描wifi
/// @param deviceId 设备id
- (void)scanWifiWith:(NSString *)deviceId;

/// 连接wifi
/// @param bssid bssid
/// @param pwd wifi密码
/// @param deviceId 设备id
- (void)connectWifi:(NSString *)bssid password:(NSString *)pwd deviceId:(NSString *)deviceId;

@end

NS_ASSUME_NONNULL_END
