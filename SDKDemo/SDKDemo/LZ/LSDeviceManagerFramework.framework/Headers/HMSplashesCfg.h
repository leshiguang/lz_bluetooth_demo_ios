//
//  HMSplashesCfg.h
//  LSDeviceManagerFrameworkTests
//
//  Created by pengpeng on 2019/8/9.
//  Copyright © 2019 Wenzheng Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HMSplashesCfg : NSObject

/** 是否开启散点图心率监测 */
@property(nonatomic,assign)BOOL enable;
/** 开始时间（时） */
@property(nonatomic,assign)int startHour;
/** 开始时间（分） */
@property(nonatomic,assign)int startMin;
/** 结束时间（时） */
@property(nonatomic,assign)int endHour;
/** 结束时间（分） */
@property(nonatomic,assign)int endMin;

@end

NS_ASSUME_NONNULL_END
