//
//  LSLocalDataHelper+DeviceSetting.h
//  设备
//
//  Created by Dylan on 16/1/26.
//  Copyright © 2016年 Lifesense. All rights reserved.
//

#import "LSLocalDataHelper.h"
@class AlarmClockCfg;
@interface LSLocalDataHelper (DeviceSetting)
-(DeviceSetting*)deviceSettingWithId:(NSString*)_id;
-(DeviceSetting*)DeviceSettingWithDictionary:(NSDictionary*)dic;
-(NSMutableDictionary*)dictionaryByDeviceSetting:(DeviceSetting*)deviceSetting;
//更加设备id查询设备设置
-(NSArray *)deviceSettingWithDeviceId:(NSString *)deviceId settingClass:(NSString *)settingClass;
//获取未同步设备设置
-(NSArray *)getNosyncDeviceSetting;
//删除全部闹钟设置
-(void)deleteAllAlarmClockWithDeviceId:(NSString *)deviceId;
/**
 *  根据device id获取全部设置
 *
 *  @param deviceId 设备Id
 *
 *  @return 设置列表
 */
-(NSArray *)getAllDeviceSettingWithDeviceId:(NSString *)deviceId;
- (BOOL)deleteDeviceSettingWithDeviceId:(NSString *)deviceId;
@end
