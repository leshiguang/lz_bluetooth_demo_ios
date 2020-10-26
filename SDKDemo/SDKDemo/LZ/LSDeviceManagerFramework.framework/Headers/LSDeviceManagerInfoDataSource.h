//
//  LSDeviceManagerInfoDataSource.h
//  LSDeviceManagerFramework
//
//  Created by Wenzheng Zhang on 2017/9/12.
//  Copyright © 2017年 Wenzheng Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 dataSource的方法会在不同线程同时调用，请实现方确保线程安全
 */
@protocol LSDeviceManagerInfoDataSource <NSObject>
@required

/**
 App上所登陆过的所有用户Id

 @return 用户Id数组
 */
- (NSArray *)allUserIds;

@end
