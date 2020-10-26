//
//  LSDDisplayPage.h
//  LSBluetooth-Library
//
//  Created by lifesense on 16/8/1.
//  Copyright © 2016年 Lifesense. All rights reserved.
//

#import "LSDBaseModel.h"
#import "LSConst.h"
@interface LSDDisplayPage : LSDBaseModel

@property (nonatomic, assign, readonly) NSUInteger pageNum;

- (void)addPage:(DisplayPageType)page;

- (void)removePage:(DisplayPageType)page;

@end
