//
//  LSDeviceManager+Weight.h
//  LSDeviceManagerFrameworkTests
//
//  Created by alex.wu on 2019/9/9.
//  Copyright © 2019 Wenzheng Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSDeviceManager.h"
NS_ASSUME_NONNULL_BEGIN

@interface LSDeviceManager(Weight)

//接收体重测量数据 A6
- (void)bleManagerDidReceiveWeightScaleMeasureData:(LSUSyncMeasureData *)info srcData:(NSData *)srcData device:(LSDeviceInfo *)device;

//接收体重测量数据
-(void)bleManagerDidReceiveWeightMeasuredData:(LSWeightData *)data device:(LSDeviceInfo *)device;

// 更新用户体重最新一笔到绑定用户表
- (void)updateWeightByChangeFromWeightManager:(NSNumber *)userId weight:(NSNumber *)weight;

/**
 * 设置A6体重秤时间,也可能没用
 */
- (void)setScaleTime:(NSString *)deviceId utc:(NSUInteger)utc completion:(Completion)completion;

//同步体重秤测量数据
- (void)syncScaleMeasureData:(NSString *)deviceId completion:(Completion)completion;
@end
NS_ASSUME_NONNULL_END
