//
//  LSDeviceManager+OTA.h
//  LSDeviceManagerFrameworkTests
//
//  Created by alex.wu on 2019/9/9.
//  Copyright © 2019 Wenzheng Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSDeviceManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface LSDeviceManager(OTA)<LSOTADelegate>

/// 取消升级设备(ota)
- (void)cancelUpgradeDevice;

/// 升级设备固件（ota）
/// @param deviceId 设备id
/// @param hexFile 升级包
- (void)upgradeDevice:(NSString *)deviceId hexFile:(NSString *)hexFile;


/// 检测是否有固件版本更新
/// @param model 产品型号
/// @param hardwareVersion 硬件版本
/// @param softwareVersion 软件版本
/// @param deviceid 设备id
/// @param completion 回调
- (void)checkFirmwareModel:(NSString *)model hardwareVersion:(NSString *)hardwareVersion softwareVersion:(NSString *)softwareVersion deviceId:(NSString *)deviceid Completion:(void(^)(int code,NSString *msg,NSDictionary *data))completion;

/**
 设置设备固件版本
 
 @param version 固件版本
 */
- (void)updateDeviceVersion:(NSString *)version device:(Device *)device;


/**
 *  检查是否升级失败
 *
 *  @param deviceId 设备id
 *
 *  @return YES：升级失败，NO:升级成功
 */
- (BOOL)isUpgradeFaildeByDeviceId:(NSString *)deviceId;

/**
 *  @brief 检查是否配对,(仅A045使用)
 *    该接口仅为OTA时使用，其它时候切勿使用，
 *          调用该接口后，将会断开所有设备连接，回调为异步，如果检测不到设备已断开，
 *          该接口将会在30秒到39秒左右触发超时回调。如果不想进入OTA了，要调用@see startDataReceiveService 来重新启动数据接收服务。
 *          如果进去OTA,则直接调用@see upgradeDevice:hexFile: 接口
 *
 *  @param deviceId 设备id
 *  @param block    检查后的回调,isMatch为YES则是已配对，NO为未配对
 */
- (void)checkIsMatchByDeviceId:(NSString *)deviceId block:(LSDMMatchBlock)block;

@end

NS_ASSUME_NONNULL_END
