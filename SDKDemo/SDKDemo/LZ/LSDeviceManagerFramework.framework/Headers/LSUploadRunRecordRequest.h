//
//  LSUploadRunRecordRequest.h
//  LSDeviceManagerFrameworkTests
//
//  Created by wm on 2020/9/18.
//  Copyright © 2020 Wenzheng Zhang. All rights reserved.
//  上传运动数据

#import <LSNetwork_iOS/LSNetworkingModule.h>
#import "LSBaseSportData.h"

NS_ASSUME_NONNULL_BEGIN

@interface LSUploadRunRecordRequest : LSBaseRequest

- (void)setRequestParameters:(NSArray<LSBaseSportData *> *)SportDataAry;

@end

NS_ASSUME_NONNULL_END
