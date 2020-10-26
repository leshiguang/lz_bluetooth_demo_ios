//
//  LSDeviceManager+Device.h
//  LSDeviceManagerFrameworkTests
//
//  Created by alex.wu on 2019/9/9.
//  Copyright © 2019 Wenzheng Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSDeviceManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface LSDeviceManager(Device)<LSBleDataReceiveDelegate>


/**
 处理多设备时被踢时的数据
 
 @param deviceUserExts 用户关系
 */
- (void)saveActiveDeviceInfos:(NSArray*)deviceUserExts;


/**
 获取厂商信息
 @param completion 回调
 @param manufacturerId 厂商 id
 */
- (void)getManufacturerInformationForManufacturerId:(NSString *)manufacturerId completion:(LSEManufacturerInfoBlock)completion;
/**
 *  根据二维码获取设备信息
 *
 *  @param qrcode     二维码
 *  @param completion 回调
 */
- (void)getDeviceInfo:(NSString *)qrcode Completion:(void(^)(int code,NSString *msg,Device *deviceInfo))completion;


- (void)getDeviceInfoWithSN:(NSString *)sn Completion:(void (^)(int, NSString *, Device *))completion;


- (void)dealActiveDeviceData:(NSArray *)data;



//delete
- (void)deleteUserWithUserId:(NSString *)userId deviceId:(NSString *)deviceId;


/**
 *  设置活跃设备
 */
- (void)setActiveDevice:(NSString *)deviceId completion:(void(^)(int code, NSString *msg))completion;

- (void)resetActiveDevice;

- (NSArray *)getAllUserIds;

-(NSArray <DeviceUser*>*)allDeviceUsers;

- (NSArray<DeviceUser *> *)getAllDeviceUserWithUserId:(NSString *)userId;

- (Device *)getActivityDeviceWithUserId:(NSString *)userId;


- (Device *)getActivityDevice;


-(NSArray *)getCurrentCountBindDeviceUsers:(NSArray *)devices;

/**
 *  获取设备信息
 */
-(Device *)getDeviceInfo:(NSString *)deviceId;

/**
 *  获取指定设备的所有绑定关系
 *
 *  @param deviceId   设备id
 *  @param completion 回调
 */
- (void)getDeviceUsersWithDeviceId:(NSString *)deviceId  Completion:(void(^)(int code,NSString *msg,NSArray <DeviceUser *>*deviceList))completion;

/**
 *  根据userId获取用户信息
 */
-(DeviceUser *)getDeviceUserWithUserId:(NSNumber *)userId;

-(LSDeviceInfo *)getDeviceInfoWithDeviceId:(NSString *)deviceId;


/// 获取已绑定的设备列表
/// @param userId 用户id
/// @param completion 已绑定的设备列表回调
- (void)getBoundDevices:(NSNumber *)userId Completion:(void(^)(int code,NSString *msg,NSArray <Device *>*deviceList))completion;

/**
 *  获取已绑定的设备列表(同步方式)
 *
 *  @param userId 用户id
 */
- (NSArray *)getBoundDevices:(NSNumber *)userId;

- (void)refreshDevices;


/**
 *  获取用户历史绑定设备
 *
 *  @param userId     用户id
 *  @param completion 回调
 */
- (void)getHistoryDevices:(NSString *)userId Completion:(void(^)(int code,NSString *msg,NSArray <Device *>*deviceList))completion;

/// 解除绑定 (非血压计调用)
/// @param deviceId 设备id
/// @param userId 用户id
/// @param completion 回调
- (void)unBindingDevice:(NSString *)deviceId userId:(NSNumber *)userId Completion:(void(^)(int code,NSString *msg))completion;


/// 解除绑定 (血压计调用)
/// @param deviceId 设备id
/// @param userId 用户id
/// @param completion 回调
- (void)unBindingDeviceAndDeleteAllUsers:(NSString *)deviceId userId:(NSNumber *)userId Completion:(void(^)(int code,NSString *msg))completion;


/**
 *  获取电量信息
 *
 *  @param deviceId 设备Id
 *
 *  @return 如果电量存在返回相应的电量值（0 ～ 1），没有则返回nil
 */
- (NSNumber *)getDeviceBatteryWithDeviceId:(NSString *)deviceId;

/**
 * 更新缓存电量
 */
- (void)updateBatteryWithDeviceId:(NSString *)deviceId battery:(NSInteger)battery;

/**
 * 删除缓存电量
 */
- (void)removeBatteryWithDeviceId:(NSString *)deviceId;

/**
 * 清空缓存电量
 */
- (void)removeAllBatteryCache;

/*
 来电手环: 设备上传电池电量 1. 大于等于 4.1V 的，都显示电量100%   ；2.电量 3.64- 4.1V 之间 的x 值，就使用 （x-3.64）/(4.1-3.64) *100% ;  3. 低于3.64 的就提示 “手环低电量，请及时充电”。
 
 心率手环 :设备上传电池电量 1. 大于等于 4.1V 的，都显示电量100%   ；2.电量 3.55- 4.1V 之间 的x 值，就使用 （x-3.55）/(4.1-3.55) *100% ;  3. 低于3.55的就提示 “手环低电量，请及时充电”。
 
 watch 手环: 设备上传电池电量 1. 大于等于 4.1V 的，都显示电量100%   ；2.电量 3.6- 4.1V 之间 的x 值，就使用 （x-3.6）/(4.1-3.6) *100% ;  3. 低于3.6 的就提示 “手环低电量，请及时充电”。
 */
- (int)getBatteryLevel:(float)batteryVoltage model:(NSString *)model softwareVersion:(NSString *)softwareVersion;


- (BOOL)isSupportReadBattery:(LSDeviceInfo *)device;


- (NSString *)devcieImageUrlWithBackdropForDevice:(Device *)deviceInfo;

- (NSString *)devcieImageUrlWithoutBackdropForDevice:(Device *)deviceInfo;



/**
 *  @brief 获取电量,非全部设备都支持,如果设备不支持，@see onReceiveBatteryStatus:isCharging:battery:
 *  @brief battery 将会为-1
 *
 *  @param deviceId 设备ID
 */
- (void)getBatteryInfo:(NSString *)deviceId;

/**
 封装getBatteryInfo：提供主动电量更新的逻辑
 
 @note  1、一次只针对一个设备生效，多次调用会覆盖上一次请求，使用新的DeviceId
 2、updateInterval必须大于等于5s
 
 @param deviceId 设备Id
 @param updateInterval 更新周期
 */
- (void)startDeviceBatteryStatusLiveUpdateWithDeviceId:(NSString *)deviceId updateInterval:(NSTimeInterval)updateInterval;

/**
 封装getBatteryInfo：停止主动电量更新
 
 @param deviceId 设备Id
 */
- (void)stopDeviceBatteryStatusLiveUpdateWithDeviceId:(NSString *)deviceId;


- (NSNumber *)getDeviceTimeZone:(NSString *)deviceId;
@end

NS_ASSUME_NONNULL_END
