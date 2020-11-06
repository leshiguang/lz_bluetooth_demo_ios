//
//  RequestMap.h
//  LSWearable
//
//  Created by rolandxu on 12/18/15.
//  Copyright © 2015 lifesense. All rights reserved.
//
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface RequestMap : NSObject

/**
 当前host
 */
//@property (nonatomic, readonly) NSString *currentHost;

+ (instancetype)shareInstance;

/**
 获取request

 @param name 请求名
 @return request
 */
- (nullable NSString *)getRequestV2UrlByName:(NSString *)name;

/**
 获取response

 @param name 请求名
 @return response
 */
- (nullable NSString *)getResponseV2ByName:(NSString *)name;

/**
 添加自定义的protocol
 */
- (void)addProtocolWithFilePath:(NSString *)filePath;


/// 打开测试环境，默认为正式环境
- (void)openDebug;

/// 获取当前环境 YES是测试环境 NO是正式环境
- (BOOL)getDebugState;

/// 获取当前host
- (NSString *)currentHostStr;
@end

NS_ASSUME_NONNULL_END

