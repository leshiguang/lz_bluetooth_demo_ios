//
//  EncourageCfg.h
//  LSBluetooth-Library
//
//  Created by Dylan on 16/1/16.
//  Copyright © 2016年 Lifesense. All rights reserved.
//  步数、卡路里、距离目标设置

#import <Foundation/Foundation.h>

//Push鼓励目标类型提醒设置
typedef NS_ENUM(NSUInteger, LSEEncourageTargetType) {
    /**
     * 未知
     */
    LSEEncourageTargetTypeUnknown,
    /**
     * 步数
     */
    LSEEncourageTargetTypeStepNum = 1,
    
    /**
     * 卡路里
     */
    LSEEncourageTargetTypeCalories,
    
    /**
     * 距离
     */
    LSEEncourageTargetTypeDistance,
};

@interface EncourageCfg : NSObject

/// 目标值,已抛弃,切勿使用
@property(nonatomic,assign) int steps;
/// 鼓励类型
@property(nonatomic,assign) LSEEncourageTargetType type;
/// 是否开启
@property(nonatomic,assign) BOOL isOpen;
/// 目标值
@property(nonatomic,assign) float value;
/// 步数 （A6 H1_watch）
@property(nonatomic,assign) int stepNum;
/// 卡路里 （A6 H1_watch）
@property(nonatomic,assign) float caloriesNum;
/// 距离 （A6 H1_watch）
@property(nonatomic,assign) float distanceNum;

@end
