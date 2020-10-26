//
//  LSUploadAerobicsRequest.h
//  LSDeviceManagerFrameworkTests
//
//  Created by wm on 2020/9/18.
//  Copyright © 2020 Wenzheng Zhang. All rights reserved.
//

#import <LSNetwork_iOS/LSNetworkingModule.h>
#import "LSBaseSportData.h"

NS_ASSUME_NONNULL_BEGIN

@interface LSUploadAerobicsRequest : LSBaseRequest

- (void)setRequestParameters:(NSArray<LSBaseSportData *> *)OxSportDataAry;

@end

NS_ASSUME_NONNULL_END
