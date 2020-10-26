//
//  LSDSettingRespModel.h
//  LSBluetooth-Library
//
//  Created by lifesense－mac on 17/3/2.
//  Copyright © 2017年 Lifesense. All rights reserved.
//

#import "LSDBaseModel.h"
#import "LSConst.h"

@interface LSDSettingRespModel : LSDBaseModel
// 设置命令
@property (nonatomic, assign) NSUInteger settingCommand;

// 错误代码
@property (nonatomic, assign) LSSettingRespCode code;

@end
