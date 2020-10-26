//
//  AlarmData+CoreDataProperties.h
//  LSWearable
//
//  Created by hanfeng.li on 2017/3/29.
//  Copyright © 2017年 lifesense. All rights reserved.
//

#import "AlarmData+CoreDataClass.h"


NS_ASSUME_NONNULL_BEGIN

@interface AlarmData (CoreDataProperties)

+ (NSFetchRequest<AlarmData *> *)fetchRequest;

@property (nullable, nonatomic, copy) NSString *errorCause;
@property (nullable, nonatomic, copy) NSString *errorCount;
@property (nullable, nonatomic, copy) NSNumber *errorSources;
@property (nullable, nonatomic, copy) NSString *errorType;
@property (nullable, nonatomic, copy) NSString *id;
@property (nullable, nonatomic, copy) NSString *remark;
@property (nullable, nonatomic, copy) NSNumber *startTime;
@property (nullable, nonatomic, copy) NSNumber *userId;

@end

NS_ASSUME_NONNULL_END
