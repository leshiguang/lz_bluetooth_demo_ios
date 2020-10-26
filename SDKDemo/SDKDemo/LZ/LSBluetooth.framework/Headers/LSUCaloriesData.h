//
//  LSUCaloriesData.h
//  LSBluetooth-Library
//
//  Created by lifesense on 16/8/3.
//  Copyright © 2016年 Lifesense. All rights reserved.
//

#import "LSUBaseModel.h"
#import "LSConst.h"

@interface LSUCaloriesData : LSUBaseModel

@property (nonatomic, assign) LSSportCaloriesDataType type;
@property (nonatomic, assign) LSSportModeType sportMode;
@property (nonatomic, assign) LSSubModeType subMode;
@property (nonatomic, assign) long long utc;
@property (nonatomic, assign) int restCount;
@property (nonatomic, assign) int collectTime;
@property (nonatomic, readonly) NSArray<NSNumber *> *calorieList;
@property (nonatomic, readonly) NSData *srcData;

@end
