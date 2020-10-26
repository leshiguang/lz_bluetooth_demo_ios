//
//  NightModeCfg.h
//  LSWearable
//
//  Created by lifesense－mac on 16/8/12.
//  Copyright © 2016年 lifesense. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  夜间模式设置类
 */
@interface NightModeCfg : NSObject
/// 是否打开夜间模式
@property (nonatomic, assign) BOOL isOpen;
/// 与isOpen一样，不用设置该值，这里只是为了兼容android的json序列化与UI不需要更改而加的值
@property (nonatomic, assign) BOOL open;
/// 开始时间（时）
@property (nonatomic, assign) NSUInteger startHour;
/// 开始时间（分）
@property (nonatomic, assign) NSUInteger startMinute;
/// 结束时间（时）
@property (nonatomic, assign) NSUInteger endHour;
/// 结束时间（分）
@property (nonatomic, assign) NSUInteger endMinute;

@end
