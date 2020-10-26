//
//  LSConst.h
//  LSBluetooth-Library
//
//  Created by lifesense on 16/1/13.
//  Copyright © 2016年 Lifesense. All rights reserved.
//

#import <Foundation/Foundation.h>


//typedef NS_ENUM(NSUInteger, LSProtocolVer) {
//    LSProtocolVerA4 = 4, // 暂不支持
//    LSProtocolVerA5_80, // 0x80xx
//    LSProtocolVerA5_AA, // 0xAAxx
//};


typedef NS_ENUM(NSUInteger, LSSettingRespCode) {
    LSSettingRespCodeSuccess = 1,
    LSSettingRespCodeFail,
};


typedef NS_ENUM(NSUInteger, LSPlatform) {
    LSPlatformUnknown,
    LSPlatformIOS,
    LSPlatformAndroid,
    LSPlatformWP
};

/**
 * 协议版本
 */
typedef NS_ENUM(NSUInteger, LSProtocolVer) {
    LSProtocolVerNone = 0,
    LSProtocolVerA2 = 1,
    LSProtocolVerA3,
    LSProtocolVerA3_1,
    LSProtocolVerA4,
    LSProtocolVerA5,
    LSProtocolVerA5_80,
    LSProtocolVerA5_AA,
    LSProtocolVerA6_Scale,          //乐心互联体重秤
    LSProtocolVerA6_Scale_Wifi,     //爆款秤wifi配网
};

/**
 * 获取设备信息类型
 */
typedef NS_ENUM(NSUInteger, LSGetDeviceInfoType) {
    /**
     * 读取flash信息
     */
    LSGetDeviceInfoTypeReadFlashInfo,
    /**
     * 用户信息
     */
    LSGetDeviceInfoTypeReadUserInfo,
    /**
     * 闹钟设置信息
     */
    LSGetDeviceInfoTypeReadAlarmClockInfo,
    /**
     * 来电提醒设置信息
     */
    LSGetDeviceInfoTypeReadCallReminderInfo,
    /**
     * 心率检测设置信息
     */
    LSGetDeviceInfoTypeReadCheckHRInfo,
    /**
     * 久不动提醒设置信息
     */
    LSGetDeviceInfoTypeReadSedentaryInfo,
    /**
     * 防丢设置信息
     */
    LSGetDeviceInfoTypeReadProtectLostInfo
};

/**
 * 步频信息
 */
typedef NS_ENUM(NSUInteger, LSStepFreqStatus) {
    /**
     * 跑步开始
     */
    LSStepFreqStatusRunStart,
    /**
     * 跑步结束
     */
    LSStepFreqStatusRunOver,
    /**
     * 跑步暂停
     */
    LSStepFreqStatusRunPause,
    /**
     * 跑步重新开始
     */
    LSStepFreqStatusRunReStart
};
typedef LSStepFreqStatus LSWalkFreq;

typedef LSStepFreqStatus LSWalkFreq;

typedef LSStepFreqStatus LSRunningStepStatus;

typedef LSStepFreqStatus LSSportFreq;
/**
 * 每周目标
 */
typedef NS_ENUM(NSUInteger, LSWeekTarget) {
    /**
     * 步数
     */
    LSWeekTargetStep,
    /**
     * 卡路里
     */
    LSWeekTargetCalories,
    /**
     * 距离
     */
    LSWeekTargetDistance,
    /**
     * 运动量
     */
    LSWeekTargetExerciseAmount
};
//手环佩戴方式
typedef NS_ENUM(NSInteger,WearingWay)
{
    //左手佩戴
    LeftWearing,
    //右手佩戴
    RightWearing
};

//屏幕显示
typedef NS_ENUM(NSInteger,ScreenWay)
{
    //横屏
    LandScape,
    //竖屏
    VerticalScreen
};
//手环页面显示类型
typedef NS_ENUM(NSInteger,DisplayPageType)
{
    //时间
    TimePage,
    //步数
    StepPage,
    //卡路里
    CaloriesPage,
    //距离
    DistancePage,
    //心率
    HeartPage,
    //跑步
    RunningPage,
    //健走
    WalkingPage,
    //骑行
    CyclingPage,
    //游泳
    SwimmingPage,
    //健身
    FitnessPage,
    //登山
    MountainClimbingPage, // 0a
    //日常数据
    DailyDataPage, //0b
    //秒表
    StopwatchPage,  //0c
    //天气
    WeatherPage, //0d
    //电量
    ElectricityPage,//0e
    //室内跑
    IndoorRunPage = 0x0F,
    //椭圆机
    CycleMactionPage = 0x10,
    //有氧运动
    OxSportPage = 0x11,
    //12分钟跑
    twelveMinutesRunPage = 0x19,
    //6分钟跑
    sixMinutesRunPage =0x1a,
    // 篮球
    BasketballPage = 0x12, // 枚举的值必须和对应的 UI列表对应的数值对应 参见0x7E命令
    // 足球
    FootballPage = 0x13,
    // 羽毛球
    BadmintonPage = 0x14,
    // 排球
    VolleyballPage = 0x15,
    // 乒乓球
    TableTennisPage = 0x16,
    // 瑜伽
    YogaPage = 0x17,
    
    //支付宝
    zhifubao = 0x1B,
    
    // 健身舞
    GymDance = 0x1C,
    
    // 太极拳
    Taiji = 0x1D,
};

//智能心率检测
typedef NS_ENUM(NSInteger ,LSSmartHeartType)
{
    //关闭心率检测
    OffHeart,
    //开启心率检测
    OnHeart,
    //开启智能心率检测
    OnSmartHeart
};
/**
 * 震动方式
 */
typedef NS_ENUM(NSUInteger, LSShockType) {
    /**
     * 持续震动
     */
    LSShockTypeAlway,
    /**
     * 间歇震动，震动强度不变
     */
    LSShockTypeInterval,
    /**
     * 间歇震动，震动强度由小变大
     */
    LSShockTypeIntervalS2L,
    /**
     * 间歇震动，震动强度由大变小
     */
    LSShockTypeIntervalL2S,
    /**
     * 间歇震动，震动强度大小循环
     */
    LSShockTypeIntervalLoop,
};

typedef NS_ENUM(NSUInteger, LSWeek) {
    LSWeekNone,
    LSWeekMonday = 1,
    LSWeekTuesday,
    LSWeekWednesday,
    LSWeekThursday,
    LSWeekFriday,
    LSWeekSaturday,
    LSWeekSunday,
};

/**
 * Push来电提醒设置类型
 */
typedef NS_ENUM(NSUInteger, LSCallReminderAlertType) {
    /**
     * 来电提醒
     */
    LSCallReminderAlertTypeDefault,
    /**
     * 消息提醒
     */
    LSCallReminderAlertTypeMsg,
    /**
     * 断连提醒
     */
    LSCallReminderAlertTypeLost,
    /**
     * 短信提醒
     */
    LSCallReminderAlertTypeSMS,
    /**
     * 微信提醒
     */
    LSCallReminderAlertTypeWX,
    /**
     * QQ提醒
     */
    LSCallReminderAlertTypeQQ,
    /**
     * Facebook提醒
     */
    LSCallReminderAlertTypeFacebook,
    /**
     * Twitter提醒
     */
    LSCallReminderAlertTypeTwitter,
    /**
     * Line提醒
     */
    LSCallReminderAlertTypeLine,
    /**
     * Gmail提醒
     */
    LSCallReminderAlertTypeGmail,
    /**
     * KakaoTalk提醒
     */
    LSCallReminderAlertTypeKakaoTalk,
    /**
     * WhatsApp提醒
     */
    LSCallReminderAlertTypeWhatsApp,
    /**
     * SEWellness提醒
     */
    LSCallReminderAlertTypeSEWellness = 253,
    
    LSCallReminderAlertTypeCustom = 0xfe,
    
};

//Push表盘设置类型
typedef NS_ENUM(NSUInteger,LSDialModeType)
{
    /**
     * 表盘1
     */
    LSDialModeTypeOne = 1,
    /**
     * 表盘2
     */
    LSDialModeTypeTwo,
    /**
     * 表盘3
     */
    LSDialModeTypeThree,
    /**
     * 表盘4
     */
    LSDialModeTypeFour,
    /**
     * 表盘5
     */
    LSDialModeTypeFive,
    /**
     * 表盘6
     */
    LSDialModeTypeSix,
};

//Push自动识别多运类型
typedef NS_ENUM(NSUInteger,LSAutomaticSportstype)
{
    /**
     * 跑步
     */
    LSAutomaticSportstypeRunning = 1,
    /**
     * 健走
     */
    LSAutomaticSportstypeWalking = 2,
    /**
     * 骑行
     */
    LSAutomaticSportstypeCycling,
    /**
     * 游泳
     */
    LSAutomaticSportstypeSwimming,

};

//Push鼓励目标类型提醒设置
typedef NS_ENUM(NSUInteger,LSEncourageTargetType)
{
    /**
     * 步数
     */
    LSEncourageTargetTypeStepNum = 1,
    /**
     * 卡路里
     */
    LSEncourageTargetTypeCalories,
    /**
     * 距离
     */
    LSEncourageTargetTypeDistance,
};

//Push天气类型设置
typedef NS_ENUM(NSUInteger,LSWeatherType)
{
    /**
     * 晴(白天)
     */
    LSWeatherTypeSunnyDuring = 0,
    /**
     * 晴(晚上)
     */
    LSWeatherTypeSunnyNight,
    /**
     * 多云
     */
    LSWeatherTypeCloudy,
    /**
     * 晴间多云(白天)
     */
    LSWeatherTypeSunnyAndCloudyDuring,
    /**
     * 晴间多云(夜晚)
     */
    LSWeatherTypeSunnyAndCloudyNight,
    /**
     * 大部多云（白天）
     */
    LSWeatherTypeMostCloudyDuring,
    /**
     * 大部多云（夜晚）
     */
    LSWeatherTypeMostCloudyNight,
    /**
     * 阴天
     */
    LSWeatherTypeGloomy,
    /**
     * 阵雨
     */
    LSWeatherTypeShower,
    /**
     * 雷阵雨
     */
    LSWeatherTypeThunderyShower,
    /**
     * 冰雹或雷阵雨伴有冰雹
     */
    LSWeatherTypeHail,
    /**
     * 小雨
     */
    LSWeatherTypedRizzle,
    /**
     * 中雨
     */
    LSWeatherTypedModerateRain,
    /**
     * 大雨
     */
    LSWeatherTypedDownpour,
    /**
     * 暴雨
     */
    LSWeatherTypedHeavyRains,
    /**
     * 大暴雨
     */
    LSWeatherTypedBigHeavyRains,
    /**
     * 特大暴雨
     */
    LSWeatherTypedRainstorm,
    /**
     * 冻雨
     */
    LSWeatherTypedFreezingRain,
    
    /**
     * 雨夹雪
     */
    LSWeatherTypedSleet,
    /**
     * 阵雪
     */
    LSWeatherTypedSnowShower,
    /**
     * 小雪
     */
    LSWeatherTypedLightSnow,
    /**
     * 中雪
     */
    LSWeatherTypedModerateSnow,
    /**
     * 大雪
     */
    LSWeatherTypedBigSnow,
    /**
     * 暴雪
     */
    LSWeatherTypedBlizzard,
    /**
     * 浮尘
     */
    LSWeatherTypedFlyAsh,
    /**
     * 扬尘
     */
    LSWeatherTypedDust,
    /**
     * 沙尘暴
     */
    LSWeatherTypedStorms,
    /**
     * 强沙尘暴
     */
    LSWeatherTypedStrongStorms,
    /**
     * 雾
     */
    LSWeatherTypedFog,
    /**
     * 霾
     */
    LSWeatherTypedHaze,
    /**
     * 风
     */
    LSWeatherTypedWind,
    /**
     * 大风
     */
    LSWeatherTypedBigWind,
    /**
     * 飓风
     */
    LSWeatherTypedHurricane,
    /**
     * 热带风暴
     */
    LSWeatherTypedTropicalStorm,
    /**
     * 龙卷风
     */
    LSWeatherTypedTornado,

};

//手环发送运动模式类型
typedef NS_ENUM(NSUInteger,LSSportModeType)
{
    /**
     * 跑步模式
     */
    LSSportModeTypeSportMode = 1 ,
    /**
     * 健走模式
     */
    LSWalkingModeTypeSportMode,
    /**
     * 骑行模式
     */
    LSCyclingModeTypeSportMode,
    /**
     * 游泳模式
     */
    LSSwimingModeTypeSportMode,
    /**
     * 健身模式
     */
    LSKeepfitModeTypeSportMode,
    /**
     * 新跑步模式
     */
    LSRunningModeTypeSportMode, //6
    
    /**
     * 室内跑
     */
    LSIndoorRunModeTypeSportMode = 0x07,
    
    /**
     * 椭圆机
     */
    LSCycleMactionModeTypeSportMode = 0x08,
    
    /**
     * 有氧运动
     */
    LSOxSportModeTypeSportMode = 0x09,
    
    /**
     * 篮球
     */
    LSBasketballModeTypeSportMode = 0x0A,
    /**
     * 足球
     */
    LSFootballModeTypeSportMode = 0x0B,
    /**
     * 羽毛球
     */
    LSBadmintonModeTypeSportMode = 0x0C,
    /**
     * 排球
     */
    LSVolleyballModeTypeSportMode = 0x0D,
    /**
     * 乒乓球
     */
    LSTableTennisModeTypeSportMode = 0x0E,
    /**
     * 瑜伽
     */
    LSYogaModeTypeSportMode = 0x0F,
    /**
     * 电竞
     */
    LSEGameModeTypeSportMode = 0x10,
    /**
     * 有氧能力12分钟跑
     */
    LS12MinutesRunModeTypeSportMode = 0x11,
    /**
     * 有氧能力6分钟跑
     */
    LS6MinutesRunModeTypeSportMode = 0x12,
    
    //健身舞
    LSGymDanceModeTypeSportMode = 0x13,
    
    //太极拳
    LSTaijiModeTypeSportMode = 0x14,

};

//手环发送子模式类型
typedef NS_ENUM(NSUInteger, LSLaunchSportMode)
{
    //手动进入步模式
    LSLaunghSportModeLaunch,
    //自动识别模式
    LSLaunchSportModeClose,
};

//手环发送子模式类型
typedef NS_ENUM(NSUInteger, LSSubModeType)
{
    //手动进入步模式
    LSSubModeTypeManuallyEnter,
    //自动识别模式
    LSSubModeTypeAutomaticEnter,
};

//手环发送运动跑步子模式类型
typedef NS_ENUM(NSUInteger,LSSportSubModeType)
{
    //watch跑步数据
    LSSportSubModeTypeWatchSportMode,
    //自动识别跑步数据
    LSSportSubModeTypeAutoSportMode,
    //轨迹跑有通知到APP
    LSSportSubModeTypeGPSSportMode,
    //轨迹跑没有通知到APP
    LSSportSubModeTypeNoGPSSportMode
};

//手环发送新跑步子模式类型
typedef NS_ENUM(NSUInteger, LSRunningSubModeType)
{
    //手动进入跑步模式
    LSRunningSubModeTypeManuallyEnter,
    //自动识别跑步模式
    LSRunningSubModeTypeAutomaticEnter,
};

//手环发送运动健走子模式类型
typedef NS_ENUM(NSUInteger, LSWalkingSubModeType)
{
    //手动进入健走模式
    LSWalkingSubModeTypeManuallyEnter,
    //自动识别健走模式
    LSWalkingSubModeTypeAutomaticEnter,
};

//手环发送运动游泳子模式类型
typedef NS_ENUM(NSUInteger,LSSwimSubModeType)
{
    //手动进入游泳模式
    LSSwimSubModeTypeManuallyEnter,
    //自动识别游泳模式
    LSSwimSubModeTypeAutomaticEnter,
};

// 手环发送运动子模式类型 (骑行健身足篮排羽毛乒乓球瑜伽)
typedef NS_ENUM(NSUInteger, LSSportBallSubModeType)
{
    LSSportBallSubModeTypeManuallyEnter,
    LSSportBallSubModeTypeAutomaticEnter
};

//运动心率数据类型
typedef NS_ENUM(NSUInteger,LSSportHartDataType)
{
    //旧运动心率数据
    LSSportHartDataTypeOld,
    //新运动心率数据
    LSSportHartDataTypeNew,
};

//运动卡路里数据类型
typedef NS_ENUM(NSUInteger,LSSportCaloriesDataType)
{
    //旧运动卡路里数据
    LSSportCaloriesDataTypeOld,
    //新运动卡路里数据
    LSSportCaloriesDataTypeNew,
};

//手环发送运动功能检测
typedef NS_ENUM(NSUInteger,LSFunctionTestType)
{
    /**
     * 开启GPS功能检测
     */
    LSFunctionTestTypeGPS = 1,
    
    LSFunctionTestTypeSportState = 0x02,
//    0x02：运动状态,用于手环端结束手机App运动
};

//手环发送GPS状态
typedef NS_ENUM(NSUInteger,LSFunctionGPSType)
{
    /**
     * 开启GPS
     */
    LSFunctionGPSTypeOpen = 0x01,
    /**
     * 关GPS
     */
    LSFunctionGPSTypeClose = 0x00,
    /**
     * GPS开 & 定位成功
     */
    LSFunctionGPSTypeGet = 0x03,
    /**
     * 手机App拒绝运动发起
     */
    LSFunctionGPSTypeReject = 0x80,
};



//手环距离单位类型
typedef NS_ENUM(NSInteger,DistanceUnit)
{
    //公制
    DistanceUnitMetric,
    //英制
    DistanceUnitImperial,
};

//手环时间显示类型（时制）
typedef NS_ENUM(NSInteger,TimeType)
{
    //24小时制
    TimeTypeTwentyFourHoursSystem,
    //12小时
    TimeTypeTwelveHoursSystem
};

//性别
typedef NS_ENUM(NSInteger,LSGender)
{
    LSMale,
    LSFemal
};

//运动类别
typedef NS_ENUM(NSInteger,LSPeopleType)
{
    LSOrdinaryPeople,
    LSSporter
};

//目标类型
typedef NS_ENUM(NSInteger,LSTargetType)
{
    LSWeightType = 1,
    LSOther
};

//选择删除的类型
typedef NS_OPTIONS(NSUInteger, LSClearType) {
    LSClearAllData       = 1 ,
    LSClearUserData      = 1 << 1,
    LSClearSettingData   = 1 << 2,
    LSClearMeasureData   = 1 << 3
};

// 体重秤单位
typedef NS_ENUM(NSUInteger, LSWeightUnit) {
    LSWeightUnitKg = 0,     // 公斤
    LSWeightUnitLb,         // 磅
    LSWeightUnitSt,         // 英石
    LSWeightUnitJin         // 斤，找不到英文，直接用拼音
};

//时间标记类型
typedef NS_OPTIONS(NSUInteger, LSTimeFlagType) {
    LSUtcSupport       = 1 ,
    LSTimeZoneSupport  = 1 << 1,
    LSTimeStampSupport = 1 << 2,
};

// 初始化请求类型
typedef NS_OPTIONS(NSUInteger, LSInitReqType) {
    LSInitReqTypeMTU   = 1,           // 需要协商MTU
    LSInitReqTypeSL    = 1 << 1,      // 需要Slave Latency
    LSInitReqTypeSTO   = 1 << 2,      // 需要Supervisory Time Out
    LSInitReqTypeUTC   = 1 << 3,      // 请求UTC
    LSInitReqTypeTimeZone = 1 << 4,   // 请求时区
    LSInitReqTypeDate  = 1 << 5,      // 请求日期(NSDate)
};

// 测量数据包上传的数据类型
typedef NS_OPTIONS(NSUInteger, LSMeasureDataType) {
    LSMeasureDataTypeUserNumber = 1,            // 包含UserNumber
    LSMeasureDataTypeUTC = 1 << 1,              // 包含UTC
    LSMeasureDataTypeTimeZone = 1 << 2,         // 包含时区
    LSMeasureDataTypeDate = 1 << 3,             // 包含日期
    LSMeasureDataTypeBMI = 1 << 4,              // 包含BMI
    LSMeasureDataTypeBFP = 1 << 5,              // 包含Body Fat Percentage
    LSMeasureDataTypeBM = 1 << 6,               // 包含BM
    LSMeasureDataTypeMP = 1 << 7,               // 包含Muscle Percentage
    LSMeasureDataTypeMM = 1 << 8,               // 包含Muscle Mass
    LSMeasureDataTypeFFM = 1 << 9,              // 包含Fat Free Mass
    LSMeasureDataTypeSLM = 1 << 10,             // 包含Soft Lean Mass
    LSMeasureDataTypeBWM = 1 << 11,             // 包含Body Water Mass
    LSMeasureDataTypeImp = 1 << 12,             // 包含阻抗
};

//控制手环工作状态
typedef NS_ENUM(NSInteger,DeviceWorkState)
{
    //手环正常工作状态
    DeviceWorkStateNormal,
    //手环状态机复位到登录
    DeviceWorkStateLogin,
    //手环断开蓝牙连接
    DeviceWorkStateDisconnect,
};

//心率传感器接触状态
typedef NS_ENUM(NSInteger,LSSensorContactStatus)
{
    //传感器触点功能不支持
    LSSensorContactFeatureUnsupported,
    //非直接接触式的传感器触
    LSSensorContactFeatureSupportedWithoutDetected,
    //支持直接接触式的传感器触点功能
    LSSensorContactFeatureSupportedWithDetected,
};

//调用实时心率结果状态
typedef NS_ENUM(NSInteger,LSRealTimeResultStatus)
{
    //参数错误
    LSRealTimeResultStatusParametereError,
    //设备未登陆
    LSRealTimeResultStatusNotLogIn,
    //实时心率开启成功
    LSRealTimeResultStatusOpenSuccessful,
    //实时心率开启失败
    LSRealTimeResultStatusOpenFailure,
    //实时心率关闭成功
    LSRealTimeResultStatusCloseSuccessful,
    //实时心率关闭失败
    LSRealTimeResultStatusCloseFailure,
};


