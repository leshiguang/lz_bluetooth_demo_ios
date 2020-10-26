//
//  HeartRateCfg.h
//  LSBluetooth-Library
//
//  Created by Dylan on 16/1/16.
//  Copyright © 2016年 Lifesense. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface HeartRateCfg : NSObject
/** 检测结束时间（时） */
@property(nonatomic,assign)int endHour;
/** 检测结束时间（分） */
@property(nonatomic,assign)int endMin;
/** 检测开始时间（时） */
@property(nonatomic,assign)int startHour;
/** 检测开始时间（分） */
@property(nonatomic,assign)int startMin;
/** 是否打开 */
@property(nonatomic,assign)BOOL enable;




@end
