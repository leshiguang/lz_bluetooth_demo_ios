//
//  LSScalesSyncDataManager.h
//  LSDeviceManagerFrameworkTests
//
//  Created by wm on 2020/9/18.
//  Copyright © 2020 Wenzheng Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WeightData.h"

NS_ASSUME_NONNULL_BEGIN

@interface LSScalesSyncDataManager : NSObject

+ (instancetype)shareInstance;

- (void)syncWeightData:(NSArray <WeightData *> *)weightDatas;

@end

NS_ASSUME_NONNULL_END
