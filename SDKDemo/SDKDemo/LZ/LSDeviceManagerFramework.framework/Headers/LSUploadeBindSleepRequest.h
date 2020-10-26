//
//  LSUploadeBindSleepRequest.h
//  LSDeviceManagerFrameworkTests
//
//  Created by wm on 2020/9/17.
//  Copyright © 2020 Wenzheng Zhang. All rights reserved.
//

#import <LSNetwork_iOS/LSNetworkingModule.h>
#import "SleepingData.h"

NS_ASSUME_NONNULL_BEGIN

@interface LSUploadeBindSleepRequest : LSBaseRequest

- (void)setRequestParameters:(NSArray<SleepingData *> *)sleepingDataAry;

@end

NS_ASSUME_NONNULL_END
