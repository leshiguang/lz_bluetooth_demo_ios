//
//  LSSportFreqInfo.h
//  LSBluetooth-Library
//
//  Created by lifesense on 2017/11/2.
//  Copyright © 2017年 Lifesense. All rights reserved.
//

#import "LSConst.h"

@interface LSSportFreqInfo : NSObject

/**
 * 开始和停止状态对应的时间
 */
@property(nonatomic, assign)long long utc;
/**
 * 状态
 */
@property(nonatomic, assign)LSSportFreq status;

@end
