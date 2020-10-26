//
//  LSUSettingResult.h
//  LSBluetooth-Library
//
//  Created by lshenrong on 17/3/2.
//  Copyright © 2017年 Lifesense. All rights reserved.
//

#import "LSUBaseModel.h"
#import "LSConst.h"

@interface LSUSettingResult : LSUBaseModel

/** 设置的CMD */
@property (nonatomic ,assign) int settingCmd;

/** 错误代码 */
@property (nonatomic ,assign) LSSettingRespCode code;


@end
