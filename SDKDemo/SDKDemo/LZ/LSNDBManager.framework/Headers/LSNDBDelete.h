//
//  LSNDBDelete.h
//  LSNDBManager
//
//  Created by Wenzheng Zhang on 2017/10/4.
//  Copyright © 2017年 Wenzheng Zhang. All rights reserved.
//

#import <WCDB/WCTDeclare.h>
#import <WCDB/WCTChainCall.h>

@interface LSNDBDelete : WCTChainCall
/**
 @brief Execute the delete SQL.
 @return YES if no error occurs.
 */
- (BOOL)execute;

/**
 @brief It should be called after executing successfully
 @return the number of changes in the most recent call
 */
- (int)changes;
@end
