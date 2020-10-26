//
//  LSDeviceManager+Sport.h
//  LSDeviceManagerFrameworkTests
//
//  Created by alex.wu on 2019/9/9.
//  Copyright © 2019 Wenzheng Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSDeviceManager.h"
NS_ASSUME_NONNULL_BEGIN

@interface LSDeviceManager(Sport)<LSBleDataReceiveDelegate>


//APP push 申请发起/结束运动
- (void)launchOrCloseSport:(NSString *)deviceId isLaunch:(BOOL)isLaunch modelType:(LSESportModeType)modelType completion:(Completion)completion;

@end

NS_ASSUME_NONNULL_END
