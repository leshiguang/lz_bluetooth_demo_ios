//
//  LSNDBSelect+Private.h
//  LSNDBManager
//
//  Created by Wenzheng Zhang on 2017/10/4.
//  Copyright © 2017年 Wenzheng Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSNDBSelect.h"
#import <WCDB/statement_recyclable.hpp>
#import <WCDB/WCTChainCall+Private.h>
#import <WCDB/WCTCore+Private.h>
#import <WCDB/WCTResult.h>
#import <WCDB/WCTRowSelect+Private.h>
#import <WCDB/WCTRowSelect.h>
#import <WCDB/WCTSelectBase+Private.h>
#include "StatementRawSelect.hpp"

@interface LSNDBSelect () {
@protected
    BOOL _prepared;
    WCDB::RecyclableStatement _statementHandle;
    WCDB::StatementRawSelect _statement;
}

- (instancetype)initWithCore:(const std::shared_ptr<WCDB::CoreBase> &)core andResults:(const WCTResultList &)resultList searchSQL:(NSString *)searchSQL;
- (BOOL)lazyPrepare;
- (BOOL)next;
- (void)finalize;
@end
