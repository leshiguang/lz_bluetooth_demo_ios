//
//  LSDInfomationClear.h
//  LSBluetooth-Library
//
//  Created by lshenrong on 17/3/1.
//  Copyright © 2017年 Lifesense. All rights reserved.
//

#import "LSDBaseModel.h"
#import "LSConst.h"

@interface LSDInfomationClear : LSDBaseModel
/** 用户号*/
@property (nonatomic ,assign) int userNumber;
/** 选择删除的类型*/
@property (nonatomic ,assign) LSClearType clearType;



@end
