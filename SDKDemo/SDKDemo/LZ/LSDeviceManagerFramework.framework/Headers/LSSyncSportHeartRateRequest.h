//
//  LSSyncSportHeartRate.h
//  LSDeviceManagerFrameworkTests
//
//  Created by wm on 2020/9/17.
//  Copyright © 2020 Wenzheng Zhang. All rights reserved.
//

#import <LSNetwork_iOS/LSNetworkingModule.h>
#import "SportHeartRateData.h"

NS_ASSUME_NONNULL_BEGIN

@interface LSSyncSportHeartRateRequest : LSBaseRequest

- (void)setRequestParameters:(NSArray<SportHeartRateData *> *)SportHeartRateDataAry;

@end

NS_ASSUME_NONNULL_END
