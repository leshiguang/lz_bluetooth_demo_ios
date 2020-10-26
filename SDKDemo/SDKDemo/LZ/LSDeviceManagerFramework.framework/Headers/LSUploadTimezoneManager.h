//
//  LSUploadTimezoneManager.h
//  LSDeviceManagerFramework
//
//  Created by wm on 2020/9/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LSUploadTimezoneManager : NSObject
+ (instancetype)shareInstance;

/// 时区上报
/// @param model 设备model信息
/// @param mac 设备mac地址
- (void)RequestSyncTimezoneWithModel:(NSString *)model mac:(NSString *)mac;
@end

NS_ASSUME_NONNULL_END
