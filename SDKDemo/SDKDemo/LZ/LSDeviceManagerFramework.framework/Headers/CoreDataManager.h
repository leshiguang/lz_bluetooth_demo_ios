// CoreDataManager.h
//
// Copyright (c) 2014 Marin Usalj <http://supermar.in>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@interface CoreDataManager : NSObject

@property (readonly, strong, nonatomic) NSManagedObjectContext *managedObjectContext;
@property (readonly, strong, nonatomic) NSManagedObjectModel *managedObjectModel;
@property (readonly, strong, nonatomic) NSPersistentStoreCoordinator *persistentStoreCoordinator;
@property (nonatomic, copy) NSString *dataBase;

- (void)saveContext;
- (NSURL *)applicationDocumentsDirectory;

/**
 * 将会关闭数据库操作，并且也会保存关闭前数据库的数据，所以无需再调一次@see saveContext
 */
- (void)cleanUp;
+ (instancetype)sharedManager;
/**
 *  获取数据库本地路径
 *
 *  @return 数据库路径
 */
- (NSString *)getDataBasePath;
@end
