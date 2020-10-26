//
//  SwimmingData.h
//  LSBluetooth-Library
//
//  Created by Dylan on 16/1/16.
//  Copyright © 2016年 Lifesense. All rights reserved.
//

#import "LSBaseSportData.h"
#import "LSDMConstants.h"

@interface SwimmingData : LSBaseSportData

/// 游泳圈数
@property (nonatomic, assign) NSUInteger laps;

@end
