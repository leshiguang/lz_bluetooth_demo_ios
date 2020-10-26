//
//  LSSyncRunCaloriesRequest.h
//  LSDeviceManagerFrameworkTests
//
//  Created by wm on 2020/9/18.
//  Copyright © 2020 Wenzheng Zhang. All rights reserved.
//

#import <LSNetwork_iOS/LSNetworkingModule.h>
#import "RunningCaloriesData.h"

NS_ASSUME_NONNULL_BEGIN

@interface LSSyncRunCaloriesRequest : LSBaseRequest

- (void)setRequestParameters:(NSArray<RunningCaloriesData *> *)runningCaloriesDatas;

@end

NS_ASSUME_NONNULL_END
