//
//  LSEManufacturerInfo.h
//  LSWearable
//
//  Created by lshenrong on 17/3/13.
//  Copyright © 2017年 lifesense. All rights reserved.
//  心率预警设置

#import <Foundation/Foundation.h>

@interface LSEManufacturerInfo : NSObject
/** 厂商id*/
@property (nonatomic ,strong) NSString *manufacturerId;
/** 厂商名称*/
@property (nonatomic ,strong) NSString *manufacturerName;
/** 厂商电话*/
@property (nonatomic ,strong) NSString *manufacturerPhone;
/** 厂商地址*/
@property (nonatomic ,strong) NSString *manufacturerAdress;
/** 备注*/
@property (nonatomic ,strong) NSString *manufacturerMemo;
/** 创建时间*/
@property (nonatomic ,strong) NSDate *created;
/** 修改时间*/
@property (nonatomic ,strong) NSDate *updated;






@end
