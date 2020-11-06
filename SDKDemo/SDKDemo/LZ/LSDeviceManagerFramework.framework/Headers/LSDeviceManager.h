//
//  LSDeviceManager.h
//  LSBluetooth-Library
//
//  Created by Dylan on 16/1/25.
//  Copyright © 2016年 Lifesense. All rights reserved.
//test
#import <Foundation/Foundation.h>
#import "LSDeviceComponentDelegate.h"
#import "WalkingData.h"
#import "WeightData.h"
#import "RunningData.h"
#import "SwimmingData.h"
#import "HeartRateData.h"
#import "SportHeartRateData.h"
#import "SleepingData.h"
#import "SportStateData.h"
#import "StepTargetCfg.h"
#import "DeviceUnitCfg.h"
#import "EncourageCfg.h"
#import "AlarmClockCfg.h"
#import "SedentaryCfg.h"
#import "AlarmClockCfg.h"
#import "WiFiCfg.h"
#import "MessageReminderCfg.h"
#import "RunningCaloriesData.h"
#import "HeartrateSwitchCfg.h"
#import "NightModeCfg.h"
#import "NoDisturbModeCfg.h"
#import "WearStateCfg.h"
#import "ScreenDirectionCfg.h"
#import "ScreenContentCfg.h"
#import "HRSectionStatisticData.h"
#import "DeviceUserInfo.h"
#import "LSEDialModelCfg.h"
#import "LSEAutomaticSportstypeCfg.h"
#import "LSEWeatherData.h"
#import "LSEDeviceInfo.h"
#import "LSESportHRSectionCfg.h"
#import "LSEHRRemindCfg.h"
#import "UWalkingData.h"
#import "LSEScaleUserInfoCfg.h"
#import "LSEScaleTargetCfg.h"

#import "LSEApplyDeviceIdInfo.h"
#import "LSEProductInfo.h"
#import "LSEManufacturerInfo.h"
#import "LSEHRSection.h"
#import "LSESwimmingInfoCfg.h"
#import "LSESportsInfoCfg.h"
#import "HFSmartLink.h"

#import "LSSportItemsCfg.h"
#import "LSDeviceManagerInfoDataSource.h"
#import "TimeFormatCfg.h"
#import "LSLocalDataHelper.h"
#import <LSBluetooth/LSBLEDeviceManager.h>
#import <LSBluetooth/LSBleDataReceiveDelegate.h>
#import <CoreMotion/CoreMotion.h>
#import "LSWifiConfig.h"

#import "BraceletReceiveDataDelegate.h"
#import "ScalesReceiveDataDelegate.h"
#import "BloodPressureReceiveDataDelegate.h"

#define system_exist @"system_exist"

#define CLASS_NAME(cls) NSStringFromClass([cls class])
#define ISRequestSuccess(code) (code == 200 ? YES : NO)
#define DLUserDefaults [NSUserDefaults standardUserDefaults]
#define MAX_LOG_SIZE (uint64_t)(1024 * 1024 * 8) // 8M的log空间


#ifndef WATCH_MODEL
#define WATCH_MODEL @"415"
#define MAMBO2_MODEL @"417"
#define ZIVA_MODEL @"418"
#define DD_MODEL @"421"
#define MID_MODEL @"422"
#define S5MINI_MODEL @"LS213-B"
#define M3_MODEL @"428"
#define M5_MODEL @"431"
#define M5_SOFTWARE_VERSION 200
#define AIR_MODEL @"426"
#define H1_MODEL @"430"

#endif


#undef NSLog

#define LSELog(...)


#if 1
#define NO_SYNC_DEVICE_STATUS    // 不上传电量信息
#endif

#define OPEN_READ_BATTERY


#define CHECK_DEVICEID()     \
if (!deviceId) { \
if (completion) { \
completion(NO); \
} \
return; \
}

//#define CLASS_NAME(cls) NSStringFromClass([cls class])
//#define CHECK_MAIN_THREAD_OPEN
#ifdef CHECK_MAIN_THREAD_OPEN
#define CHECK_MAIN_THREAD()      NSAssert([NSThread isMainThread], @"因CoreData问题，设备组件接口请放在主线程调用")
#else
#define CHECK_MAIN_THREAD()      ;
#endif

static NSString *const _kLSDMNetDisconnectedStr = @"网络未连接，请检查网络并重试";

static const NSString *DyLan = @"DyLan";

static const unsigned componentFlags = (NSCalendarUnitYear| NSCalendarUnitMonth | NSCalendarUnitDay | NSCalendarUnitWeekOfMonth |  NSCalendarUnitHour | NSCalendarUnitMinute | NSCalendarUnitSecond | NSCalendarUnitWeekday | NSCalendarUnitWeekdayOrdinal);

typedef void(^LSDMMatchBlock)(BOOL bMatch);

//#define AIRKISS_MIX 1

/**
 *  AirKiss错误代码
 */
typedef NS_ENUM(NSInteger, AirKissCode) {
    /**
     *  配对成功
     */
    AirKissSuccess = 0,
    /**
     *  配对超时
     */
    AirKissTimeOut,
    /**
     *  WIFI不能使用
     */
    AirKissWifiNotUse,
    /**
     *  出错
     */
    AirKissError,
    
};

// 配网方式
typedef enum : NSUInteger
{
    LSEWifiConfigTypeOld,       // 老产品，默认使用airkiss
    LSEWifiConfigTypeAirkiss,   // airkiss
    LSEWifiConfigTypeSmartLink, // smartlink
    LSEWifiConfigTypeUnknown, // 未知状态
} LSEWifiConfigType;

typedef enum
{
    KG=1,//千克
    JIN=2,//斤
    POUNDS = 3,//磅
    M = 4,//米
    KM =5,//公里
    St ,    // 英石
    GONGJIN,    // 中文公斤
}UnitType;

//手环距离单位类型
typedef NS_ENUM(NSInteger,DMDistanceUnit)
{
    //公制
    DMDistanceUnitMetric,
    //英制
    DMDistanceUnitImperial,
};


typedef enum
{
    Bonbon=1,
    Bonbon_C=2,//斤
    Mambo = 3,//磅
    Mambo_Call = 4,//米
    Mambo_HR =5,//公里
    Mambo_Plus,
    A3,
    Q3,
    S3,
    S1_S3,
    S1,
    A4,
    S7,
    S5,
    Melody,
    A3_F,
}DeviceName;

/**
 写入回调代码
 */
typedef enum : NSUInteger {
    /**
     *  写入成功
     */
    SettingCodeSuccess = 0,
    
    /**
     *  设备没有连接
     */
    SettingCodeNoConnect,
    
    /**
     *  不支持的Push项
     */
    SettingCodeNotSupport,
    
    /**
     *  没有设备可以写入
     */
    SettingCodeNoDevice,
    
    /**
     *  蓝牙没打开
     */
    SettingCodeBluetoothPoweredOff,
    
    /**
     *  写入失败(其它错误)
     */
    SettingCodeFailed,
} SettingCode;


/**
 乐心产品类别
 
 - LSEProductCategoryAll: 所有设备
 - LSEProductCategoryBand: 手环
 - LSEProductCategoryWatch: 手表
 - LSEProductCategoryScale: 秤
 - LSEProductCategoryBloodPressure: 血压计
 - LSEProductCategoryThirdParty: 乐心互联
 */
typedef NS_ENUM(NSUInteger, LSEProductCategory) {
    LSEProductCategoryAll,
    LSEProductCategoryBand,
    LSEProductCategoryWatch,
    LSEProductCategoryScale,
    LSEProductCategoryBloodPressure,
    LSEProductCategoryThirdParty,
};

/**
 搜索设备回调
 @param info 设备信息
 @param rssi 信号强度，越小越强
 */
typedef void(^LSESearchBlock)(LSEDeviceInfo *info, NSInteger rssi);


typedef void(^CallBackBlock)(AirKissCode code, LSEWifiConfigType type, NSUInteger time);

typedef void(^Completion)(SettingCode code);

typedef void(^UnPairBlock)(int code, NSString *msg);

typedef void(^LSEStopSearchBlock)(BOOL isStop);

typedef void(^LSEProductInfoBlock)(NSArray<LSEProductInfo *> *productInfos, NSInteger code, NSString *msg);
typedef void(^LSEManufacturerInfoBlock)(LSEManufacturerInfo *manufacturerInfo, NSInteger code, NSString *msg );


typedef void(^DeviceConnectLogBlock)(NSString *deviceId);


@class LSDeviceInfo,EncourageCfg,SedentaryCfg,AlarmClockCfg,DeviceUnitCfg;
@interface LSDeviceManager : NSObject <LSBleDataReceiveDelegate>

@property(nonatomic,weak)id<LSDeviceComponentDelegate>delegate;

/**
 设置数据源，出于性能考虑，此属性的设置方法为非线程安全，请在合适的时机初始化。dataSource的方法会在不同线程同时调用，请实现方确保线程安全
 */
@property (nonatomic, weak) id <LSDeviceManagerInfoDataSource> dataSource;

//当前用户信息
@property(nonatomic,strong)NSDictionary *currentUserInfo;

//数据Delegate
//@property (atomic, weak) id <LSDeviceManagerWeightDataDelegate> weightDataDelegate;
//@property (atomic, weak) id <LSDeviceManagerSleepDataDelegate> sleepDataDelegate;
//@property (atomic, weak) id <LSDeviceManagerSportDataDelegate> sportDataDelegate;
//@property (atomic, weak) id <LSBloodPressureDataDelegate> bloodPressureDataDelegate;

@property (atomic, weak) id <BraceletReceiveDataDelegate> braceletDataDelegate;
@property (atomic, weak) id <ScalesReceiveDataDelegate> scalesDataDelegate;
@property (atomic, weak) id <BloodPressureReceiveDataDelegate> bloodPressureDataDelegate;
 
@property (nonatomic, assign) BOOL isInBackGround;

@property (atomic, assign) BOOL canConnectPaycard;

//@property  int targetStep;

//@property EncourageCfg * encourageCfg;

@property (nonatomic, copy) NSString *currentUserId;//当前用户的userId

@property(nonatomic,strong) LSLocalDataHelper *localDataHelper;

@property UnPairBlock unPairBlock;

@property Device *curUpgradeDevice;
@property NSString *upgradeFilePath;
@property NSString *upgradeVersion;
@property NSMutableArray *bLSELogs;
@property dispatch_queue_t logQueue;
@property BOOL bLogThreadSupend;
@property dispatch_semaphore_t logSem;
@property BOOL bStopLogUpload;
@property BOOL bUpgrade;
@property NSMutableDictionary *batteryCache;

@property MatchBlock matchBlock;

@property NSTimer *batteryTimer;
@property int airKissMode; // 0：旧模块,1:新，2：混合
// 默认配网顺序
@property NSArray<NSNumber *> * wifiConfigOrders;
@property NSTimer* configWifiTimer;
@property NSUInteger configWifiTime;
@property LSEWifiConfigType wifiConfigType;
@property AirKissCode airCode;
@property NSUInteger startWifiTime;

@property int pedRequestCount;
@property BOOL isUseApp;
@property BOOL gpsIsEnable;
@property BOOL gpsHasReceived;
@property BOOL gpsRejectReceive;

//@property(nonatomic, copy)      NSString *accToken;
@property(nonatomic,strong)     WalkingData *walkingData;
@property(nonatomic,strong)     CMPedometer *stepCounter;
@property(nonatomic,copy)       CallBackBlock callBack;
@property(nonatomic,strong)     LSBLEDeviceManager *deviceManager;
@property (nonatomic,strong)    NSMutableArray* managerDelegates;
@property(nonatomic,strong)     NSMutableSet *stateDic;
@property(nonatomic,strong)     NSMutableDictionary *dic;
@property (nonatomic,strong)    NSMutableArray <NSString *>*DeviceList;
@property (nonatomic,strong)    Device *currentDevice;
@property(nonatomic,assign)     BOOL isSynM7;
@property(nonatomic,strong)     NSTimer *autoSynM7Timer;
@property(nonatomic,strong)     NSMutableArray *M7Pedometers;
@property(nonatomic,strong)     NSMutableDictionary *wifiDic;
@property(nonatomic,assign)     float currentWeight;
@property(nonatomic,assign)     NSInteger allSteps;

@property (nonatomic, copy)     NSString *batteryStatusLiveUpdateDeviceId;
@property (nonatomic, strong)   NSTimer  *batteryStatusLiveUpdateTimer;

@property (nonatomic, strong)   dispatch_queue_t  isolationQueue;

@property (nonatomic, strong) HFSmartLink *smtlk;

@property int bindState;


- (void)addDelegate:(id)delegate;

- (void)removeDlegate:(id)delegate;

- (NSArray*)getDelegates;

- (id)deleageAtIndex:(NSInteger)index;

- (void)removeAllDelegates;
/**
 *  单例初始化
 */
+ (instancetype)shareInstance;

/**
 *  检查手机计步功能
 */
- (void)checkPedometerPermisson;

/*
 * 退出登录时调用一次
 */
- (void)logout;

/*
 * 登录时调用一次
 */
- (void)loginWithUserId:(NSString *)userId;

/**
 *  获取设备组件数据库
 *
 *  @return 数据库地址，注：获取不到时为nil
 */
- (NSString *)getDeviceManagerDataBasePath;

/**
 * 设置Log文件目录，全路径
 */
+ (void)setLogDirectory:(NSString *)logPath;

/**
 *  是否开启log
 */
- (void)isOpenBluetoothLog:(BOOL)isOpen;

/**
 *  是否保存log
 */
+ (void)setSaveLog:(BOOL)log;

/**
 *  系统蓝牙没打开是否弹出提示框
 */
+ (void)setShowBleAlert:(BOOL)isShow;

- (BOOL)stopDeviceManger;

/**
 删除设备缓存

 @param userId 用户Id
 */
- (void)deleteDeviceCacheWithUserId:(NSString *)userId;

- (void)runBlockInIsolationQueue:(dispatch_block_t)block;


#pragma mark - - other
- (void)runMainBlock:(dispatch_block_t)block;


// 开始连接Block
@property (nonatomic, copy) DeviceConnectLogBlock startConnectBlock;

// 设备登录Block
@property (nonatomic, copy) DeviceConnectLogBlock loginConnectBlock;

- (void)saveDataBase;


/// 开启调试模式
- (void)openDebug;

/// 获取当前版本号
- (NSString *)getVersion;

@end





