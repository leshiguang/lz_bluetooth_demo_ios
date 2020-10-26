//
//  LSDeviceComponentDelegate.h
//  LSBluetooth-Library
//
//  Created by Dylan on 16/1/18.
//  Copyright © 2016年 Lifesense. All rights reserved.
//t

#import <Foundation/Foundation.h>
typedef NS_ENUM(NSUInteger, LSOTAUpdataState) {
    LSOTAUpdataStateNotSetCentralManager, // 没有设置CBCentralManager
    LSOTAUpdataStateNotAvailable,   // 蓝牙不可用
    LSOTAUpdataStateNotFound,       // 找不到设备
    LSOTAUpdataStateHexFileNotFound,// 固件找不到
    LSOTAUpdataStateHexFileInvalid, // 固件文件无效
    LSOTAUpdataStateConnectFailed,  // 连接失败
    LSOTAUpdataStateDisconnected,   // 断开连接
    LSOTAUpdataStateNotSupport,     // 不支持的升级
    LSOTAUpdataStateEnterDFUModeFailed,// 进入升级模式失败
    LSOTAUpdataStateEnteredDFUMode,    // 已进入升级模式
    LSOTAUpdataStateUpgrading,         // 升级中
    LSOTAUpdataStateUpgradeFailed,     // 升级失败
    LSOTAUpdataStateUpgradeCancel,     // 升级取消
    LSOTAUpdataStateSuccess,           // 升级成功
    LSOTAUpdataStateLowBattery,        // 电量低
};
//连接状态
typedef enum{
    LS_CONNECTED_SUCCESS = 1,
    LS_CONNECTED_FAILED = 2,
    LS_DISCONNECTED = 3,
    LS_CONNECTED_BEGIN = 4,       // 开始连接
}BluetoothConnectState;
//绑定状态
typedef enum : NSUInteger {
    /**
     *  输入校验码
     */
    LSEBindStatusInputCode,
    
    /**
     *  绑定成功
     */
    LSEBindStatusSuccessful,
    
    /**
     *  绑定失败
     */
    LSEBindStatusFail,
    
    /**
     *  解绑成功
     */
    LSEBindUnBindSuccessful,
    
    /**
     *  解绑失败
     */
    LSEBindUnBindFailure,
    
} LSEBindStatusCode;
/**
 手机计步错误代码
 */
typedef enum : NSUInteger {
    PedometerErrorCodeSuccess,      ///< 正常
    PedometerErrorCodeNoPermission, ///< 没有权限
    PedometerErrorCodeUnSupported,  ///< 不支持手机计步
    PedometerErrorCodeOther,        ///< 其它错误
} PedometerErrorCode;


/**
 * 历史数据同步标志
 */
typedef NS_ENUM(NSUInteger, LSEHistoryDataSyncFlag)
{
    /**
     * 同步开始
     */
    LSEHistoryDataSyncFlagStart,
    
    /**
     * 同步结束
     */
    LSEHistoryDataSyncFlagEnd,
};

@class LSDeviceInfo,WeightData,RunningData,SwimmingData,WalkingData,SportHeartRateData,SleepingData,Device,DeviceUser,DeviceStatus,DeviceSetting,HeartRateData, HRSectionStatisticData, RunningCaloriesData,UWalkingData,SportStateData, LSSportGPSData, LSPaceStatusData, LSSportTotalData, LSEcgStatus, LSEcgTotalData, LSEcgData, LSEcgMiddleResult, LSSleepData,LSEcgResult,LSURealTimeHRData;
@protocol LSDeviceComponentDelegate <NSObject>
@optional

//检测蓝牙设备的连接状态
- (void)onDeviceConnectStateChange:(BluetoothConnectState)connectState broadcastId:(NSString *)broadcastId;

- (void)onDeviceConnectStateChange:(BluetoothConnectState)connectState device:(Device *)device;

//固件升级百分比
- (void)deviceComponentOtaUpgradePercent:(NSInteger )percent;

//固件升级状态
- (void)deviceComponentOtaState:(LSOTAUpdataState)state;

#pragma mark-接收设备上传的数据


/**
 *  @brief 获取电量,非全部设备都支持,如果设备不支持，@see onReceiveBatteryStatus:isCharging:battery:
 *  @param deviceId   设备ID
 *  @param isCharging 是否在充电
 *  @param battery    电量（0 ~ 100）,不支持或获取出错就为-1
 */
- (void)onReceiveBatteryStatus:(NSString *)deviceId isCharging:(BOOL)isCharging battery:(NSInteger)battery;


/**
 轨迹跑模式回调接口

 @param deviceId 设备ID
 @param state    轨迹跑状态，0:开始，1:结束
 */
- (void)onReceiveTrackMode:(NSString *)deviceId state:(SportStateData *)state;

#pragma mark -手机蓝牙状态实时检测
//手机蓝牙状态改变实时回调
- (void)onBluetoothStateChange:(BOOL)enable;

/**
 绑定状态回调接口, device和deviceUsers只有在LSEBindStatusSuccessful时才有值

 @param bindCode 绑定状态
 @param device 设备信息
 @param deviceUsers 设备用户信息
 @param netCode 网络错误的代码
 @param netMsg  网络错误的消息
 @param object  如果bindCode是输入随机码状态LSEBindStatusInputCode，object表示随机码长度，数据类型为NSNumber，如果是其他状态码，object为nil
 */
- (void)onBindStatusChange:(LSEBindStatusCode)bindCode device:(Device *)device deviceUsers:(NSArray<DeviceUser *> *)deviceUsers netCode:(NSInteger)netCode netMsg:(NSString *)netMsg object:(NSObject *)object;

/**
 收到历史数据进度回调
 
 @param device 设备
 @param precent 进度
 */
- (void)onReceiveHistoryData:(Device *)device precent:(NSInteger)precent;


- (void)device:(Device *)device sorfVersionChangeTo:(NSString *)version;

@end
