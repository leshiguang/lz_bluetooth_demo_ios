//
//  WCTInterface+LSNDBConvenient.h
//  LSNDBManager
//
//  Created by Wenzheng Zhang on 2017/10/4.
//  Copyright © 2017年 Wenzheng Zhang. All rights reserved.
//

#import <WCDB/WCTDeclare.h>
#import <WCDB/WCTInterface.h>

@interface WCTInterface (LSNDBConvenient)
// search
- (NSArray /* <WCTObject*> */ *)getAllObjectsOfClass:(Class)cls sql:(NSString *)sql;

// delete
- (BOOL)deleteObjectsFromTable:(NSString *)tableName whereStr:(NSString *)whereStr;
@end
