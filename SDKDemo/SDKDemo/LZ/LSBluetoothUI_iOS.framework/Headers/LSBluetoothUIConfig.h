//
//  LSBluetoothUIConfig.h
//  LSBluetoothUI_iOS
//
//  Created by wm on 2020/9/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LSBluetoothUIAccountInfo : NSObject
//乐智用户ID
@property (nonatomic, strong) NSString *userId;
//登录token
@property(nonatomic, strong) NSString *accessToken;
//外部token
@property(nonatomic, strong) NSString *businessToken;
//是否需要补充信息（新注册用户为true）
@property(nonatomic) BOOL needInfo;
@end

@interface LSBluetoothUIUserInfo : NSObject
/// 用户id
@property (nonatomic, copy) NSNumber *id;
/// 用户昵称
@property (nonatomic, copy) NSString *name;
/// 头像
@property (nonatomic, copy) NSString *headImg;
/// sex 1-男， 2-女
@property (nonatomic, copy) NSNumber *sex;
/// 生日 1402300000
@property (nonatomic, copy) NSString *birthday;
/// 身高 cm
@property (nonatomic, copy) NSNumber *height;
/// 腰围（单位：cm）
@property (nonatomic, copy) NSNumber *waist;
/// Integer 长度单位:0/null-公制;1-公制;2-英制
@property (nonatomic, copy) NSNumber *lengthUnit;
/// Integer 体重单位:0/null-千克;1-千克;2-斤;3-磅;4-英石
@property (nonatomic, copy) NSNumber *weightUnit;

@end

@interface LSBluetoothUIConfig : NSObject

/** 默认使用的语言版本, 默认为 nil. 将随系统的语言自动改变 */
@property (copy, nonatomic, nullable) NSString *languageCode;

@property (nonatomic, strong) LSBluetoothUIUserInfo *userInfo;

@property (nonatomic, strong) LSBluetoothUIAccountInfo *accountInfo;

/** @return Singleton Config instance */
+ (instancetype)defaultConfig;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end
NS_ASSUME_NONNULL_END
