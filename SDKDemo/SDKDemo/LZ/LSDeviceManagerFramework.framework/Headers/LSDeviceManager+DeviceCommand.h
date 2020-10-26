//
//  LSDeviceManager+DeviceCommand.h
//  LSDeviceManagerFrameworkTests
//
//  Created by alex.wu on 2019/9/10.
//  Copyright © 2019 Wenzheng Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSDeviceManager.h"
NS_ASSUME_NONNULL_BEGIN

/**
 这里处理设备连接时发送给设备的命令
 */
@interface LSDeviceManager(DeviceCommand)

/**
 设置语言
 
 @param deviceId 设备id
 @param code 语言 （en，zh）蓝牙协议文档5.6 语言代码表
 @param completion 回调
 */
- (void)setLanguageSetting:(NSString *)deviceId languageCode:(NSString *)code completion:(Completion)completion;



/**
 *  设置用户信息
 *
 *  @param deviceId 设备id
 *  @param userInfo 用户信息
 *  @param completion 回调
 */
- (void)setUserInfo:(NSString *)deviceId mode:(DeviceUserInfo *)userInfo completion:(Completion)completion;




- (void)updatePedometerUserInfo;


@end

NS_ASSUME_NONNULL_END
