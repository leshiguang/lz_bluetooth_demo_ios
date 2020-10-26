//
//  LSUploadBindStepRequest.h
//  LSDeviceManagerFrameworkTests
//
//  Created by wm on 2020/9/17.
//  Copyright © 2020 Wenzheng Zhang. All rights reserved.
//

#import <LSNetwork_iOS/LSNetworkingModule.h>
#import "WalkingData.h"

NS_ASSUME_NONNULL_BEGIN

@interface LSUploadBindStepRequest : LSBaseRequest

- (void)setRequestParameters:(NSArray <WalkingData *> *)walkingDataAry;

@end

NS_ASSUME_NONNULL_END
