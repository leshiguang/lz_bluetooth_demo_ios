//
//  LSEProductInfo.h
//  LSWearable
//
//  Created by Wenzheng Zhang on 2017/3/9.
//  Copyright © 2017年 lifesense. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 默认绑定方式
 
 - LSEDefaultBindWayQRCode: 二维码
 - LSEDefaultBindWaySNCode: SN码和QRcode
 - LSEDefaultBindWaySearch: 搜索绑定
 */
typedef NS_ENUM(NSUInteger, LSEDefaultBindWay) {
    LSEDefaultBindWayQRCode = 1,
    LSEDefaultBindWaySNCodeAndQRCode,
    LSEDefaultBindWaySearch,
    LSEDefaultBindWay1579
};

@interface FactoryProducts : NSObject
- (instancetype)initWithDict:(NSDictionary *)dict;

/**
 工厂型号
 */
@property (nonatomic, copy) NSString *model;

/**
 传输协议
 */
@property (nonatomic, copy) NSString *transferProtocal;

/**
 蓝牙广播名字
 */
@property (nonatomic, copy) NSString *bluetoothBroadcastName;

/**
 通讯方式
 1:网络,
 2: WIFI,
 3:GPRS,
 4:蓝牙,
 5:WIFI_GPRS,
 6: NB_IOT
 */
@property (nonatomic, copy) NSString *communicationType;

/**
 工厂产品类型
 体重秤("01")
 体重脂肪测量仪("02")
 手环("04")
 血糖仪("06")
 血压计("08")
 人体成分分析仪("09")
 支付卡("11")
 */
@property (nonatomic, copy) NSString *productTypeCode;

/**
 是否需要随机码，如果是蓝牙设备需要
 */
@property (nonatomic, assign) BOOL randomCode;

/**
 serviceUUID
 */
@property (nonatomic, copy) NSString *serviceUUID;

/**
 配网方式
 */
@property (nonatomic, assign) NSInteger configureManne;

/**
 产品名称
 */
@property (nonatomic, copy) NSString *name;

@end

@interface LSEProductInfo : NSObject
- (instancetype)initWithDict:(NSDictionary *)dict;

/**
 产品名称
 */
@property (nonatomic, copy) NSString *name;

/**
 设备图片Url
 */
@property (nonatomic, copy) NSString *imageUrl;
/**
 展示分类
 1:手环
 2:手表
 3:智能秤
 4:血压计
 5:乐心互联
 */
@property (nonatomic, assign) NSInteger productTypeCode;

/**
 默认绑定方式
 1.二维码
 2.sn号
 3.蓝牙
 */
@property (nonatomic, assign) NSInteger defaultBindMode;

/**
 其它绑定方式
 */
@property (nonatomic, copy) NSArray *otherBindModes;

/**
 查找蓝牙设备，过滤的mac地址前缀
 */
@property (nonatomic, copy) NSArray *servieUUIDList;

/**
 包含的工厂产品
 */
@property (nonatomic, copy) NSArray<FactoryProducts *> *factoryProducts;

@end


/**
 设备列表页面展示依赖的数据模型
 */
@interface LSProductInfoPage: NSObject

- (instancetype)initWithDict:(NSDictionary *)dict;

/**
 展示产品类型
 */
@property (nonatomic, strong) NSNumber *productType;

/**
 高亮图标图片地址
 */
@property (nonatomic, strong) NSString *highlightImageUrl;

/**
 未高亮图标图片地址
 */
@property (nonatomic, strong) NSString *noHighlightImageUrl;

/**
 展示产品类型名称
 */
@property (nonatomic, strong) NSString *productTypeName;

/**
 产品详情
 */
@property (nonatomic, strong) NSArray<LSEProductInfo *> *iotDisplayProducts;

@end

