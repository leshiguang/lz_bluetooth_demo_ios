//
//  LSDeviceManager+Connect.h
//  LSDeviceManagerFrameworkTests
//
//  Created by alex.wu on 2019/9/9.
//  Copyright © 2019 Wenzheng Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSDeviceManager.h"
NS_ASSUME_NONNULL_BEGIN

@interface LSDeviceManager(Connect)<LSBluetoothStateChangeDelegate>

/**
 *  连接设备
 *
 *  @param deviceInfo 设备信息
 */
- (void)connectDeviceWithDeviceInfo:(Device *)deviceInfo;

/**
 *  断开设备
 *
 *  @param deviceInfo 设备信息
 */
- (void)disConnectWithDeviceInfo:(NSString *)broadcastId;


/**
 *  检测蓝牙是否打开
 */
- (void)isBleEnableCompletion:(void(^)(BOOL isOpenFlags))completion;

- (BOOL)isBluetoothEnabled;

/// 检测蓝牙设备连接状态
/// @param broadcastId 设备广播id
- (BOOL)checkDeviceConnectionStateWithBroadcastId:(NSString *)broadcastId;

/// 开启数据同步
- (BOOL)startDataReceiveService;

/// 结束数据同步
-(BOOL)stopDeviceManger;

-(void)connectAllDevevices;

@end

NS_ASSUME_NONNULL_END
