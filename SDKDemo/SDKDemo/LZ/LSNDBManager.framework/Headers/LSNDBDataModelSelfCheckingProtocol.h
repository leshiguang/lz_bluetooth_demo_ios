//
//  LSNDBDataModelSelfCheckingProtocol.h
//  LSNDBManager
//
//  Created by Wenzheng Zhang on 2017/10/4.
//  Copyright © 2017年 Wenzheng Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol LSNDBDataModelSelfCheckingProtocol <NSObject>
@required


/**
 检查数据正确性
 
 @param shouldAdjust 在数据不合法时，是否需要自行调整
 @return 数据是否正确，包含调整后的结果。
 */
- (BOOL)checkDataValidity:(BOOL)shouldAdjust;
@end
