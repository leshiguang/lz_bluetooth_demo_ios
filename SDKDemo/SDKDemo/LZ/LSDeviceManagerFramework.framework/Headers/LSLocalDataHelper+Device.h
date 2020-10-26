//
//  LSLocalDataHelper+Device.h
//  设备
//
//  Created by Dylan on 16/1/26.
//  Copyright © 2016年 Lifesense. All rights reserved.
//

#import "LSLocalDataHelper.h"
@interface LSLocalDataHelper (Device)
-(Device*)DeviceWithDictionary:(NSDictionary*)dic;
-(Device*)deviceWithId:(NSString*)_id;
//获取设备列表
-(Device*)getDeviceListWithDeviceId:(NSString *)deveiceId type:(NSString *)productTypeCode;
//
-(NSArray *)getAllDeviceListWithDeviceId:(NSString *)deviceId;
//
-(Device *)getAllDeviceWithDeviceId:(NSString *)deviceId;

- (BOOL)deleteDeviceWithId:(NSString *)deviceId;

//获取历史设备列表
-(Device*)getHistoryDeviceListWithDeviceId:(NSString *)deveiceId;

//获取所有未同步的数据
-(NSArray *)getNosyncDevice;

-(NSMutableDictionary*)dictionaryByDevice:(Device*)device;
@end
