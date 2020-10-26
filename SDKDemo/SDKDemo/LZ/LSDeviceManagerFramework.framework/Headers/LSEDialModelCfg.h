//
//  LSEDialModelCfg.h
//  LSWearable
//
//  Created by hanfeng.li on 2017/2/22.
//  Copyright © 2017年 lifesense. All rights reserved.
//

#import <Foundation/Foundation.h>


//Push表盘设置类型
typedef NS_ENUM(NSUInteger, LSEDialModelType) {
    /**
     * 表盘1
     */
    LSEDialModeTypeOne = 1,
    /**
     * 表盘2
     */
    LSEDialModeTypeTwo,
    /**
     * 表盘3
     */
    LSEDialModeTypeThree,
    /**
     * 表盘4
     */
    LSEDialModeTypeFour,
    /**
     * 表盘5
     */
    LSEDialModeTypeFive,
    /**
     * 表盘6
     */
    LSEDialModeTypeSix,
};


@interface LSEDialModelCfg : NSObject

/// 表盘模式
@property (nonatomic, assign) LSEDialModelType type;

@end




