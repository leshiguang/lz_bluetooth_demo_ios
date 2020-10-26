//
//  LSDLoginRespModel.h
//  LSBluetooth-Library
//
//  Created by lifesense－mac on 17/3/2.
//  Copyright © 2017年 Lifesense. All rights reserved.
//

#import "LSDBaseModel.h"

@interface LSDLoginRespModel : LSDBaseModel

// 登陆是否成功
@property (nonatomic, assign) BOOL loginSuccess;

// 校验码, 6个字节
@property (nonatomic, strong) NSString *verifyCode;

//// deviceId
//@property (nonatomic, strong) NSString *deviceId;
//
//// mac address
//@property (nonatomic, strong) NSString *macAddr;

// 工作状态
// 0：正常工作数据通信；
// 1：绑定数据通信；
// 2：解绑数据通信。
@property (nonatomic, assign) NSUInteger workType;


@end
