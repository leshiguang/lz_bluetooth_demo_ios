//
//  LSBBleExceptionRecord.h
//  LSBluetooth-Library
//
//  Created by lifesense－mac on 17/10/26.
//  Copyright © 2017年 Lifesense. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LSBBleExceptionRecord : NSObject

@property (nonatomic, assign) NSUInteger errorCategoryCode;

@property (nonatomic, assign) NSUInteger errorCode;

@property (nonatomic, strong) NSString *firmwareVersion;

@property (nonatomic, strong) NSString *modelNumber;

@end
