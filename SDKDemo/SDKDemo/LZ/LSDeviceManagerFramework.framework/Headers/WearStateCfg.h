//
//  WearStateCfg.h
//  LSWearable
//
//  Created by lifesense－mac on 16/8/12.
//  Copyright © 2016年 lifesense. All rights reserved.
//  佩戴习惯

#import <Foundation/Foundation.h>

/**
 穿戴类型
 */
typedef enum : NSUInteger {
    WearStateTypeLeft,  ///< 左手佩戴
    WearStateTypeRight,  ///< 右手佩戴
} WearStateType;

/// 穿戴习惯设置类
@interface WearStateCfg : NSObject
/// 穿戴类型
@property (nonatomic, assign) WearStateType type;

@end
