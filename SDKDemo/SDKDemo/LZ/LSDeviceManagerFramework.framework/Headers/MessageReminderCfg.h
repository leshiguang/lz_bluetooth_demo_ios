//
//  MessageReminderCfg.h
//  LSWearable
//
//  Created by Dylan on 16/3/16.
//  Copyright © 2016年 lifesense. All rights reserved.
//  消息提醒设置

#import <Foundation/Foundation.h>
#import <LSBluetooth/LSConst.h>

@interface MessageReminderCfg : NSObject

/// 是否打开消息提醒
@property (nonatomic, assign) BOOL enable;

/// 消息提醒类型
@property (nonatomic, assign) LSCallReminderAlertType type;

@end

@interface MessageReminderCfgAry : NSObject
/// 设置的运动项
@property(nonatomic, strong) NSArray<MessageReminderCfg *> *items;

@end
