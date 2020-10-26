//
//  LSLocalDataHelper+DeviceStatus.h
//  设备
//
//  Created by Dylan on 16/1/26.
//  Copyright © 2016年 Lifesense. All rights reserved.
//

#import "LSLocalDataHelper.h"

@interface LSLocalDataHelper (DeviceStatus)
-(DeviceStatus*)deviceStatusWithId:(NSString*)_id;

-(DeviceStatus*)deviceStatusWithDeviceId:(NSString*)deviceId;

-(DeviceStatus*)DeviceStatusWithDictionary:(NSDictionary*)dic;

//获取未同步设备状态
-(NSArray *)getNosyncDeviceStatus;

-(NSMutableDictionary*)dictionaryByDeviceStatus:(DeviceStatus*)deviceStatus;

- (DeviceStatus *)createDeviceStatus;
- (DeviceStatus *)createDeviceStatusWithId:(NSString *)_id;
- (BOOL)deleteDeviceStatusWithDeviceId:(NSString *)deviceId;

@end
