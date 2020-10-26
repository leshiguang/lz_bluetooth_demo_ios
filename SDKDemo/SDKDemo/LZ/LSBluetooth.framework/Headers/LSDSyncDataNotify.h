//
//  LSDSyncDataNotify.h
//  LSBluetooth-Library
//
//  Created by lshenrong on 17/3/3.
//  Copyright © 2017年 Lifesense. All rights reserved.
//

#import "LSDBaseModel.h"
#import "LSConst.h"

@interface LSDSyncDataNotify : LSDBaseModel
/** 用户号*/
@property (nonatomic ,assign) int userNumber;
/** 是否允许上传数据*/
@property (nonatomic ,assign) BOOL isSyncData;


@end
