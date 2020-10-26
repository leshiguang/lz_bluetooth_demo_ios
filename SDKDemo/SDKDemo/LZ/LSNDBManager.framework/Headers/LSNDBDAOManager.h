//
//  LSNDBDAOManager.h
//  LSNDBManager
//
//  Created by Wenzheng Zhang on 2017/10/4.
//  Copyright © 2017年 Wenzheng Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSNDBBaseDAOProtocol.h"

@interface LSNDBDAOManager : NSObject


/**
 保存DB文件的文件夹

 @return 保存DB文件的文件夹
 */
+ (NSString *)dbsDirectory;

/**
 初始化LSNDBDAOManager

 @param dbName db名，若为nil，使用默认db
 @return LSNDBDAOManager实例
 */
- (instancetype)initWithDBName:(NSString *)dbName;


/**
 获取DAO类

 @param modelClass modle类
 @return dao
 */
- (id<LSNDBBaseDAOProtocol>)getDAOByClass:(Class)modelClass;
@end
