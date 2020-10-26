//
//  LSDeviceManager+BraceletSetting.h
//  LSDeviceManagerFrameworkTests
//
//  Created by wm on 2020/9/23.
//  Copyright © 2020 Wenzheng Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSDeviceManager.h"
#import "LSBraceletSettingState.h"

NS_ASSUME_NONNULL_BEGIN

@interface LSDeviceManager (BraceletSetting)

#pragma mark -
#pragma mark - 新的设置项接口

/// 设置手环设置项
/// @param data 设置数据model
/// @param deviceId 设备Id
/// @param setType 设置项类型
/// @param completion 设置回调
- (void)setBraceletWithData:(id)data deviceId:(NSString *)deviceId setType:(LSBraceletSettingStateType)setType completion:(Completion)completion;


/// 获取手环设置项
/// @param deviceId 设备Id
/// @param setType 设置项类型
- (id)redBraceletWithDeviceId:(NSString *)deviceId setType:(LSBraceletSettingStateType)setType;


#pragma mark -
#pragma mark - 老接口将废弃

/// 读取游泳的相关信息
/// @param deviceId 设备Id
- (LSESwimmingInfoCfg *)getSwimmingInfo:(NSString *)deviceId;


/// 设置游泳的相关信息
/// @param deviceId 设备Id
/// @param cfg 模式
/// @param completion 回调
- (void)setSwimmingInfo:(NSString *)deviceId cfg:(LSESwimmingInfoCfg *)cfg completion:(Completion)completion;

/// 设置步数目标
/// @param deviceId 设备id
/// @param step 步数目标
/// @param completion 回调
- (void)setStepTarget:(NSString *)deviceId step:(StepTargetCfg *)step completion:(Completion)completion;

/// 查询步数目标
/// @param deviceId 设备id
- (StepTargetCfg *)getStepTarget:(NSString *)deviceId;

/// 运动项内容设置
/// @param deviceId 设备Id
/// @param items 设置的运动项内容 （see: LSSportItemType）
/// @param completion 回调
- (void)setSportItems:(NSString *)deviceId items:(NSArray<LSSportItemSwitch *> *)items completion:(Completion)completion;

/// 获取运动项设置的配置
/// @param deviceId 设备Id
- (NSArray<LSSportItemSwitch *> *)getSportItem:(NSString *)deviceId;

/// 步数、卡路里、距离目标设置
/// @param deviceId 设备id
/// @param config 鼓励设置模型
/// @param completion 回调
- (void)setEncourage:(NSString *)deviceId config:(EncourageCfg *)config completion:(Completion)completion;

/// 步数、卡路里、距离目标设置
/// @param deviceId 设备id
- (EncourageCfg *)getEncourage:(NSString *)deviceId;

/// 久坐提醒设置
/// @param deviceId 设备id
/// @param config 配置
/// @param completion 回调
- (void)setSedentary:(NSString *)deviceId config:(SedentaryCfg *)config completion:(Completion)completion;

/// 查询久坐提醒
/// @param deviceId 设备id
- (SedentaryCfg *)getSedentary:(NSString *)deviceId;

/// 连续心率监测
/// @param deviceId 设备Id
/// @param state model
/// @param completion 回调
- (void)setHeartRateMeatureState:(NSString *)deviceId state:(HeartrateSwitchCfg *)cfg completion:(Completion)completion;

/// 查询心率监测状态
/// @param deviceId 设备Id
- (HeartrateSwitchCfg *)getHeartRateMeatureState:(NSString *)deviceId;

/// 设置心率预警
/// @param de
/// @param cfg 配置项
/// @param completion 回调
- (void)setSportHeartRateSectionRemind:(NSString *)deviceId heartRateCfg:(LSEHRRemindCfg *)cfg completion:(Completion)completion;

/// 获取心率预警设置
/// @param deviceId 设备Id
- (LSEHRRemindCfg *)getHeartRateRemind:(NSString *)deviceId;

/// 设置夜间模式
/// @param deviceId 设备Id
/// @param mode 夜间模式设置内容，具体请看NightModeCfg
/// @param completion 设置是否成功回调
- (void)setNightMode:(NSString *)deviceId mode:(NightModeCfg *)mode completion:(Completion)completion;

/// 获取夜间模式设置
/// @param deviceId 设备Id
- (NightModeCfg *)getNightMode:(NSString *)deviceId;


/// 消息提醒设置
/// @param deviceId 设备id
/// @param cfg 设置model
/// @param completion 回调
- (void)setMsgReminder:(NSString *)deviceId messageReminderCfg:(MessageReminderCfg *)cfg completion:(Completion)completion;

/// 获取消息提醒设置数组
/// @param deviceId 设备id
- (NSArray <MessageReminderCfg *> *)getMsgReminder:(NSString *)deviceId;

/// 查询消息提醒是否打开
/// @param deviceId 设备id
/// @param type 消息类型
- (BOOL)isEnableMsgReminder:(NSString *)deviceId type:(LSCallReminderAlertType)type;


/// 设置勿扰模式
/// @param deviceId 设备id
/// @param mode 数据model
/// @param completion 回调
- (void)setNotDistrubMode:(NSString *)deviceId mode:(NoDisturbModeCfg *)mode completion:(Completion)completion;

/// 获取勿扰模式设置
/// @param deviceId 设备id
- (NoDisturbModeCfg *)getNotDistrubMode:(NSString *)deviceId;

/// 设置时间制式
/// @param deviceId 设备id
/// @param mode 数据model
/// @param completion 回调
- (void)setTimeTypeSetting:(NSString *)deviceId mode:(TimeFormatCfg *)mode completion:(Completion)completion;

/// 获取时间制式设置
/// @param deviceId 设备Id
- (TimeFormatCfg *)getTimeFormat:(NSString *)deviceId;

/// 设置手环佩戴方式
/// @param deviceId 设备Id
/// @param cfg 设置model
/// @param completion 设置是否成功回调
- (void)setWristState:(NSString *)deviceId state:(WearStateCfg *)cfg completion:(Completion)completion;

/// 获取手环佩戴方式
/// @param deviceId 设备Id
- (WearStateCfg  *)getWristState:(NSString *)deviceId;

/// 设置手环显示方向
/// @param deviceId 设备Id
/// @param cfg 手环显示方向model
/// @param completion 设置是否成功回调
- (void)setScreenDirection:(NSString *)deviceId cfg:(ScreenDirectionCfg *)cfg completion:(Completion)completion;

/// 获取手环显示方向
/// @param deviceId 设备Id
- (ScreenDirectionCfg *)getScreenDirection:(NSString *)deviceId;

/// 自定义页面显示
/// @param deviceId 设备Id
/// @param content 手环显示的页面(显示的类型请看ScreenContentType)
/// @param completion 设置是否成功回调
- (void)setScreenContent:(NSString *)deviceId content:(NSArray<ScreenContentSwitch *> *)content completion:(Completion)completion;

/// 获取自定义页面配置
/// @param deviceId 设备Id
- (NSArray<ScreenContentSwitch *> *)getScreenContent:(NSString *)deviceId;

/// 设置自动识别多运动开关到手环
/// @param deviceId 设备id
/// @param automaticSports 设置数据model
/// @param completion 回调
- (void)setAutomaticSports:(NSString *)deviceId automaticSports:(NSArray<LSEAutomaticSportstypeCfg*> *)automaticSports completion:(Completion)completion;

/// 获取自动识别多运动开关设置的信息
/// @param deviceId 设备id
- (NSArray <LSEAutomaticSportstypeCfg *> *)getAutomaticSportsSetting:(NSString *)deviceId;

/// 设置手环表盘设置到手环
/// @param deviceId 设备id
/// @param cfg 设置项model
/// @param completion 回调
- (void)setDialType:(NSString *)deviceId dialType:(LSEDialModelCfg *)cfg completion:(Completion)completion;

/// 获取手环表盘的设置模式
/// @param deviceId 设备id
- (LSEDialModelCfg *)getDialType:(NSString *)deviceId;

/// 设置天气信息到蓝牙手环
/// @param deviceId 设备id
/// @param weatherData 数据model
/// @param completion 回调
- (void)setWeatherData:(NSString *)deviceId weatherData:(LSEWeatherData *)weatherData completion:(Completion)completion;

/// 设置闹铃
/// @param deviceId 设备id
/// @param configs 数据model
/// @param completion 回调
- (void)setAlarmClock:(NSString *)deviceId configs:(NSArray <AlarmClockCfg *>*)configs completion:(Completion)completion;

/// 查询闹铃设置
/// @param deviceId 设备id
- (NSArray <AlarmClockCfg *>*)getAlarmClockTarget:(NSString *)deviceId;

/// 设备支持的最大闹钟数量
/// @param deviceId 设备id
/// @param result 查询结果
- (void)getMaxAlarmClockCount:(NSString *)deviceId result:(void(^)(NSUInteger count))result;

/// 移除闹钟
/// @param deviceId 设备id
/// @param cfg AlarmClockCfg
- (void)delAlarmClockTarget:(NSString *)deviceId eventRemind:(AlarmClockCfg *)cfg completion:(Completion)completion;

/// 设置多运动的相关信息
/// @param deviceId 设备Id
/// @param cfg 配置
/// @param completion 回调
- (void)setSportsInfo:(NSString *)deviceId cfg:(LSESportsInfoCfg *)cfg completion:(Completion)completion;









































//
///**
// 异步查询设备支持的最大闹钟数量
// 
// @param deviceId 设备id
// @param result  查询结果
// */
//- (void)getMaxAlarmClockCount:(NSString *)deviceId result:(void(^)(NSUInteger count))result;
//
//
////- (void)setTimeTypeSetting:(LSDeviceInfo *)deviceInfo timeType:(TimeType)type callback:(WriteCallback)callback
//
//
///**
// *  来电提醒开关
// *
// *  @param deviceId   设备ID
// *  @param enable     是否启用
// *  @param completion 设置完成后的回调
// */
////- (void)enableCallReminder:(NSString *)deviceId enable:(BOOL)enable completion:(Completion)completion;
//
///**
// *  获取是否开启来电
// *
// *  @param deviceId 设备ID
// *
// *  @return YES/NO
// */
////- (BOOL)isOpenCallReminder:(NSString *)deviceId;
//
//
///**
// 设置单位到手环
// 
// @param deviceId 手环
// @param type 单位
// @param completion 回调
// */
//- (void)setDistanceUnitSetting:(NSString *)deviceId distanceUnit:(DMDistanceUnit)type completion:(Completion)completion;
//
//
//
///**
// *  设置鼓励目标类型提醒设置到蓝牙手环
// *
// */
//- (void)setEncourageType:(NSString *)deviceId isOpen:(BOOL)isOpen targetType:(LSEEncourageTargetType)targetType targetValue:(double)targetValue completion:(Completion)completion;
//
///**
// *  获取手环鼓励目标类型设置的信息
// *
// */
//- (EncourageCfg *)getEncourageType:(NSString *)deviceId;
//
//
//
///**
// *  添加事件提醒信息
// *
// */
//- (void)addEventRemind:(NSString *)deviceId eventRemind:(AlarmClockCfg *)eventRemind completion:(Completion)completion;
//
///**
// 存储设置  3.7.4 add by tj ,仅仅只是暴露接口
// 
// @param deviceId 设备Id
// @param eventRemind 闹钟
// @param isDelete 是否删除
// */
//- (void)saveEventRemind:(NSString *)deviceId eventRemind:(AlarmClockCfg *)eventRemind isDelete:(BOOL)isDelete;
//
/**
 *
 *
 */
//
///**
// *  删除事件提醒信息
// *
// */
//- (void)deleteEventRemind:(NSString *)deviceId eventRemind:(AlarmClockCfg *)eventRemind completion:(Completion)completion;
//
///**
// *  获取事件提醒设置信息
// *
// */
//- (NSArray <AlarmClockCfg *> *)getEventReminds:(NSString *)deviceId;


@end

NS_ASSUME_NONNULL_END
