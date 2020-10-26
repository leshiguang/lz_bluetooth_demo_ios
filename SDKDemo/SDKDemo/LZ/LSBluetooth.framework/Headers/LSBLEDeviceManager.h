//
//  LSBLEDeviceManager.h
//  LifesenseBle.
//
//  Created by lifesense on 14-8-1.
//  Copyright (c) 2014年 lifesense. All rights reserved.
//m3



#import <Foundation/Foundation.h>
#import "BleManagerProfiles.h"
#import "NSMutableArray+QueueAdditions.h"
#import "model.h"
#import "LSConst.h"
#import "BleDebugLogger.h"
#import "libCommon.h"
#import "a6model.h"
#import "LSBleConnector.h"
@class CBPeripheral;
typedef NS_ENUM(NSUInteger, LSOTAState) {
    LSOTAStateNotSetCentralManager,
    LSOTAStateNotAvailable,
    LSOTAStateNotFound,
    LSOTAStateHexFileNotFound,
    LSOTAStateHexFileInvalid,
    LSOTAStateConnectFailed,
    LSOTAStateDisconnected,
    LSOTAStateNotSupport,
    LSOTAStateEnterDFUModeFailed,
    LSOTAStateEnteredDFUMode,
    LSOTAStateUpgrading,
    LSOTAStateUpgradeFailed,
    LSOTAStateUpgradeCancel,
    LSOTAStateSuccess,
    LSOTAStateVERSIONHASUPGRADED,//此文件版本已经升级过了,升级失败
    LSOTAStateBATTERYLOW,//电量不足升级失败
    LSOTAStateCODEVERSIONNOCORRECT,//拒绝本次下载,升级失败
    LSOTAStateCHECKFAILURE,//文件校验失败,退出升级
    LSOTAStateBATTERYLOWUPDATEFAILURE, //电量不足更新失败，退出升级
};


typedef NS_ENUM(NSUInteger, OTADeviceType) {
    OTADeviceType_Mambo,
    OTADeviceType_MamboHR,
    OTADeviceType_MamboWatch,
    OTADeviceType_SCALE,
};

// 配对状态回调
typedef void(^MatchBlock)(BOOL bMatch);

typedef void(^ReturnBlock)(BOOL bSuccess);

typedef void(^RealTimeHRStatusBlock)(LSRealTimeResultStatus status);

typedef void(^ConnectStatusBlock)(NSString *deviceId);

@protocol LSOTADelegate <NSObject>

- (void)otaState:(LSOTAState)state;

- (void)otaUpgradePercent:(NSInteger)percent;

@end

@interface LSBLEDeviceManager : NSObject
@property(nonatomic)BOOL isBluetoothPowerOn;
@property(nonatomic,strong,readonly)NSString *versionName;

//@property (nonatomic, copy) ConnectStatusBlock connectBeginBlock;
//@property (nonatomic, copy) ConnectStatusBlock connectSuccessBlock;

@property (nonatomic, copy) ConnectStatusBlock connectStartBlock;     // 连接开始
@property (nonatomic, copy) ConnectStatusBlock scanBlock;       // 扫描成功
@property (nonatomic, copy) ConnectStatusBlock connectBlock;    // 建立连接
@property (nonatomic, copy) ConnectStatusBlock enableBlock;     // 打开通道
@property (nonatomic, copy) ConnectStatusBlock weightDataBlock;      // 接收体重数据


//获取实例对象
+ (instancetype)defaultLsBleManager;

//蓝牙状态检测
- (void)checkBluetoothStatus:(void(^)(BOOL isSupportFlags,BOOL isOpenFlags))checkCompletion;

//根据指定条件搜索乐心设备
- (BOOL)searchLsBleDevice:(NSArray *)deviceTypes ofBroadcastType:(BroadcastType)broadcastType searchCompletion:(void(^)(LSDeviceInfo* lsDevice))searchCompletion;

//停止搜索
- (BOOL)stopSearch;
- (void)stopSearch:(ReturnBlock)block;

//与设备进行配对
- (BOOL)pairWithLsDeviceInfo:(LSDeviceInfo *)lsDevice pairedDelegate:(id<LSBlePairingDelegate>)pairedDelegate;

//启动测量数据接收服务
- (BOOL)startDataReceiveService:(id<LSBleDataReceiveDelegate>)dataDelegate;

- (void)startDataReceiveService:(id<LSBleDataReceiveDelegate>)dataDelegate block:(ReturnBlock)block;


/// 停止测量数据接收服务
- (BOOL)stopDataReceiveService;

- (void)stopDataReceiveService:(ReturnBlock)block;


//绑定设备用户编号
- (BOOL)bindingDeviceUsers:(NSUInteger)userNumber userName:(NSString *)name;

//设置测量设备列表
- (void)setMeasureDeviceList:(NSArray *)deviceList;

//添加单个测量设备
- (BOOL)addMeasureDevice:(LSDeviceInfo *)lsDevice;
- (void)addMeasureDevice:(LSDeviceInfo *)lsDevice block:(ReturnBlock)block;

//根据广播ID删除单个测量设备
- (BOOL)deleteMeasureDevice:(NSString *)broadcastId;

- (void)deleteMeasureDevice:(NSString *)broadcastId block:(ReturnBlock)block;


//设置产品的用户信息，对于A3协议的脂肪秤
- (BOOL)setProductUserInfo:(LSProductUserInfo *)userInfo;
- (void)setProductUserInfo:(LSProductUserInfo *)userInfo block:(ReturnBlock)block;

//设置计步器的用户信息
- (BOOL)setPedometerUserInfo:(LSPedometerUserInfo *)pedometerUserInfo;
- (void)setPedometerUserInfo:(LSPedometerUserInfo *)pedometerUserInfo block:(ReturnBlock)block;

//设置计步器的闹钟信息
- (BOOL)setPedometerAlarmClock:(LSPedometerAlarmClock *)alarmClock;
- (void)setPedometerAlarmClock:(LSPedometerAlarmClock *)alarmClock block:(ReturnBlock)block;

//set up enable scan device by broadcast name
- (BOOL)setEnableScanBrocastName:(NSArray*)enableDevices;
- (void)setEnableScanBrocastName:(NSArray*)enableDevices block:(ReturnBlock)block;

//new interface for bodyfat parse
- (LSWeightAppendData *)parseAdiposeDataWithResistance:(double)resistance_2 userHeight:(double)height_m userWeight:(double)weight_kg userAge:(int)age userSex:(UserSexType)sex;

//新增加接口，设置A2设备的声音振动提示功能
- (BOOL)setVibrationVoice:(LSVibrationVoice *)vibrationVoice;
- (void)setVibrationVoice:(LSVibrationVoice *)vibrationVoice block:(ReturnBlock)block;

//版本1.0.8新增接口，启动血压计开始测量
- (BOOL)startMeasuring;
- (void)startMeasuring:(ReturnBlock)block;

//版本1.0.8新增接口，连接通过命令启动测量的血压计设备
- (BOOL)connectDevice:(LSDeviceInfo *)pairedDevice connectDelegate:(id<LSDeviceConnectDelegate>)connectDelegate;
- (void)connectDevice:(LSDeviceInfo *)pairedDevice connectDelegate:(id<LSDeviceConnectDelegate>)connectDelegate block:(ReturnBlock)block;

//版本1.0.8新增接口，根据指定的设备类型、设备名称设置配对时采用固定的广播ID接口
- (BOOL) setCustomBroadcastID:(NSString *)customBroadcastID deviceName:(NSString *)deviceName deviceType:(NSArray*)deviceTypes;
- (void)setCustomBroadcastID:(NSString *)customBroadcastID deviceName:(NSString *)deviceName deviceType:(NSArray*)deviceTypes block:(ReturnBlock)block;

- (void) setDispatchQueue:(dispatch_queue_t)dispatchQueue;

//版本V2.0.0新增接口，设置是否允许输出log调试信息
- (void) setDebugModeWithPermissions:(NSString *)key;

#pragma mark A5、A4/Wechat

/**
 * 更新用户信息到指定设备
 */
- (BOOL)setUserInfo:(LSDeviceInfo *)deviceInfo userInfo:(LSDUserInfo *)userInfo;

/**
 * 设置设备的闹钟信息
 */
- (void)setAlarmClock:(LSDeviceInfo *)deviceInfo isOpenAlert:(BOOL)isOpenAlert alarmClockInfos:(NSArray<LSAlarmClock *> *)alarmClockInfos callback:(WriteCallback)callback;

/**
 * 设置设备久坐提醒信息
 */
- (void)setSedentaryInfo:(LSDeviceInfo *)deviceInfo isOpenAlert:(BOOL)isOpenAlert sedentaryInfos:(NSArray<LSSedentaryClock *> *)sedentaryInfos callback:(WriteCallback)callback;
/**
 * 设置设备来电提醒信息
 */
- (void)setCallReminderInfo:(LSDeviceInfo *)deviceInfo setting:(LSDCallReminder *)setting callback:(WriteCallback)callback;

//使用app id设置提醒
- (void)setCallReminderInfo:(LSDeviceInfo *)deviceInfo appId:(LSDAppidReminder *)setting callback:(WriteCallback)callback;

/**
 * 设备是否防丢模式
 */
- (void)setLostSetting:(LSDeviceInfo *)deviceInfo isOpen:(BOOL)isOpen callback:(WriteCallback)callback;

/**
 * 设置每周目标
 */
- (void)setWeekTarget:(LSDeviceInfo *)deviceInfo target:(LSWeekTarget)target targetValue:(float)targetValue callback:(WriteCallback)callback;

/**
 *  设置鼓励
 *
 *  @param deviceInfo 设备
 *  @param isOpen     是否打开
 *  @param step       目标步数
 *
 */
- (void)setEncourageSetting:(LSDeviceInfo *)deviceInfo isOpen:(BOOL)isOpen step:(int)step callback:(WriteCallback)callback;

/**
 *  心率检测设置
 *
 *
 */
- (void)setHeartRateSetting:(LSDeviceInfo *)deviceInfo isOpen:(BOOL)isOpen startHour:(int)starthour startMinute:(int)startminute endHour:(int)endhour endMinute:(int)endminute callback:(WriteCallback)callback;
/**
 *  设置心率区间(Watch)
 *
 *  @param deviceInfo 设备
 *  @param age        年龄
 *
 *  @return 成功返回YES
 */
- (void)setHeartRateSection:(LSDeviceInfo *)deviceInfo age:(NSUInteger)age callback:(WriteCallback)callback;

- (void)setHeartRateSection:(LSDeviceInfo *)deviceInfo age:(NSUInteger)age sections:(NSArray<LSHeartSection *>*)sections callback:(WriteCallback)callback;

/**
 *  运动区间心率上下限设置(Watch)
 *
 *
 */
- (void)setSportHeartRateSetting:(LSDeviceInfo *)deviceInfo MaxHeartRateZone:(int)maxHeartRateZone MinHeartRateZone:(int)minHeartRateZone callback:(WriteCallback)callback;

/**
 *  获取设备设置信息命令(Watch)
 *
 *
 */
- (void)setPushGetInfor:(LSDeviceInfo *)deviceInfo GetDeviceInfoType:(LSGetDeviceInfoType)GetDeviceInfor FlashType:(int)flashType BeginAddr:(int)beginAddr EndAddr:(int)endAddr callback:(WriteCallback)callback;

/**
 *  设置夜间抬手显示开关到手环(MT,Gold)
 *
 *
 */
- (void)setNightModelSetting:(LSDeviceInfo *)deviceInfo isOpen:(BOOL)isOpen startHour:(int)starthour startMinute:(int)startminute endHour:(int)endhour endMinute:(int)endminute callback:(WriteCallback)callback;

/**
 *  设置勿扰开关到手环(M5)
 *
 *
 */
- (void)setNotDisturbModelSetting:(LSDeviceInfo *)deviceInfo isNotDisturbOpen:(BOOL)isNotDisturbOpen isLightWhenUpOpen:(BOOL)isLightWhenUpOpen startHour:(int)starthour startMinute:(int)startminute endHour:(int)endhour endMinute:(int)endminute callback:(WriteCallback)callback;


/**
 *  设置手环佩戴左右手显示方式到手环(MT,Gold)
 *
 *
 */
- (void)setWearingWaySetting:(LSDeviceInfo *)deviceInfo way:(WearingWay)way callback:(WriteCallback)callback;

/**
 *  设置手环横屏竖屏显示(MT,Gold)
 *
 *
 */
- (void)setSceenWaySetting:(LSDeviceInfo *)deviceInfo way:(ScreenWay)way callback:(WriteCallback)callback;

/**
 *  设置手环自定义显示页面(MT,Gold)
 *
 *
 */
- (void)setDisplayPageSetting:(LSDeviceInfo *)deviceInfo displayPage:(LSDDisplayPage *)displayPage callback:(WriteCallback)callback;

/**
 *  设置手环智能心率检测开关(MT,Gold)
 *
 *
 */
- (void)setSmartHeartSetting:(LSDeviceInfo *)deviceInfo smartHeartType:(LSSmartHeartType)type callback:(WriteCallback)callback;

/**
 *  设置手环表盘设置到手环(MID)
 *
 *
 */
- (void)setDialSetting:(LSDeviceInfo *)deviceInfo dialType:(LSDialModeType)type callback:(WriteCallback)callback;

/**
 *  设置自动识别多运动开关到手环(MID)
 *
 *
 */
- (void)setAutomaticSportsSetting:(LSDeviceInfo *)deviceInfo automaticSports:(NSArray<LSAutomaticSportstypeModel*> *)automaticSports callback:(WriteCallback)callback;
/**
 *  设置鼓励目标类型提醒设置到蓝牙手环(MID)
 *
 *
 */
- (void)setEncourageTypeSetting:(LSDeviceInfo *)deviceInfo isOpen:(BOOL)isOpen targetType:(LSEncourageTargetType)targetType targetValue:(float)targetValue callback:(WriteCallback)callback;

/**
 *  设置天气信息到蓝牙手环(MID)
 *
 *
 */
- (void)setWeatherDataSetting:(LSDeviceInfo *)deviceInfo weatherData:(LSDWeatherData *)weatherData callback:(WriteCallback)callback;

/**
 *  设置事件提醒信息到手环(MID)
 *
 *
 */
- (void)setEventInfoSetting:(LSDeviceInfo *)deviceInfo eventReminds:(LSEventRemind *)eventRemind callback:(WriteCallback)callback;

/**
 *  设置运动心率区间提醒(MID)
 *
 *
 */
- (void)setSportHeartRateSectionRemindSetting:(LSDeviceInfo *)deviceInfo heartRateMax:(NSInteger)heartRateMax heartRateMin:(NSInteger)heartRateMin isOpen:(BOOL)isOpen callback:(WriteCallback)callback;

/**
 * 用户绑定手环 A5/A6
 *
 *
 */
- (void)bindDevice:(LSDeviceInfo *)deviceInfo delegate:(id<LSBindDelegate>)delegate;


/**
 * 用户绑定手环 A5/A6
 *
 *
 */
- (CBPeripheral*)getBindedDevice:(LSDeviceInfo *)deviceInfo;


-(LSBleConnector*) getConnector;

-(id<LSBleDataReceiveDelegate>)getDataReceiveDelagate;

-(LSDeviceInfo*) getBP1597MeasureDevice;
/**
 * 输入绑定手环校验码 A5
 */
- (void)inputCheckNumber:(NSString *)numberStr macAddress:(NSString *)macAddress;

/**
 * 用户确认是否进行配对 A5
 *
 */
- (void)confirmBindDevice:(BOOL)isConfirmation macAddress:(NSString *)macAddress;

/**
 * 写入DeviceID及设备注册状态 A6
 *
 */
- (void)setmacAddress:(NSString *)macAddress deviceID:(NSString *)deviceID code:(LSRegisterCode)code;

/**
 * 输入用户编号 0：客人/未识别用户 1~4：已识别用户 255：无效用户 及绑定结果(绑定) A6
 */
- (void)inputUserNumberBindDevice:(NSString *)macAddress userNumber:(int)userNumber bingResult:(LSDeviceBindResultCode)code;

/**
 * 解除绑定  用户编号 0：客人/未识别用户 1~4：已识别用户 255：无效用户 A6
 */
- (void)unBindDevice:(LSDeviceInfo *)deviceInfo userNumber:(int)userNumber  delegate:(id<LSBindDelegate>)delegate;

/**
 * 取消解绑 A6
 */
- (void)cancelUnBind:(NSString *)macAddress;

/**
 * 取消绑定 A5/A6
 */
- (void)cancelBind:(NSString *)macAddress;

/**
 * 设置A6体重秤时间
 */
- (void)setScaleTime:(LSDeviceInfo *)deviceInfo time:(LSDSettingTime *)time callback:(WriteCallback)callback;

/**
 * 设置A6体重秤单位
 */
- (void)setScaleUnit:(LSDeviceInfo *)deviceInfo unit:(LSWeightUnit)unit callback:(WriteCallback)callback;

/**
 * 设置A6体重秤用户信息
 */
- (void)setScaleUserInfo:(LSDeviceInfo *)deviceInfo userInfo:(LSDUserInformation *)userInfo callback:(WriteCallback)callback;

/**
 * 设置A6体重秤目标
 */
- (void)setScaleTarget:(LSDeviceInfo *)deviceInfo target:(LSDTargetInfomation *)target callback:(WriteCallback)callback;

/**
 * 同步A6体重秤测量数据
 */
- (void)synScaleMeasureData:(LSDeviceInfo *)deviceInfo measureInfo:(LSDSyncDataNotify *)measureInfo callback:(WriteCallback)callback;


/*
 *  设置手环时间显示类型
 *
 *
 */
- (void)setTimeTypeSetting:(LSDeviceInfo *)deviceInfo timeType:(TimeType)type callback:(WriteCallback)callback;

/**
 *  设置手环距离单位
 *
 *
 */
- (void)setDistanceUnitSetting:(LSDeviceInfo *)deviceInfo distanceUnit:(DistanceUnit)type callback:(WriteCallback)callback;

/**
 *  设置手机GPS状态到手环
 *
 *
 */
- (void)setGpsStateSetting:(LSDeviceInfo *)deviceInfo isOpen:(BOOL)isOpen callback:(WriteCallback)callback;

/**
 *  设置语言到手环
 *
 *  code 语言代码
 */
- (void)setLanguageSetting:(LSDeviceInfo *)deviceInfo languageCode:(NSString *)code callback:(WriteCallback)callback;

/**
 *  设置配速到手环
 *
 *  speed 配速设置模型
 */
- (void)setSpeedSetting:(LSDeviceInfo *)deviceInfo speed:(LSDSpeedModel *)speed callback:(WriteCallback)callback;

/**
 *  设置游泳参数到手环
 *
 *  swim 游泳参数设置模型
 */
- (void)setSwimSetting:(LSDeviceInfo *)deviceInfo swim:(LSDSwimModel *)swim callback:(WriteCallback)callback;

/**
 * 设置Log目录地址, 全路径
 */
+ (void)setLogDirectory:(NSString *)logPath;

/*
 * 是否保存log文件
 */
+ (void)setIsSaveLog:(BOOL)isSaveLog;

/*
 * 是否显示蓝牙未打开提示弹框
 */

+ (void)setIsShowBleAlert:(BOOL)isShow;

/**
 *  @brief 获取设备电压（异步）
 *  @brief 通过@see LSBleDataReceiveDelegate的bleManagerDidReceiveBatteryInfo:device:接口回调
 *
 *  @param device 设备
 *
 *  @return 是否调用成功
 */
- (BOOL)getVoltageInfo:(LSDeviceInfo *)deviceInfo;
- (void)getVoltageInfo:(LSDeviceInfo *)deviceInfo block:(ReturnBlock)block;

/**
 *  @brief 获取实时心率
 *  @brief 通过@see LSBleDataReceiveDelegate的bleManagerDidReceiveRealTimeHRInfo:device:接口回调
 *
 *  @param device 设备
 *  @param isOpen 开启或关闭数据接收
 *  @return 调用结果状态
 */
- (void)getRealTimeHR:(LSDeviceInfo *)deviceInfo isOpen:(BOOL)isOpen block:(RealTimeHRStatusBlock)block;

/**
 *  是否支持实时心率功能
 *
 */
- (void)isSupportRealTimeHRFunction:(LSDeviceInfo *)deviceInfo block:(ReturnBlock)block;

/**
 *  设置时区
 *
 *  @param timezone 时区
 */
- (void)setDeviceTimeZone:(NSInteger)timezone;

/**
 *  回复接收运动模式结果
 *
 *  @param functionTest 功能检测
 *
 *  @param sporState 功能状态
 */
- (void)setSportModeResultSetting:(LSDeviceInfo *)deviceInfo functionTest:(LSFunctionTestType)functionTest state:(LSFunctionGPSType)state callback:(WriteCallback)callback;


/**
 发起或结束运动
 
 @param deviceInfo 设备
 @param isLaunch 是否开启
 @param modelType 运动模式
 @param callback 回调
 */
- (void)launchOrCloseSport:(LSDeviceInfo *)deviceInfo isLaunch:(BOOL)isLaunch modelType:(LSSportModeType)modelType callback:(WriteCallback)callback;

#pragma mark OTA

// OTA升级
- (void)upgradeWithMacAddress:(NSString *)macAddr hardwareVer:(NSString *)hardwareVer softwareVer:(NSString *)softwareVer deviceType:(OTADeviceType)deviceType filePath:(NSURL *)filePath delegate:(id <LSOTADelegate>)delegate;

//查找目标设备的广播
- (void)findDeviceBroadcast:(NSString *)macAddress deviceType:(LSDeviceType)type findCompletion:(void(^)(BOOL isSuccess))findCompletion;


- (void)cancelFindDeviceBroadcast;


- (void)checkPhoneBluetoothStatus:(id<LSBluetoothStateChangeDelegate>)stateChangeDelegate;

- (void)checkMatchWithMacAddr:(NSString *)macAddr matchBlock:(MatchBlock)matchBlock;

#pragma mark -获取系统已连接的设备
- (NSArray *)checkConnectedPeripheral:(NSArray *)targetServices;
- (void)checkConnectedPeripheral:(NSArray *)targetServices block:(void(^)(NSArray<CBPeripheral *> *))block;

- (void)cancelUpgradeDevice;
- (void)cancelUpgradeDevice:(ReturnBlock)block;

- (void)printlnReportlog;

-(void) resetWorkStatus;
/**
 *  SDK版本
 *
 *  @return 如T1.0.0
 */
+ (NSString *)version;

+ (NSUInteger)buildVersion;

// 退出 运动锻炼页面 （跑步、健走、骑行页面）
- (void)appEndPathSport;


///  连接时间统计相关
// 连接成功过程中尝试重连次数
- (NSInteger)connectSuccessTryCount:(NSString *)deviceId;

- (void)connectorDidConnectedPeripheral:(CBPeripheral *)targetPeripheral;

// 通道打开
- (void)connectEnableTimePeripheral:(CBPeripheral *)targetPeripheral;

#pragma mark - 爆款秤WIFI配置
- (void)scanWifi:(LSDeviceInfo *)deviceInfo callback:(WriteCallback)callback;

- (void)connectWifi:(LSDeviceInfo *)deviceInfo bssid:(NSString *)bssid password:(NSString *)password callback:(WriteCallback)callback;

- (void)connectA6ProtocolDevice:(LSDeviceInfo *)deviceInfo;
 
@end
