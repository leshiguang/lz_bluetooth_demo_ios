//
//  LSNDBSelect.h
//  LSNDBManager
//
//  Created by Wenzheng Zhang on 2017/10/4.
//  Copyright © 2017年 Wenzheng Zhang. All rights reserved.
//

#import <WCDB/WCTDeclare.h>
#import <WCDB/WCTSelectBase.h>


@interface LSNDBSelect : WCTChainCall


/**
 @brief Get next selected object. You can do an iteration using it.
 
 WCTObject* object = nil;
 while ((object = [select nextObject]) {
 //...
 }
 
 @return The real type of WCTObject depends on your selection and ORM.
 */
- (id /* WCTObject* */)nextObject;

/**
 @brief Get all selected objects.
 @return The NSArray collection of WCTObject.
 The real type of WCTObject depends on your selection and ORM.
 */
- (NSArray /* <WCTObject*> */ *)allObjects;
@end
