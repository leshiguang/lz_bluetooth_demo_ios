//
//  LSDInitRespModel.h
//  LSBluetooth-Library
//
//  Created by lifesense－mac on 17/3/2.
//  Copyright © 2017年 Lifesense. All rights reserved.
//

#import "LSDBaseModel.h"
#import "LSConst.h"

@interface LSDInitRespModel : LSDBaseModel

// 请求类型
@property (nonatomic, assign) LSInitReqType type;

// MTU
@property (nonatomic, assign) NSUInteger mtuValue;

// Slave Latency
@property (nonatomic, assign) NSUInteger slValue;

// Supervisory Time out
@property (nonatomic, assign) NSUInteger stoValue;

// UTC
@property (nonatomic, assign) NSUInteger utc;

// Timezone
@property (nonatomic, assign) NSInteger timeZone;

// Date
@property (nonatomic, strong) NSDate *date;

@end
