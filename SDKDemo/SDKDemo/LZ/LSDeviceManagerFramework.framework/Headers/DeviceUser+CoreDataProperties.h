//
//  DeviceUser+CoreDataProperties.h
//  LSWearable
//
//  Created by hanfeng.li on 2017/3/29.
//  Copyright © 2017年 lifesense. All rights reserved.
//

#import "DeviceUser+CoreDataClass.h"


NS_ASSUME_NONNULL_BEGIN

@interface DeviceUser (CoreDataProperties)

+ (NSFetchRequest<DeviceUser *> *)fetchRequest;

@property (nullable, nonatomic, copy) NSNumber *birthday;
@property (nullable, nonatomic, copy) NSNumber *created;
@property (nullable, nonatomic, copy) NSString *deviceId;
@property (nullable, nonatomic, copy) NSString *headimg;
@property (nullable, nonatomic, copy) NSNumber *height;
@property (nullable, nonatomic, copy) NSString *id;
@property (nullable, nonatomic, copy) NSNumber *isDelete;
@property (nullable, nonatomic, copy) NSString *nickname;
@property (nullable, nonatomic, copy) NSNumber *sex;
@property (nullable, nonatomic, copy) NSNumber *syncFlag;
@property (nullable, nonatomic, copy) NSNumber *updated;
@property (nullable, nonatomic, copy) NSNumber *userId;
@property (nullable, nonatomic, copy) NSNumber *userNo;
@property (nullable, nonatomic, copy) NSNumber *weight;

@end

NS_ASSUME_NONNULL_END
