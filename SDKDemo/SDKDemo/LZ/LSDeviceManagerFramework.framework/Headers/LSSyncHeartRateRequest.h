//
//  LSSyncHeartRateRequest.h
//  LSDeviceManagerFrameworkTests
//
//  Created by wm on 2020/9/17.
//  Copyright © 2020 Wenzheng Zhang. All rights reserved.
//

#import <LSNetwork_iOS/LSNetworkingModule.h>
#import "HeartRateData.h"

NS_ASSUME_NONNULL_BEGIN

@interface LSSyncHeartRateRequest : LSBaseRequest

- (void)setRequestParameters:(NSArray<HeartRateData *> *)heartRateDataAry;

@end

NS_ASSUME_NONNULL_END
