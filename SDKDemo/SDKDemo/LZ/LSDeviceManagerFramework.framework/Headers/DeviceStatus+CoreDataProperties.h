//
//  DeviceStatus+CoreDataProperties.h
//  LSWearable
//
//  Created by hanfeng.li on 2017/3/29.
//  Copyright © 2017年 lifesense. All rights reserved.
//

#import "DeviceStatus+CoreDataClass.h"


NS_ASSUME_NONNULL_BEGIN

@interface DeviceStatus (CoreDataProperties)

+ (NSFetchRequest<DeviceStatus *> *)fetchRequest;

@property (nullable, nonatomic, copy) NSNumber *battery;
@property (nullable, nonatomic, copy) NSNumber *batteryChangeTime;
@property (nullable, nonatomic, copy) NSNumber *created;
@property (nullable, nonatomic, copy) NSString *deviceId;
@property (nullable, nonatomic, copy) NSString *id;
@property (nullable, nonatomic, copy) NSNumber *isDelete;
@property (nullable, nonatomic, copy) NSNumber *netType;
@property (nullable, nonatomic, copy) NSNumber *online;
@property (nullable, nonatomic, copy) NSNumber *syncFlag;
@property (nullable, nonatomic, copy) NSNumber *updated;

@end

NS_ASSUME_NONNULL_END
