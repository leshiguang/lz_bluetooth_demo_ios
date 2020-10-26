//
//  LSDEventInfo.h
//  LSBluetooth-Library
//
//  Created by lifesense on 17/1/7.
//  Copyright © 2017年 Lifesense. All rights reserved.
//

#import "LSDBaseModel.h"
#import "LSConst.h"
@interface LSEventRemind : NSObject

/**
 *  事件提醒序号(必须在1~5)
 */
@property (nonatomic, assign) int index;

/**
 *  事件描述内容
 */
@property (nonatomic, strong) NSString *eventcontent;

/**
 *  事件提醒开关
 */
@property (nonatomic, assign) BOOL eventSwitch;

/**
 *  事件提醒时间(小时)
 */
@property (nonatomic, assign) int hour;

/**
 *  事件提醒时间(分钟)
 */
@property (nonatomic, assign) int minute;

/**
 *  事件提醒重复时间(重复提醒的日期)
 */
@property (nonatomic, readonly) NSArray *weeks;

/**
 *  事件提醒震动方式
 */
@property (nonatomic, assign) LSShockType shockType;

/**
 *  事件提醒震动持续时长
 */
@property (nonatomic, assign) int shockTime;

/**
 *  事件提醒震动强度1
 */
@property (nonatomic, assign) int shockLevel1;

/**
 *  事件提醒震动强度2
 */
@property (nonatomic, assign) int shockLevel2;

/**
 *  添加提醒的日期,如果没有设置，将会提醒一次，最后一个一定得是LSWeekNone
 *
 *  @param week1 LSWeek 星期几
 */
- (void)addWeek:(LSWeek)week1,...;

/**
 *  删除提醒日期，最后一个一定得是LSWeekNone
 *
 *  @param week1 LSWeek 星期几
 */
- (void)removeWeek:(LSWeek)week1,...;
@end
@interface LSDEventInfo : LSDBaseModel
@property (nonatomic, readonly) NSArray<LSEventRemind*> *events;

/**
 *  添加事件提醒对象
 *
 *  @param event LSEventRemind 事件提醒对象
 */

- (void)addEvent:(LSEventRemind *)event;
@end
