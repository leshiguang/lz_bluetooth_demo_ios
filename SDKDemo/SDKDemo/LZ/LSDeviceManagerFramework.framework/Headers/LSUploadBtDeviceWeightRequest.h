//
//  LSUploadBtDeviceWeightRequest.h
//  LSDeviceManagerFrameworkTests
//
//  Created by wm on 2020/9/18.
//  Copyright © 2020 Wenzheng Zhang. All rights reserved.
//

#import <LSNetwork_iOS/LSNetworkingModule.h>
#import "WeightData.h"

NS_ASSUME_NONNULL_BEGIN

@interface LSUploadBtDeviceWeightRequest : LSBaseRequest

- (void)setRequestParameters:(NSArray<WeightData *> *)weightDataAry;

@end

NS_ASSUME_NONNULL_END
