//
//  LSNDBDataModelProtocol.h
//  LSNDBManager
//
//  Created by Wenzheng Zhang on 2017/10/4.
//  Copyright © 2017年 Wenzheng Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol LSNDBDataModelProtocol <NSObject>
- (void)setPropertysFromDict:(NSDictionary*)dict;
@optional
- (NSDictionary*)dictionaryFromProperties;
@end
