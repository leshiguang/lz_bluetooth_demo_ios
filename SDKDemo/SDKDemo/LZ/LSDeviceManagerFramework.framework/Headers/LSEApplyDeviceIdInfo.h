//
//  LSEApplyDeviceIdInfo.h
//  LSWearable
//
//  Created by lifesense－mac on 17/3/9.
//  Copyright © 2017年 lifesense. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LSEApplyDeviceIdInfo : NSObject
//-	mac	string	否	设备mac地址
//-	hardwareVersion	string	否	硬件版本号
//-	softwareVersion	string	否	软件版本号
//-	venderId	string	否	厂商id
//-	model	string	是	工厂型号
//-	salesModel	string	是	销售型号
//-	productTypeCode	string	否	设备类型:体重秤(“01”), 体重脂肪测量仪(“02”), 手环(“04”), 血糖仪(“06”), 血压计(“08”), 人体成分分析仪(“09”)
//-	name	string	是	产品名称

/**
 设备mac地址
 */
@property (nonatomic, copy) NSString *mac;

/**
 硬件版本号
 */
@property (nonatomic, copy) NSString *hardwareVersion;

/**
 软件版本号
 */
@property (nonatomic, copy) NSString *softwareVersion;

/**
 软件版本号
 */
@property (nonatomic, copy) NSString *algorithmVersion;

/**
 厂商id
 */
@property (nonatomic, copy) NSString *venderId;

/**
 设备类型:体重秤(“01”), 体重脂肪测量仪(“02”), 手环(“04”), 血糖仪(“06”), 血压计(“08”), 人体成分分析仪(“09”)
 */
@property (nonatomic, copy) NSString *productTypeCode;

/**
 工厂型号，可选
 */
@property (nonatomic, copy) NSString *model;

/**
 销售型号，可选
 */
@property (nonatomic, copy) NSString *salesModel;

/**
 产品名称，可选
 */
@property (nonatomic, copy) NSString *name;

/**
 通讯方式:网络(1), WIFI(2), GPRS(3), 蓝牙(4), WIFI_GPRS(5)
 */
@property (nonatomic, assign) NSUInteger communicationType;

/**
 第三方设备唯一标识
 */
@property (nonatomic, copy) NSString *thirdDeviceId;

/**
 设备广播ID
 */
@property (nonatomic, copy) NSString *broadcastId;

@end
