//
//  LSNDBTableCoding.h
//  LSNDBManager
//
//  Created by Wenzheng Zhang on 2017/10/4.
//  Copyright © 2017年 Wenzheng Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WCDB/WCDB.h>

@protocol LSNDBTableCoding <WCTTableCoding>
/**
 表名，默认为类名
 
 @return 表名
 */
+ (NSString*)LSNDB_tableName;
@end
