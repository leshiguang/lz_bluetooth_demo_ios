//
//  LSULoginReqModel.h
//  LSBluetooth-Library
//
//  Created by lifesense－mac on 17/3/2.
//  Copyright © 2017年 Lifesense. All rights reserved.
//

#import "LSUBaseModel.h"

@interface LSULoginReqModel : LSUBaseModel

// LifeSense设备认证算法（Device ID）XOR MAC）验证码
@property (nonatomic, strong) NSString *verifyCode;

// "表示用户在设备中分配的用户号
// 0：客人/未识别用户
// 1~4：已识别用户
// 255：无效用户"
@property (nonatomic, assign) NSUInteger userNumber;

// 电池剩余电量百分比，单位0-100
@property (nonatomic, assign) NSUInteger battery;

@end
