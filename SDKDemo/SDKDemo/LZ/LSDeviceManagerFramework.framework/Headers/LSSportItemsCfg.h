//
//  LSSportItemsCfg.h
//  LSDeviceManagerFramework
//
//  Created by Xwei on 2017/11/10.
//  Copyright © 2017年 Wenzheng Zhang. All rights reserved.
//  运动项设置

#import <Foundation/Foundation.h>

// 定义运动项内容
typedef NS_ENUM(NSUInteger, LSSportItemType){
    LSSportItemTypeRunning, // 跑步0
    LSSportItemTypeWalking, // 健走1
    LSSportItemTypeCycling, // 骑行2
    LSSportItemTypeSwiming, // 游泳3
    LSSportItemTypeFitness, // 健身4
    LSSportItemTypeYoga, // 瑜伽5
    LSSportItemTypeBasketball, // 篮球6
    LSSportItemTypeFootball, // 足球7
    LSSportItemTypeBadminton, // 羽毛球8
    LSSportItemTypeVolleyball, // 排球9
    LSSportItemTypeTableTennis, // 乒乓球a
    LSSportItemTypeESport,  // 电竞b
    LSSportItemType12MinutesRunMode,  // 12分钟跑c
    LSSportItemType6MinutesRunMode,  // 6分钟跑d
    LSSportItemTypeAliPayMode,  // 支付宝e
    LSSportItemTypeGymDance,//f
    LSSportItemTypeTaiji,//16
    LSSportItemTypeIndoorRun,//17
    LSSportItemTypeCycleMaction,//18
    LSSportItemTypeOxSport,//19
    LSSportItemTypeUnknowUsed = 0xffff
};

@interface LSSportItemSwitch : NSObject

/// 类型
@property (nonatomic, assign) LSSportItemType type;
/// 开/关
@property (nonatomic, assign) BOOL state;

@end

/// 运动项设置Model
@interface LSSportItemsCfg : NSObject

/// 设置的运动项
@property(nonatomic, strong) NSArray<NSNumber *> *items;

@end
