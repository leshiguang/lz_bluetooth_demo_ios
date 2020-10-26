//
//  LSNDBBaseDAO.h
//  LSNDBManager
//
//  Created by Wenzheng Zhang on 2017/10/4.
//  Copyright © 2017年 Wenzheng Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WCDB/WCDB.h>
#import "LSNDBBaseDAOProtocol.h"
#import "LSNDBTableCoding.h"

@interface LSNDBBaseDAO : NSObject <LSNDBBaseDAOProtocol>
@property (nonatomic, weak, readonly) Class<LSNDBTableCoding> entityClass;
+ (instancetype)daoWithEntityClass:(Class)aClass database:(WCTDatabase *)database workQueue:(NSOperationQueue *)workQueue;
@end
