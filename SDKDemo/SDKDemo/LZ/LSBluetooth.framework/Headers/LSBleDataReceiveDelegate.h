//
//  LSBleDataReceiveDelegate.h
//  LsBluetooth-Test
//
//  Created by lifesense on 14-8-12.
//  Copyright (c) 2014年 com.lifesense.ble. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BleManagerProfiles.h"
#import "model.h"
#import "LSErrorRecord.h"
#import "libCommon.h"
#import "a6model.h"
#import "LSBBleExceptionRecord.h"


@protocol LSBleDataReceiveDelegate <NSObject>

@optional

//接收体重测量数据
- (void)bleManagerDidReceiveWeightMeasuredData:(LSWeightData*)data device:(LSDeviceInfo *)device;

//接收计步器测量数据
- (void)bleManagerDidReceivePedometerMeasuredData:(LSPedometerData*)data device:(LSDeviceInfo *)device;

//接收血压计测量数据
- (void)bleManagerDidReceiveSphygmometerMeasuredData:(LSSphygmometerData *)data device:(LSDeviceInfo *)device;

//接收身高测量数据
- (void)bleManagerDidReceiveHeightMeasuredData:(LSHeightData*)data device:(LSDeviceInfo *)device;

//接收脂肪秤测量数据
- (void)bleManagerDidReceiveWeightAppendMeasuredData:(LSWeightAppendData*)data device:(LSDeviceInfo *)device;

//接收产品用户信息
- (void)bleManagerDidReceiveProductUserInfo:(LSProductUserInfo *)userInfo device:(LSDeviceInfo *)device;

//接收产品用户信息写成功回调
- (void)bleManagerDidWriteSuccessForProductUserInfo:(NSString *)deviceId memberId:(NSString *)memberId device:(LSDeviceInfo *)device;

//接收计步器用户信息写成功回调
- (void)bleManagerDidWriteSuccessForPedometerUserInfo:(NSString *)deviceId memberId:(NSString *)memberId device:(LSDeviceInfo *)device;

//接收计步器闹钟设置成功回调
- (void)bleManagerDidWriteSuccessForAlarmClock:(NSString *)deviceId memberId:(NSString *)memberId device:(LSDeviceInfo *)device;

/*
 *新增加接口部分，支持厨房秤
 */
//接收设备的详细信息
- (void)bleManagerDidDiscoveredDeviceInfo:(LSDeviceInfo *)deviceInfo;

//接收厨房秤的测量数据
- (void)bleManagerDidReceiveKitchenScaleMeasuredData:(LSKitchenScaleData *)kitchenData device:(LSDeviceInfo *)device;

//连接状态改变
- (void)bleManagerDidConnectStateChange:(DeviceConnectState)connectState deviceName:(NSString *)deviceName device:(LSDeviceInfo *)device;

//接收Ａ4设备的运动测量数据
- (void)bleManagerDidReceivePedometerMeasuredDataForA4:(NSArray *)dataList commandCode:(CommandRequestCode)code device:(LSDeviceInfo *)device;

//接收Ａ4设备的睡眠测量数据
- (void)bleManagerDidReceivePedometerSleepInfoForA4:(NSArray *)sleepInfoList  device:(LSDeviceInfo *)device;

//接收A5手环上传的测量数据，根据packet type 进行转换
//-(void)bleManagerDidReceivePedometerMeasuredDataForA5:(id)dataObject type:(PacketType)packetType;


/**
 收到历史数据同步标志(同步开始/同步过程/同步结束)

 @param device 设备
 @param flag 标志
 @param precent 百分比
 */
- (void)bleManagerDidReceiveHistoryDataSyncFlag:(LSDeviceInfo *)device flag:(LSHistoryDataSyncFlag)flag precent:(NSInteger)precent;
//- (void)bleManagerDidReceiveHistoryDataSyncFlag:(LSDeviceInfo *)device flag:(LSHistoryDataSyncFlag)flag;

/**
 *  收到设备信息,这个是设备主动上传
 *
 *  @param info 设备信息模型
 */
- (void)bleManagerDidReceiveDeviceInfo:(LSUDeviceInfo *)info srcData:(NSData *)srcData device:(LSDeviceInfo *)device;

/**
 *  收到血氧数据
 *
 *  @param info 血氧数据模型
 */
- (void)bleManagerDidReceiveBloodOxygen:(LSUBloodOxygen *)info srcData:(NSData *)srcData device:(LSDeviceInfo *)device;

/**
 *  收到心率数据
 *
 *  @param info 心率数据模型
 */
- (void)bleManagerDidReceiveHeartRate:(LSUHearRate *)info srcData:(NSData *)srcData device:(LSDeviceInfo *)device;

/**
 *  收到运动心率数据
 *
 *  @param info 运动心率数据模型
 */
- (void)bleManagerDidReceiveSportHeartRate:(LSUSportHeartRate *)info srcData:(NSData *)srcData device:(LSDeviceInfo *)device;

/**
 *  收到配速数据
 *
 *  @param info 配速数据模型
 */
- (void)bleManagerDidReceiveConfigurationSpeed:(LSUConfigurationSpeed *)info srcData:(NSData *)srcData device:(LSDeviceInfo *)device;

/**
 *  收到测量数据
 *
 *  @param info 测量数据模型
 */
- (void)bleManagerDidReceiveMeasureData:(NSArray<LSUMeasureData *> *)info srcData:(NSData *)srcData device:(LSDeviceInfo *)device;

/**
 *  收到睡眠数据
 *
 *  @param info 睡眠数据模型
 */
- (void)bleManagerDidReceiveSleepData:(LSUSleepData *)info srcData:(NSData *)srcData device:(LSDeviceInfo *)device;

/**
 *  收到卡路里数据
 *
 *  @param info 卡路里数据模型
 */
- (void)bleManagerDidReceiveCaloriesData:(LSUCaloriesData *)info srcData:(NSData *)srcData device:(LSDeviceInfo *)device;

/**
 *  收到跑步数据
 *
 *  @param info 跑步数据模型
 */
- (void)bleManagerDidReceiveSportData:(LSUSportData *)info srcData:(NSData *)srcData device:(LSDeviceInfo *)device;

/**
 *  收到新跑步数据
 *
 *  @param info 新跑步数据模型
 */
- (void)bleManagerDidReceiveRunningData:(LSURunningData *)info srcData:(NSData *)srcData device:(LSDeviceInfo *)device;

/**
 *  收到运动模式健走数据
 *
 *  @param info 运动模式健走数据模型
 */
- (void)bleManagerDidReceiveWalkingData:(LSUWalkingData *)info srcData:(NSData *)srcData device:(LSDeviceInfo *)device;

/**
 *  收到运动模式状态数据
 *
 *  @param info 运动模式状态模型
 */
- (void)bleManagerDidReceiveSportModeStateData:(LSUSportState *)info device:(LSDeviceInfo *)device;

/**
 *  收到手环向App上报状态
 *
 *  @param info 运动上报状态模型
 */
- (void)bleManagerDidReceiveReportSportStateData:(LSUReportSportState *)info device:(LSDeviceInfo *)device;


/**
 *  收到游泳数据
 *
 *  @param info 游泳数据模型
 */
- (void)bleManagerDidReceiveSwimingData:(LSUSwimData *)info srcData:(NSData *)srcData device:(LSDeviceInfo *)device;

/**
 * 收到健身运动数据
 *
 * @param info 健身数据模型
 */
- (void)bleManagerDidReceiveFitnessData:(LSUFitnessData *)info srcData:(NSData *)srcData device:(LSDeviceInfo *)device;

/**
 * 收到骑行运动数据
 *
 * @param info 骑行数据模型
 */
- (void)bleManagerDidReceiveRideData:(LSURideData *)info srcData:(NSData *)srcData device:(LSDeviceInfo *)device;


/**
 * 收到篮球运动数据
 *
 * @param info 篮球数据模型
 */
- (void)bleManagerDidReceiveBasketballData:(LSUBasketballData *)info srcData:(NSData *)srcData device:(LSDeviceInfo *)device;

/**
 * 收到足球运动数据
 *
 * @param info 足球数据模型
 */
- (void)bleManagerDidReceiveFootballData:(LSUFootballData *)info srcData:(NSData *)srcData device:(LSDeviceInfo *)device;

/**
 * 收到羽毛球运动数据
 *
 * @param info 羽毛球数据模型
 */
- (void)bleManagerDidReceiveBadmintonData:(LSUBadmintonData *)info srcData:(NSData *)srcData device:(LSDeviceInfo *)device;

/**
 * 收到排球运动数据
 *
 * @param info 排球数据模型
 */
- (void)bleManagerDidReceiveVolleyballData:(LSUVolleyballData *)info srcData:(NSData *)srcData device:(LSDeviceInfo *)device;

/**
 * 收到乒乓球运动数据
 *
 * @param info 乒乓球数据模型
 */
- (void)bleManagerDidReceiveTableTennisData:(LSUTableTennisData *)info srcData:(NSData *)srcData device:(LSDeviceInfo *)device;

/**
 * 收到瑜伽运动数据
 *
 * @param info 瑜伽数据模型
 */
- (void)bleManagerDidReceiveYogaData:(LSUYogaData *)info srcData:(NSData *)srcData device:(LSDeviceInfo *)device;

//太极
- (void)bleManagerDidReceiveTaijiData:(LSUBaseSportData *)info srcData:(NSData *)srcData device:(LSDeviceInfo *)device;
//健身舞
- (void)bleManagerDidReceiveGymDanceData:(LSUBaseSportData *)info srcData:(NSData *)srcData device:(LSDeviceInfo *)device;

- (void)bleManagerDidReceiveIndoorRunData:(LSUIndoorRunSportData *)info srcData:(NSData *)srcData device:(LSDeviceInfo *)device;
- (void)bleManagerDidReceiveCycleMactionData:(LSUBaseSportData *)info srcData:(NSData *)srcData device:(LSDeviceInfo *)device;
- (void)bleManagerDidReceiveOxSportData:(LSUBaseSportData *)info srcData:(NSData *)srcData device:(LSDeviceInfo *)device;

- (void)bleManagerDidReceiveESportData:(LSUESportData *)info srcData:(NSData *)srcData device:(LSDeviceInfo *)device;


/**
 * 收到新测量数据
 *
 * @param info 新测量数据模型
 */
- (void)bleManagerDidReceiveNewMeasureData:(LSUNewMeasureData *)info srcData:(NSData *)srcData device:(LSDeviceInfo *)device;

/*
 * 收到测试数据
 *
 * @param info 测试数据模型
 */
- (void)bleManagerDidReceiveTestData:(LSUTestData *)info srcData:(NSData *)srcData device:(LSDeviceInfo *)device;
/**
 *  收到心率区间统计数据
 *
 *  @param info 心率区间统计数据模型
 */
- (void)bleManagerDidReceiveHRSectionData:(LSUHRSection *)info srcData:(NSData *)srcData device:(LSDeviceInfo *)device;

/**
 *  获取到设备信息,这个是需要向设备发送获取设备信息指令才会执行
 *
 *  @param info 获取到的设备信息数据
 */
- (void)bleManagerDidReceiveGetDeviceInfo:(LSUGetDeviceInfo *)info srcData:(NSData *)srcData device:(LSDeviceInfo *)device;

/**
 *  电量信息回调
 *
 *  @param info 电量信息,如果获取不到，则info = nil
 *  @param device 设备
 */
- (void)bleManagerDidReceiveBatteryInfo:(LSUVoltageModel *)info device:(LSDeviceInfo *)device;

/**
 *  实时心率数据回调
 *
 *  @param info 心率数据模型
 *  @param device 设备
 */
- (void)bleManagerDidReceiveRealTimeHRInfo:(LSURealTimeHRData *)info device:(LSDeviceInfo *)device;

- (void)bleManagerDidReceiveErrorRecord:(LSErrorRecord *)errorRecord targetDevice:(NSString *)broadcastId;


- (void)bleManagerDidReceiveErrorRecords:(NSArray *)errorRecords targetDevice:(NSString *)broadcastId;

/**
 *  获取到时区
 *
 *  @param timezone 时区
 *  @param device   设备
 */
- (void)bleManagerDidReceiveDeviceTimeZone:(NSInteger)timezone device:(LSDeviceInfo *)device;

/*
 #pragma mark OTA
 - (void)otaMgrState:(LSOTAManagerCode)state;
 - (void)otaMgrUpgradePercent:(NSInteger)percent;
 */

/**
 *  绑定/解绑回调
 *
 *  @param deviceifo 设备信息
 *  @param code   设备绑定或解绑状态
 */
//- (void)bleManagerDidReceiveDeviceBind:(LSDeviceInfo *)deviceifo code:(LSBindCode)code;

/**
 *  收到体重秤电量信息
 *  @param info 体重秤电量信息
 */
- (void)bleManagerDidReceiveWeightScaleBattery:(LSWeightScaleBatteryInfo *)info device:(LSDeviceInfo *)device;

/**
 *  收到体重秤测量数据
 *  @param info 体重秤测量数据
 */
- (void)bleManagerDidReceiveWeightScaleMeasureData:(LSUSyncMeasureData *)info srcData:(NSData *)srcData device:(LSDeviceInfo *)device;

/**
 *  收到体重秤单位信息
 *  @param info 体重秤单位信息
 */
- (void)bleManagerDidReceiveWeightScaleUnitInfo:(LSUUnitSettingData *)info srcData:(NSData *)srcData device:(LSDeviceInfo *)device;

/**
 *  收到体重秤设置结果信息
 *  @param info 体重秤设置结果信息
 */
- (void)bleManagerDidReceiveWeightScaleSettingResultInfo:(LSUSettingResult *)info srcData:(NSData *)srcData device:(LSDeviceInfo *)device;

/**
 蓝牙异常记录

 @param record 记录
 */
- (void)onBluetoothExceptionRecord:(LSBBleExceptionRecord *)record;


/// 接收爆款秤wifi扫描数据
/// @param wifiModel model
/// @param device 设备信息
- (void)bleManagerDidReceiveSsidName:(LSScaleWifiModel *)wifiModel device:(LSDeviceInfo *)device;

/// 爆款秤wifi配网状态回调
/// @param state 0成功 1失败
/// @param device 设备信息
- (void)bleManagerDidReceiveWifiConnectState:(NSInteger *)state device:(LSDeviceInfo *)device;


@end

// 配对回调
@protocol LSBindDelegate <NSObject>

- (void)bindResult:(LSBindCode)code device:(LSDeviceInfo *)deviceInfo object:(NSObject *)object;

@end


