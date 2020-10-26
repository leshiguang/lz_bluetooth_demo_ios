//
//  LSBluetoothUIManager.h
//  KMNavigationBarTransition
//
//  Created by wm on 2020/9/4.
//

//#import "LSWAppAppearanceConfigrationMacro.h"
//#import "LSWAppColorConfigrationMacro.h"
//#import "LSWAppFontConfigrationMacro.h"
//#import "Device+LSWDeviceUtility.h"
//#import "LSWConstants.h"
//#import "NSString+LSAdditions.h"
//#import "LSWUnitManager+Weight.h"
//#import "UIColor+Hex.h"
//#import "NSString+LSWAddition.h"
//#import "TKAlertViewController.h"
//#import "LSWAttributedUtil.h"
//#import "ServerCommunicationManager.h"
//#import "LSWRouter.h"
//#import "LSWRouterDefine.h"
//#import "LSWMacro.h"
//#import "NSBundle+LSBluetoothUI.h"
//#import "LSBluetoothUIConfig.h"
//#import <LSDeviceManagerFramework/LSDeviceManager+BraceletSetting.h>
//#import <LSDeviceManagerFramework/LSDeviceManager+ScalesSetting.h>

typedef enum : NSUInteger {
    LSBluetoothResultTypeSusses, //成功
    LSBluetoothResultTypeFaile   //失败
} LSBluetoothResultType;

#import <Foundation/Foundation.h>
#import "LSBluetoothUIConfig.h"

NS_ASSUME_NONNULL_BEGIN

@interface LSBluetoothUIManager : NSObject
+ (instancetype)shareInstance;

@property (nonatomic, assign) LSBluetoothResultType resultType;

#pragma mark - 初始化Api


/// 初始化
/// @param accuountInfo 账号信息
- (void)initBluetoothUISDK:(LSBluetoothUIAccountInfo *)accuountInfo;

/// 更新用户信息
/// @param userInfo 用户信息
- (void)updateUserInfo:(LSBluetoothUIUserInfo *)userInfo completion:(void(^)(LSBluetoothResultType resultType))completion;

#pragma mark - 调用乐智界面Api

/// 设备列表页面
- (UIViewController *)lsPageDeviceList;
/// 我的设备页面
- (UIViewController *)lsPageBindDeviceList;
/// 打开体重页面
- (void)lsOpenWeightPage;
/// 血压页面
- (void)lsBloodpressurePage;
/// 心率页面
- (void)lsHeartRatePage;
/// 有氧能力
- (void)lsAerobicRatePage;
/// 睡眠
- (void)lsSleepRatePage;
/// 步数
- (void)lsStepPage;

#pragma mark - 版本

/// 获取当前版本号
- (NSString *)getVersion;

@end

NS_ASSUME_NONNULL_END
