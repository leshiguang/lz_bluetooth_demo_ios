//
//  LSNDBBaseDataModel.h
//  LSNDBManager
//
//  Created by Wenzheng Zhang on 2017/10/4.
//  Copyright © 2017年 Wenzheng Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSNDBDataModelSelfCheckingProtocol.h"
#import "LSNDBDataModelProtocol.h"

@interface LSNDBBaseDataModel : NSObject <LSNDBDataModelSelfCheckingProtocol, LSNDBDataModelProtocol>
@end
