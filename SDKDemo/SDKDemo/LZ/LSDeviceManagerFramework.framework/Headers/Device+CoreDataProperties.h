//
//  Device+CoreDataProperties.h
//  LSWearable
//
//  Created by hanfeng.li on 2017/3/29.
//  Copyright © 2017年 lifesense. All rights reserved.
//

#import "Device+CoreDataClass.h"
#import "LSEDialProertyValue.h"


/**
 * 设备类型：01 体重秤、02 脂肪秤、03 身高、04 计步器、
 * 05  腰围尺、06 血糖仪、07 体温计、08 血压计、09 厨房秤、10 手环、14 第三方设备-智能枕头
 */
typedef enum
{
    UNKONW=0,
    WEIGHT_SCALE=1,
    FAT_SCALE = 2,
    HEIGHT_MIRIAM = 3,
    PEDOMETER =4,
    WAISTLINE_MIRIAM=5,
    GLUCOSE_METER=6,
    THERMOMETER=7,
    SPHYGMOMETER =8,
    KITCHEN_SCALE = 9,
    BAND,
    PAYCARD,
    THIRDDEVICE_SLEEPACE,
}DeviceType;


NS_ASSUME_NONNULL_BEGIN

@interface Device (CoreDataProperties)

+ (NSFetchRequest<Device *> *)fetchRequest;

@property (nullable, nonatomic, copy) NSNumber *battery;
@property (nullable, nonatomic, copy) NSNumber *bindTime;
@property (nullable, nonatomic, copy) NSString *broadcastId;
@property (nullable, nonatomic, copy) NSNumber *communicationType;
@property (nullable, nonatomic, copy) NSNumber *created;
@property (nullable, nonatomic, copy) NSString *hardwareVersion;
@property (nullable, nonatomic, copy) NSString *id;
@property (nullable, nonatomic, copy) NSString *imgUrl;
@property (nullable, nonatomic, copy) NSString *imsi;
@property (nullable, nonatomic, copy) NSNumber *isDelete;
@property (nullable, nonatomic, copy) NSString *mac;
@property (nullable, nonatomic, copy) NSString *model;
@property (nullable, nonatomic, copy) NSString *name;
@property (nullable, nonatomic, copy) NSString *password;
@property (nullable, nonatomic, copy) NSString *picture;
@property (nullable, nonatomic, copy) NSString *productTypeCode;
@property (nullable, nonatomic, copy) NSString *protocolType;
@property (nullable, nonatomic, copy) NSString *qrcode;
@property (nullable, nonatomic, copy) NSString *salesModel;
@property (nullable, nonatomic, copy) NSNumber *sleepSupport;
@property (nullable, nonatomic, copy) NSString *sn;
@property (nullable, nonatomic, copy) NSString *sn8;
@property (nullable, nonatomic, copy) NSString *softwareVersion;
@property (nullable, nonatomic, copy) NSString *algorithmVersion;
@property (nullable, nonatomic, copy) NSNumber *syncFlag;
@property (nullable, nonatomic, copy) NSNumber *updated;
@property (nullable, nonatomic, copy) NSString *venderId;
@property (nullable, nonatomic, copy) NSString *productProperties;
@property (nullable, nonatomic, copy) NSString *simpleName;
@property (nullable, nonatomic, copy) NSString *thirdDeviceId;
@property (nullable, nonatomic, copy) NSString *operationGuide;
/**
 * 是否激活；1-激活；0未激活
 **/
@property (nullable, nonatomic, copy) NSNumber *isActive;

/**
 * 最近同步数据时间
 **/
@property (nullable, nonatomic, copy) NSNumber *lastDataTime;

@property (nonatomic, assign, readonly) DeviceType deviceType;

//表盘图片地址列表
- (NSArray<LSEDialProertyValue *> *)getDialProperties;

//获取简单名称
- (NSString *)getSimpleNameStr;
@end

NS_ASSUME_NONNULL_END
