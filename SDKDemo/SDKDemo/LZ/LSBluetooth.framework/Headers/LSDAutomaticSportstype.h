//
//  LSDAutomaticSportstype.h
//  LSBluetooth-Library
//
//  Created by lifesense on 17/1/4.
//  Copyright © 2017年 Lifesense. All rights reserved.
//

#import "LSDBaseModel.h"
#import "LSConst.h"
@interface LSAutomaticSportstypeModel : NSObject
/**
 * 运动类型
 */
@property (nonatomic, assign) LSAutomaticSportstype automaticSportstype;

/**
 * 自动识别开关
 */
@property (nonatomic, assign) BOOL isOpen;

@end
@interface LSDAutomaticSportstype : LSDBaseModel
@property (nonatomic, assign, readonly) NSUInteger automaticNum;

@property (nonatomic, readonly) NSArray<LSAutomaticSportstypeModel*> *automatics;

/**
 *  添加自动识别多运动
 *
 *  @param model LSAutomaticSportstypeModel 自动识别多运动对象
 */
- (void)addAutomatic:(LSAutomaticSportstypeModel *)model;

@end
