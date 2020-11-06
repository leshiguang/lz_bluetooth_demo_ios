//
//  LSAuthorizeTool.h
//  LSAuthorization
//
//  Created by wm on 2020/11/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LSAuthorizeTool : NSObject

+ (NSString *)generateSignWithDiction:(NSDictionary *)dic;

@end

NS_ASSUME_NONNULL_END
