//
//  LSDeviceManager+WifiConfig.h
//  LSDeviceManagerFrameworkTests
//
//  Created by alex.wu on 2019/9/9.
//  Copyright © 2019 Wenzheng Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSDeviceManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface LSDeviceManager(WifiConfig)<LSWifiConfigDelegate>

/**
 *  配置wifi设备密码
 *
 *  @param deviceId   设备id
 *  @param ssid       wifi名称
 *  @param passWord   密码
 *  @param completion 回调
 */
- (void)configWifiDevice:(NSString *)deviceId ssid:(NSString *)ssid passWord:(NSString *)passWord Completion:(void(^)(AirKissCode code, LSEWifiConfigType type, NSUInteger time))completion;

/**
 *  配置wifi设备密码(使用供应商的SDK，S3,S5，S7使用这个)
 *
 *  @param deviceId   设备id
 *  @param ssid       wifi名称
 *  @param passWord   密码
 *  @param completion
 */
//-(void)configWifiWithManufDevice:(NSString *)deviceId ssid:(NSString *)ssid passWord:(NSString *)passWord Completion:(void(^)(AirKissCode code))completion;

/**
 *  中断wifi设备密码配置
 */
- (void)interruptConfigWifiDevice;

/**
 *  获取WiFi配置状态
 *
 *  @param deviceId 设备Id
 *  @param completion 回调
 */
- (void)getDevWiFiStatusWithDeviceId:(NSString *)deviceId Completion:(void(^)(WiFiCfg *cfg))completion;


@end

NS_ASSUME_NONNULL_END
