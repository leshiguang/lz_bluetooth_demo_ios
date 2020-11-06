//
//  lzReceiveDataSqliteModel.h
//  LSDeviceManagerFrameworkTests
//
//  Created by wm on 2020/10/19.
//  Copyright © 2020 Wenzheng Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BraceletReceiveDataState.h"

NS_ASSUME_NONNULL_BEGIN

@interface lzReceiveDataSqliteModel : NSObject

@property (nonatomic, strong) NSString *dataId;

@property (nonatomic, strong) NSString *userId;

@property (nonatomic, strong) NSString *data;

@property (nonatomic, assign) NSInteger sync;

@property (nonatomic, assign) BraceletReceiveDataType dataType;

@end

NS_ASSUME_NONNULL_END
