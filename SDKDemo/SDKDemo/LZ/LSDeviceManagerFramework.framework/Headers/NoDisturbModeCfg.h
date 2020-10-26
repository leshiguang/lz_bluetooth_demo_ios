//
//  NoDisturbModeCfg.h
//  LSDeviceManagerFrameworkTests
//
//  Created by boluobill on 2018/8/22.
//  Copyright © 2018 Wenzheng Zhang. All rights reserved.
//  设置勿扰模式

#import <Foundation/Foundation.h>

@interface NoDisturbModeCfg : NSObject

/// 是否打开勿扰模式
@property (nonatomic, assign) BOOL isOpen;
/// 勿扰模式下是否抬手亮屏
@property (nonatomic, assign) BOOL isRaise;
/// 开始时间（时）
@property (nonatomic, assign) NSUInteger startHour;
/// 开始时间（分）
@property (nonatomic, assign) NSUInteger startMinute;
/// 结束时间（时）
@property (nonatomic, assign) NSUInteger endHour;
/// 结束时间（分）
@property (nonatomic, assign) NSUInteger endMinute;

@end
