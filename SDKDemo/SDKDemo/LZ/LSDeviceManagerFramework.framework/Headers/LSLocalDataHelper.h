//
//  LSLocalDataHelper.h
//  设备
//
//  Created by Dylan on 16/1/26.
//  Copyright © 2016年 Lifesense. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CoreDataManager.h"
#import "Device+CoreDataProperties.h"
#import "DeviceUser+CoreDataProperties.h"
#import "DeviceStatus+CoreDataProperties.h"
#import "DeviceSetting+CoreDataProperties.h"
#import "AlarmData+CoreDataProperties.h"

@interface LSLocalDataHelper : NSObject

@property(nonatomic,strong)CoreDataManager *dataManager;

+(instancetype)shareInstance;

@end
