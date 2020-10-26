//
//  LSNDBDelete+Private.h
//  LSNDBManager
//
//  Created by Wenzheng Zhang on 2017/10/4.
//  Copyright © 2017年 Wenzheng Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSNDBDelete.h"
#import <WCDB/WCTChainCall+Private.h>
#import <WCDB/WCTDelete.h>
#include "StatementRawDelete.hpp"


@interface LSNDBDelete (Private)
- (instancetype)initWithCore:(const std::shared_ptr<WCDB::CoreBase> &)core sql:(NSString *)sql;
@end
