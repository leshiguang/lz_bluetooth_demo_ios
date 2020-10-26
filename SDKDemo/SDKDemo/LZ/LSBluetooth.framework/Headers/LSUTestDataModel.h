//
//  LSUTestDataModel.h
//  LSBluetooth-Library
//
//  Created by lifesense－mac on 16/12/5.
//  Copyright © 2016年 Lifesense. All rights reserved.
//

#import "LSUBaseModel.h"


/**
 用于调试设备采集数据，无太多作用
 */
@interface LSUTestDataModel : LSUBaseModel

@property(nonatomic, strong) NSData* uploadData;

@end
