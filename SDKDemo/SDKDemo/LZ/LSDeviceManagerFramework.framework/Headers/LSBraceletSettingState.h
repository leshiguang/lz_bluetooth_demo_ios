//
//  LSBraceletSettingState.h
//  LSDeviceManagerFrameworkTests
//
//  Created by wm on 2020/9/24.
//  Copyright © 2020 Wenzheng Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LSBraceletSettingState : NSObject

typedef enum : NSUInteger {
    LSSwimmingLenghtSetType,            ///< 设置游泳池长度
    LSSportPagesSetType,                ///< 运动项设置
    LSStepTargetSetType,                ///< 设置步数目标
    LSHeartRateMeatureSetType,          ///< 心率监测设置
    LSEncourageSetType,                 ///< 步数、卡路里、距离目标设置
    LSSedentaryInfoType,                ///< 久坐提醒设置
    LSHeartRateRemindSetType,           ///< 心率预警
    LSNightModeSetType,                 ///< 夜间模式设置
    LSMsgReminderSetType,               ///< 消息提醒
    LSNoDisturbModeSetType,             ///< 勿扰模式
    LSTimeTypeSetType,                  ///< 时间制式
    LSWristStateSettype,                ///< 佩戴习惯
    LSScreenDirectionSetType,           ///< 设置屏幕方向
    LSScreenContentSetType,             ///< 自定义屏幕
    LSAutomaticSportsSetType,           ///< 自动识别多运动类型
    LSDialTypeSetType,                  ///< 设置手环表盘
    LSWeatherDataSetType,               ///< 设置天气
    LSSportInfoSetType,                 ///< 设置运动信息
    LSAlarmClockSetType,                ///< 设置闹铃

} LSBraceletSettingStateType;


/// 数据类型（LSBraceletSettingStateType）和 数据model具有映射关系，通过这个方法可以按到对应的类名
/// @param state 运动类型
extern NSString * NSStringFromSettingState(LSBraceletSettingStateType state);

@end

NS_ASSUME_NONNULL_END
