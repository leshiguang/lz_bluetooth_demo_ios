//
//  LSUInitReqModel.h
//  LSBluetooth-Library
//
//  Created by lifesense－mac on 17/3/2.
//  Copyright © 2017年 Lifesense. All rights reserved.
//

#import "LSUBaseModel.h"
#import "LSConst.h"

@interface LSUInitReqModel : LSUBaseModel

// 请求类型
@property (nonatomic, assign) LSInitReqType type;

// MTU
@property (nonatomic, assign) NSUInteger mtuValue;

// Slave Latency
@property (nonatomic, assign) NSUInteger slValue;

// Supervisory Time out
@property (nonatomic, assign) NSUInteger stoValue;

@end
