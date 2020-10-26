//
//  LSULogData.h
//  LSBluetooth-Library
//
//  Created by lifesense－mac on 17/11/17.
//  Copyright © 2017年 Lifesense. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSUBaseModel.h"

@interface LSULogData : LSUBaseModel

@property (nonatomic, assign) NSUInteger time;

@property (nonatomic, assign) NSUInteger code;

@property (nonatomic, strong) NSString *content;

@end
