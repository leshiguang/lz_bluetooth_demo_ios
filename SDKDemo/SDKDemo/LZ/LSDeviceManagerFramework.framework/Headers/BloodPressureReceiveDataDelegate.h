//
//  BloodRreasureReceiveDataDelegate.h
//  LSDeviceManagerFrameworkTests
//
//  Created by wm on 2020/9/17.
//  Copyright © 2020 Wenzheng Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol BloodPressureReceiveDataDelegate <NSObject>
- (void)onReceiveBloodPressureMeasureData:(LSSphygmometerData *)bloodPressureData;
@end

NS_ASSUME_NONNULL_END
