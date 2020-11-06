//
//  LSNewAccountAuthorizeRequest.h
//  LSAuthorization
//
//  Created by wm on 2020/11/6.
//

#import <Foundation/Foundation.h>
#import <LSNetwork_iOS/LSBaseRequest.h>

NS_ASSUME_NONNULL_BEGIN

@interface LSNewAccountAuthorizeRequest : LSBaseRequest

- (void)addParamesWithDic:(NSDictionary *)dic;

- (void)urlAppendingString:(NSString *)str;

@end

NS_ASSUME_NONNULL_END
