//
//  UWalkingData.h
//  LSWearable
//
//  Created by 郭景煊 on 17/1/10.
//  Copyright © 2017年 lifesense. All rights reserved.
//

#import "LSBaseSportData.h"
#import "LSDMConstants.h"

@interface LSDMWalkingFreqInfo : NSObject
/// 健走状态对应时间UTC
@property (nonatomic, assign) long long utc;
/// 健走状态
@property (nonatomic, assign) LSDMWalkFreq status;
/// 数据Id
@property (nonatomic, strong) NSString *dataId;
@end

@interface UWalkingData : LSBaseSportData
/// 健走总步数
@property (nonatomic, assign)  int step;
/// 获取健走频率信息(只读)
@property (nonatomic, strong)  NSArray<LSDMWalkingFreqInfo *> *walkFreqList;
@end
