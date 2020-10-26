//
//  LSDeviceManager+Settings.h
//  LSDeviceManagerFrameworkTests
//
//  Created by alex.wu on 2019/9/6.
//  Copyright © 2019 Wenzheng Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSDeviceManager.h"

NS_ASSUME_NONNULL_BEGIN


@interface LSDeviceManager (Settings)

- (void)saveSettting:(NSString *)deviceId clsName:(NSString *)clsName settingObj:(id)settingObj;

- (id)getSetting:(NSString *)deviceId clsName:(NSString *)clsName;


@end

NS_ASSUME_NONNULL_END
