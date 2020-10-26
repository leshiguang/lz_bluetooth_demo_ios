//
//  LZUIViewController.h
//  SDKDemo
//
//  Created by wm on 2020/10/16.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface LZUIViewController : UIViewController
//乐智用户ID
@property (nonatomic, strong) NSString *userId;
//登录token
@property(nonatomic, strong) NSString *accessToken;
@end

NS_ASSUME_NONNULL_END
