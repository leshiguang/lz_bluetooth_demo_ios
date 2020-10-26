//
//  ScreenDirectionCfg.h
//  LSWearable
//
//  Created by lifesense－mac on 16/8/12.
//  Copyright © 2016年 lifesense. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 手环显示方向
 */
typedef enum : NSUInteger {
    ScreenDirectionTypeHorizontal, ///< 水平显示
    ScreenDirectionTypeVertical,   ///<///< 垂直显示
} ScreenDirectionType;


/// 手环显示方向设置类
@interface ScreenDirectionCfg : NSObject
/// 显示方向
@property (nonatomic, assign) ScreenDirectionType type;

@end
