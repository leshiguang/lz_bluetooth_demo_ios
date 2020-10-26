//
//  libCommon.h
//  libCom
//
//  通用函数、宏
//
//  Created by Damein on 15/8/18.
//  Copyright (c) 2015年 Damein. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSLog.h"
#import "LSDeviceInfo.h"

//#if (DEBUG == 1)
//#define MLog(fmt,...) [LSLog log:@"app" isSave:NO format:fmt,##__VA_ARGS__]
#define MLogF(fmt,...) [LSLog log:@"app" isSave:YES format:fmt,##__VA_ARGS__]
#define MLogT(tag,fmt,...) [LSLog log:tag format:fmt,##__VA_ARGS__]

//#else
#define MLog         NSLog// 忽略log信息
//#endif

#define RGB(r,g,b) [UIColor colorWithRed:r / 255.f green:g / 255.f blue:b / 255.f alpha:1]
#define RGBA(r,g,b,a) [UIColor colorWithRed:r / 255.f green:g / 255.f blue:b / 255.f alpha:a / 100.f]



/**
 * 历史数据同步标志
 */
typedef NS_ENUM(NSUInteger, LSHistoryDataSyncFlag)
{
    /**
     * 同步开始
     */
    LSHistoryDataSyncFlagStart,
    
    /**
     * 同步过程百分比
     */
    LSHistoryDataSyncFlagPrecent,
    
    /**
     * 同步结束
     */
    LSHistoryDataSyncFlagEnd,
};



/**
 设备功能
 */
typedef enum : NSUInteger {
    /**
     *  计步
     */
    DFStepCounter,
    
    /**
     *  心率
     */
    DFHeartRate,
    
    /**
     *  闹钟
     */
    DFAlarmClock,
    
    /**
     *  睡眠
     */
    DFSleepMonitoring,
    
    /**
     *  跑步模式
     */
    DFSportMode,
    
    /**
     *  更新手环的用户信息
     */
    DFUpdateDeviceUserInfo,
    
    /**
     *  消息提醒设置
     */
    DFMessageReminderSetting,
    
    /**
     *  来电提醒设置
     */
    DFCallReminderSetting,
    
    /**
     *  短信提醒设置
     */
    DFSMSReminderSetting,
 
    /**
     *  微信提醒设置
     */
    DFWXReminderSetting,

    /**
     *  久坐提醒设置
     */
    DFSedentarySetting,
    
    /**
     *  鼓励设置
     */
    DFEncourageSetting,
    
    /**
     *  防丢设置
     */
    DFLostSetting,
    
    /**
     *  每周目标设置
     */
    DFWeekTargetSetting,
    
    /**
     *  心率检测设置
     */
    DFHeartRateSetting,
    
    /**
     *  心率区间设置
     */
    DFHeartRateSectionSetting,
    
    /**
     *  运动区间心率上下限设置
     */
    DFSportHeartRateSetting,
    
    /**
     *  获取设置信息功能
     */
    DFGetSettingInfo,
    
    /**
     *  获取设备电压
     */
    DFGetDeviceVoltage,
    
    /**
     *  夜间模式设置
     */
    DFNightModeSetting,
    
    /**
     *  勿扰模式设置
     */
    DFNotDisturbModeSetting,

    
    /**
     *  佩戴习惯(左、右手)设置
     */
    DFWristHabitSetting,
    
    /**
     *  屏幕方向(横屏、竖屏)设置
     */
    DFScreenDirectionSetting,
    
    /**
     *  自定义屏幕显示内容设置
     */
    DFCustomScreenContentSetting,
    
    /**
     *  智能心率设置
     */
    DFSmartHeartRateSetting,
    
    /**
     * 跑步卡路里数据
     */
    DFRunningCalorie,
    /**
     * 功能检测
     */
    DFFunctionTest,
    
} DeviceFunction;



/**
 写入回调代码
 */
typedef enum : NSUInteger {
    /**
     *  写入成功
     */
    WriteRespSuccess = 0,
    
    /**
     *  设备没有连接
     */
    WriteRespNoConnect,
    
    /**
     *  不支持的Push项
     */
    WriteRespNotSupport,
    
    /**
     *  没有设备可以写入
     */
    WriteRespNoDevice,
    
    /**
     *  蓝牙没打开
     */
    WriteRespBluetoothPoweredOff,
    
    /**
     *  写入失败(其它错误)
     */
    WriteRespFailed,
} WriteRespCode;

/**
 绑定操作状态
 */
typedef enum : NSUInteger {
 
    /**
     *  输入随机数 (返回此状态,用户需要调用LSBLEDeviceManager的用户绑定手环校验随机码接口)
     */
    LSBindInputRandomNumber,
    
    /**k
     *  确认配对 (返回此状态,用户需要调用LSBLEDeviceManager的用户确认配对接口)
     */
    LSBindMatchingConfirmation,
    
    /**
     *  未注册通知  /A6
     */
    LSBindUnregister,
    
    /**
     *  请输入用户编号和绑定结果 /A6
     */
    LSBindInputUserNumberAndBindResult,
    
    /**
     *  绑定成功
     */
    LSBindSuccessful,
    
    /**
     *  绑定失败
     */
    LSBindFailure,
    
    /**
     *  解绑成功
     */
    LSBindRemoveBindSuccessful,
    
    /**
     *  解绑失败
     */
    LSBindRemoveBindFailure,
    
    /**
     *  取消绑定
     */
    LSBindCancelBind,
    
    /**
     *  取消解绑
     */
    LSBindCancelRemoveBind,
    
    /**
     *  未知状态
     */
    LSBindUnknown,

    
} LSBindCode;

/**
 设备注册状态
 */
typedef enum : NSUInteger {
    
    /**
     *  正常未注册的设备
     */
    LSRegisterNormal = 1,
    
    /**
     *  已注册，不再分配Device ID
     */
    LSRegisterRegistered,
    
    /**
     *  非法
     */
    LSRegisterIllegal,
    
    //预留
    
} LSRegisterCode;

/**
 设备绑定结果
 */
typedef enum : NSUInteger {
    
    /**
     *  绑定成功
     */
    LSDeviceBindResultCodeBindSuccessful = 1,
    
    /**
     *  绑定失败
     */
    LSDeviceBindResultCodeBindFailure,
    
    /**
     *  设备未注册，需要先注册
     */
    LSDeviceBindResultCodeUnregistered,
    
    /**
     *  非法
     */
    LSDeviceBindResultCodeIllegal,
    
    //预留
    
} LSDeviceBindResultCode;

// 一个空的block,没有返回值也没有参数
typedef void(^EmptyBlock)();
/**
 *  写入数据回调
 *
 *  @param code 写入数据回调代码
 */
typedef void(^WriteCallback)(WriteRespCode code);

/**
 *  绑定操作状态回调
 *
 *  @param code 绑定操作状态回调代码
 */
typedef void(^BindCallback)(LSDeviceInfo *deviceInfo, LSBindCode code);
// 对分配和释放内存的封装
#define LSMalloc(type,size) (type*)malloc(size)
#define LSFree(inst) if(inst){free(inst);inst = NULL;}
#define BZero(inst,size) bzero(inst,size)

//int类型移位
#define INTSHIFT(intValue) ((intValue & 0x000000FF) << 24) | ((intValue & 0x0000FF00) << 8) | ((intValue & 0x00FF0000) >> 8) | ((intValue & 0xFF000000) >> 24)

//short类型移位
#define ShortSHIFT(shortValue) (((shortValue & 0x00FF) << 8) |((shortValue & 0xFF00) >>8))

// 获取位,从0开始
#define GetBit(value, bit) (((value)&(1<<bit))?1:0)
// 设置位为1，从0开始
#define SetBit(value, bit) ((value)|(1<<bit))
// 设置位为0，从0开始
#define ClearBit(value, bit) ((value)&(~(1<<bit)))

#define NSSF(format,...) [NSString stringWithFormat:format,__VA_ARGS__]


#define NSUserDefaultsInst [NSUserDefaults standardUserDefaults]

// 屏幕宽
#define SCREEN_WIDTH [UIScreen mainScreen].bounds.size.width

// 屏幕高
#define SCREEN_HEIGHT [UIScreen mainScreen].bounds.size.height

// 创建一个weak变量
#define WeakVar(weakVar,var) __weak typeof(var) weakVar = var

// 创建一个strong变量
#define StrongVar(strongVar,var) __strong __typeof(var) strongVar = var

// 声明一个单例
#define Create_Singleton_Def() + (instancetype)shared

// 实现一个单例
#define Create_Singleton_Imp(cls) \
+ (instancetype)shared \
{ \
    static cls *_gs_cls = nil; \
    static dispatch_once_t onceToken; \
    dispatch_once(&onceToken, ^{ \
        if (!_gs_cls) { \
            _gs_cls = [cls new]; \
        } \
    }); \
    return _gs_cls; \
} \

#pragma mark 通知中心

/**
 *  添加一个消息监听到通知中心
 *
 *  @param observer
 *  @param selector
 *  @param name     监听的名字
 */
void addPost(id observer, SEL selector,NSString *name);

/**
 *  通过名字删除消息监听
 *
 *  @param observer
 *  @param name     监听的名字
 */
void removePost(id observer,NSString *name);

/**
 *  发送一个消息监听
 *
 *  @param name   监听的名字
 *  @param object 发送的数据，没有就填nil
 */
void post(NSString *name,id object);

#pragma mark 其它

/**
 *  调用target里面的sel方法，新的SDK会报警告，这里统一调这个接口，可去掉警告
 *
 *  @param target 目标实例
 *  @param sel    selector方法
 *  @param object 要传的数据
 */
void performSelector(id target,SEL sel,id object);

// int大小端互转
unsigned short ConvertShortEndian(unsigned short s);

// short大小端互转
unsigned int ConvertIntEndian(unsigned int n);


#pragma mark 乐心通用函数
// 浮点型转整型，精度两位小数
// 低三个字节是数据，高一个字节是带符号数的10的指数
// 0X0013C3=5059
// 0XFE=-2
// 5059*10^(-2)=50.59Kg
int ls_Float2Int(float value);
// 整型转浮点型
float ls_Int2Float(int value);
// 把时分转换成short
short ls_Time2Short(char hour, char minute);
// 把short转换成时分
void ls_Short2Time(short time, char *hour, char *minute);
// 把short转换成sfloat
float ls_Short2SFloat(short value);

NSData *ls_strMac2DataMac(NSString *strMac);
NSString *ls_dataMac2StrMac(NSData *data);


#pragma mark 设备功能判断

/**
 *  获取设备类型
 *
 *  @param model   型号
 *  @param softVer 固件版本
 *  @param hardVer 硬件版本
 *
 *  @return 设备类型
 */
//DeviceType getDeviceType(NSString *model, NSString *softVer, NSString *hardVer);


/**
 *  指定设备是否支持指定的功能
 *
 *  @param model   型号
 *  @param softVer 固件版本
 *  @param hardVer 硬件版本
 *  @param dFun    欲检测的功能
 *
 *  @return 是/否
 */
BOOL isSupportDeviceFunction(NSString *model, NSString *softVer, NSString *hardVer, DeviceFunction dFun);





