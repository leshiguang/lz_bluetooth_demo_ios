//
//  DeviceSetting+CoreDataProperties.h
//  LSWearable
//
//  Created by hanfeng.li on 2017/3/29.
//  Copyright © 2017年 lifesense. All rights reserved.
//

#import "DeviceSetting+CoreDataClass.h"


NS_ASSUME_NONNULL_BEGIN

@interface DeviceSetting (CoreDataProperties)

+ (NSFetchRequest<DeviceSetting *> *)fetchRequest;

@property (nullable, nonatomic, copy) NSString *content;
@property (nullable, nonatomic, copy) NSNumber *created;
@property (nullable, nonatomic, copy) NSString *deviceId;
@property (nullable, nonatomic, copy) NSString *id;
@property (nullable, nonatomic, copy) NSNumber *isDelete;
@property (nullable, nonatomic, copy) NSString *settingClass;
@property (nullable, nonatomic, copy) NSNumber *settingTime;
@property (nullable, nonatomic, copy) NSNumber *syncFlag;
@property (nullable, nonatomic, copy) NSNumber *updated;

@end

NS_ASSUME_NONNULL_END
