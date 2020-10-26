//
//  LSNDBBaseDAOProtocol.h
//  LSNDBManager
//
//  Created by Wenzheng Zhang on 2017/10/4.
//  Copyright © 2017年 Wenzheng Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol LSNDBBaseDAOProtocol <NSObject>
@required
- (NSError *)saveEntity:(id)entity;
- (void)saveEntity:(id)entity callback:(void (^)(NSError *error))callback;
- (void)saveEntityWithArray:(NSArray *)array callback:(void (^)(NSError *error))callback;


/**
 批量存储数据，若单条数据存储失败，整体回滚

 @param array 数据
 @return 是否成功
 */
- (NSError *)saveEntityWithArray:(NSArray *)array;


/**
 批量存储数据，若单条数据存储失败，忽略此条，继续存储

 @param array 数据
 @param useReplace 是否使用insert or replace语句
 @return commit是否失败，commit成功，但是有默写数据存储失败，不会报错
 */
- (NSError *)saveEntityAsMuchAsPossibleWithArray:(NSArray *)array useReplace:(BOOL)useReplace;

- (NSArray *)loadEntityWithWhere:(NSString *)where order:(NSString *)order;
- (NSArray *)loadEntityWithWhere:(NSString *)where order:(NSString *)order offset:(NSInteger)offset count:(NSInteger)count;
- (void)loadEntityWithWhere:(NSString *)where order:(NSString *)order offset:(NSInteger)offset count:(NSInteger)count callback:(void (^)(NSArray *))callback;

//复杂查询可以用这个方法,自己写SQL
- (void)loadEntityWithSQL:(NSString *)sql callback:(void (^)(NSArray *array))callback;
- (NSArray *)loadEntityWithSQL:(NSString *)sql;

- (NSError *)deleteEntityWithWhere:(NSString *)where;
- (void)deleteAllEntity;

@end
