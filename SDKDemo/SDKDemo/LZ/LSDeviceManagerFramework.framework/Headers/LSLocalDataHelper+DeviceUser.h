//
//  LSLocalDataHelper+DeviceUser.h
//  设备
//
//  Created by Dylan on 16/1/26.
//  Copyright © 2016年 Lifesense. All rights reserved.
//

#import "LSLocalDataHelper.h"
@interface LSLocalDataHelper (DeviceUser)
-(NSArray <DeviceUser*>*)allDeviceUsersWithUserIds:(NSArray *)userIds;

-(DeviceUser*)deviceUserWithId:(NSString*)_id;
//
-(DeviceUser*)deviceUserWithUserId:(NSNumber*)userId;

-(NSArray*)deviceUserWithDeviceId:(NSString*)deviceId;

-(void)deleteDeviceUserWithUserId:(NSNumber *)userId;
//获取已设备绑定状态列表
-(NSArray <DeviceUser*>*)getDeviceUserListWithUserId:(NSNumber *)userId;
//获取设备历史绑定状态列表
-(NSArray <DeviceUser*>*)getHistoryDeviceUserListWithUserId:(NSString *)userId;

-(DeviceUser*)deviceUserWithDictionary:(NSDictionary*)dic;
//获取未同步的设备状态
-(NSArray *)getNosyncDeviceUser;

-(NSMutableDictionary*)dictionaryByDeviceUser:(DeviceUser*)deviceUser;
- (BOOL)deleteDeviceUserWithDeviceId:(NSString *)deviceId;
@end
