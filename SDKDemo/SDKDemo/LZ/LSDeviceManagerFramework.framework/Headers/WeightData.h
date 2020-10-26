//
//  WeightData.h
//  LSBluetooth-Library
//
//  Created by Dylan on 16/1/16.
//  Copyright © 2016年 Lifesense. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WeightData : NSObject

/// 用户id
@property (nonatomic, strong) NSString *userId;
/// 体重id
@property (nonatomic,strong) NSString *id;
/// 体重数据
@property(nonatomic,assign) double weight;
/// 测量时间
@property(nonatomic,copy) NSNumber *measurementDate;
/// 设备id
@property (nonatomic, strong) NSString *deviceId;
/// 设备按钮号
@property (nonatomic, assign) NSInteger deviceUserNo;
/// 5K电阻值
@property(nonatomic,assign)double resistance5K;
/// 50K电阻值
@property(nonatomic,assign)double resistance50K;


///** 体质数据 */
//@property(nonatomic,assign)double bmi;
///** 脂肪率 */
//@property(nonatomic,assign)double pbf;
///** 骨骼量 */
//@property(nonatomic,assign)double bone;
///** 水分率 */
//@property(nonatomic,assign)double water;
///** 肌肉量 */
//@property(nonatomic,assign)double muscle;
///** 体重水平 */
//@property(nonatomic,assign)int weightLevel;
///** 电量（1-10）*/
//@property(nonatomic,assign)int battery;


@end
