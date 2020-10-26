//
//  LSEDeviceInfo.h
//  LSWearable
//
//  Created by lifesense－mac on 17/3/1.
//  Copyright © 2017年 lifesense. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LSEDeviceInfo : NSObject
/// 设备展示名称
@property (nonatomic, copy) NSString *displayName;
/// 设备广播名
@property (nonatomic, copy) NSString *name;
/// 设备MAC地址
@property (nonatomic, copy) NSString *mac;
/// 型号
@property (nonatomic ,strong) NSString *model;
/// 协议版本
@property (nonatomic ,strong) NSString *protocolType;
/// rssi 信号强度，越小越强
@property (nonatomic, assign) NSInteger rssi;
/// 是否注册
@property (nonatomic, assign) BOOL isReg;
/// 厂商ID
@property (nonatomic, strong) NSString *vendorID;
/// 广播Id
@property (nonatomic, strong) NSString *broadcastId;
/// 设备类型
@property (nonatomic, assign) int deviceType;
@end
