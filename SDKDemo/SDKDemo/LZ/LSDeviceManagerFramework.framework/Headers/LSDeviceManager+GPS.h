//
//  LSDeviceManager+GPS.h
//  LSDeviceManagerFrameworkTests
//
//  Created by alex.wu on 2019/9/10.
//  Copyright © 2019 Wenzheng Zhang. All rights reserved.
//

#import "LSDeviceManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface LSDeviceManager (GPS)

/**
 设置GPS状态到手环（手环界面显示）
 
 @param enable GPS是否可用
 */
- (void)setGPSState:(NSString *)deviceId enable:(BOOL)enable completion:(Completion)completion;

/**
 设置GPS状态(轨迹跑使用)
 
 @param isUseApp true:将使用enable参数。false:组件将自己获取GPS状态，忽略enable参数
 @param enable   gps是否可用
 */
- (void)setGPSState:(BOOL)isUseApp enable:(BOOL)enable;


/**
 设置GPS是否已经获取
 
 @param received gps已获取，需要app开始后清空
 */
- (void)setGPSHasReceived:(BOOL)received;


/**
 设置用户是否拒绝等待收集GPS YES拒绝  NO默认允许
 
 @param reject 拒绝
 */
- (void)setGPSRejectReceive:(BOOL)reject;
@end

NS_ASSUME_NONNULL_END
