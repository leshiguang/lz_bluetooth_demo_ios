//
//  LSUConfigurationSpeed.h
//  LSBluetooth-Library
//
//  Created by hanfeng.li on 2017/1/16.
//  Copyright © 2017年 Lifesense. All rights reserved.
//

#import "LSUBaseModel.h"
#import "Constants.h"

@interface LSUConfigurationSpeed : LSUBaseModel

@property (nonatomic, assign) LSSportModeType sportMode;
@property (nonatomic, assign) LSSubModeType subMode;
@property (nonatomic, assign) long long utc;
@property (nonatomic, assign) int restCount;
@property (nonatomic, assign) int collectTime;
@property (nonatomic, readonly) NSArray<NSNumber *> *configuraionSpeedList;
@property (nonatomic, readonly) NSData *srcData;

@end
