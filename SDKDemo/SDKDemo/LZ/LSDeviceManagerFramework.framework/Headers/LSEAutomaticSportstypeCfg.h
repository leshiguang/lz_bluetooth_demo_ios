//
//  LSEAutomaticSportstypeCfg.h
//  LSWearable
//
//  Created by 郭景煊 on 17/1/12.
//  Copyright © 2017年 lifesense. All rights reserved.
//

#import <Foundation/Foundation.h>

//Push自动识别多运类型
typedef NS_ENUM(NSUInteger,LSEAutomaticSportstype)
{
    /**
     * 跑步
     */
    LSEAutomaticSportstypeRunning = 1,
    
    /**
     * 健走
     */
    LSEAutomaticSportstypeWalking,
    
    /**
     * 游泳
     */
    LSEAutomaticSportstypeSwimming = 4,
};

@interface LSEAutomaticSportstypeCfg : NSObject

/// 运动类型
@property (nonatomic, assign) LSEAutomaticSportstype automaticSportstype;
/// 自动识别开关
@property (nonatomic, assign) BOOL isOpen;

@end

