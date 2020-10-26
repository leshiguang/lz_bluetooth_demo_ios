//
//  LSLocalDataHelper+AlarmData.h
//  LSWearable
//
//  Created by Dylan on 16/3/28.
//  Copyright © 2016年 lifesense. All rights reserved.
//

#import "LSLocalDataHelper.h"

@class AlarmData;
@interface LSLocalDataHelper (AlarmData)
/**
 *  保存告警数据
 */
- (AlarmData *)dl_saveAlarmDataToDic:(NSDictionary *)dic;
/**
 *  根据id查询告警数据
 */
- (AlarmData *)dl_getAlarmDataWithId:(NSString *)_id;
/**
 *  获取全部告警数据
 */
- (NSArray<AlarmData *> *)dl_getAllAlarmData;
/**
 *  根据userId获取告警数据
 */
- (NSArray<AlarmData *> *)dl_getAlarmDataWithUserId:(NSNumber *)userId;

/**
 *  根据id删除告警数据
 */
-(BOOL)dl_deleteAlarmDataWithId:(NSString *)_id;
/**
 *  删除所有的告警数据
 */
-(BOOL)dl_deleteAllAlarmData;
/**
 *  modle转dic
 */
-(NSDictionary *)dl_dictionaryByAlarmData:(AlarmData *)alarmData;
@end
