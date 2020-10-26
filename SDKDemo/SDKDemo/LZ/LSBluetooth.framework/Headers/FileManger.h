//
//  FileManger.h
//  log文件工具类
//
//  Created by lifesense on 16/3/22.
//  Copyright © 2016年 彭涛. All rights reserved.
//
#import <Foundation/Foundation.h>
@class LSBleActionEvent;

@interface FileManger : NSObject
@property (nonatomic,copy)NSString *logFolderPath;
@property (nonatomic,copy)NSString *userID;
@property (nonatomic,copy)NSString *mac;
@property (nonatomic,copy)NSString *version;
+(instancetype)filemanager;
-(void)writeFileData:(LSBleActionEvent *)logModel;
@end
