//
//  braceletReceiveData.h
//  LSDeviceManagerFrameworkTests
//
//  Created by wm on 2020/9/16.
//  Copyright © 2020 Wenzheng Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BraceletReceiveData : NSObject

/// 数据唯一id UUID
@property (nonatomic, copy) NSString *dataId;

/// 用户id
@property (nonatomic, copy) NSNumber *userId;

/// 设备id 必传
@property (nonatomic, copy) NSString *deviceId;

/// 软件版本
@property (nonatomic, copy) NSString *softVer;

/// 设备型号
@property (nonatomic, copy) NSString *model;

@end

NS_ASSUME_NONNULL_END
