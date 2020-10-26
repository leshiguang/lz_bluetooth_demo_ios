//
//  LSDeviceManager+Bind.h
//  LSDeviceManagerFrameworkTests
//
//  Created by alex.wu on 2019/9/9.
//  Copyright © 2019 Wenzheng Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSDeviceManager.h"

NS_ASSUME_NONNULL_BEGIN



@interface LSDeviceManager(Bind)<LSBindDelegate,LSBleDataReceiveDelegate>


/**
 从缓存获取指定产品类型的产品列表
 
 @param category 产品类别
 @param completion 回调
 */
- (void)getProductInfoListFromCacheForCategoryType:(LSEProductCategory)category completion:(LSEProductInfoBlock)completion;

/**
 获取指定产品类型的产品列表
 
 @param category 产品类别
 @param completion 回调
 */
- (void)getProductInfoListForCategoryType:(LSEProductCategory)category completion:(LSEProductInfoBlock)completion;

- (void)applyDeviceIdWithInfo:(LSEApplyDeviceIdInfo *)deviceInfo completion:(void(^)(int code, NSString *msg, NSString *deviceId, NSString *mac))completion;

- (NSArray *)cachedProductInfoListForCategoryType:(LSEProductCategory)category;

- (void)saveProductInfoListForCategoryType:(LSEProductCategory)category productInfoList:(NSDictionary *)productInfoDic;

- (NSArray<LSEProductInfo *> *)productInfoListFormDictArray:(NSArray<NSDictionary *> *)dictArray;


/**
 * 仅绑定设备时使用，其它时候不要用
 */
- (void)findTargetDevice:(NSString *)broadcastId type:(NSString *)type completion:(void(^)(BOOL isSuccess))findCompletion;

/**
 *  根据二维码绑定设备（蓝牙或wifi）
 */
-(void)bindingDeviceuserId:(NSString *)userId qrCode:(NSString *)qrCode userNo:(NSNumber *)userNo Completion:(void(^)(int code,NSString *msg,Device *device,NSArray<DeviceUser *>*user))completion;

// 通过DeviceID来绑定设备
- (void)bindDeviceWithDeviceId:(NSString *)deviceId userId:(NSString *)userId completion:(void(^)(int code,NSString *msg,Device *device,NSArray<DeviceUser *>*user))completion;

- (void)reSearchDevice;


/**
 *  绑定手环
 *
 */
- (void)pairDevice:(LSEDeviceInfo *)deviceInfo;

/**
 * 用户绑定手环校验码
 *
 */

/// 用户绑定手环校验码
/// @param code 校验码
/// @param deviceInfo 设备信息
- (void)inputCode:(NSString *)code deviceInfo:(LSEDeviceInfo *)deviceInfo;

/// 取消绑定
/// @param deviceInfo 设备信息
/// @param completion
- (void)cancelPair:(LSEDeviceInfo *)deviceInfo completionBlock:(Completion)completion;


- (Device *)getPairDevice:(LSDeviceInfo *)device;


/**
 * 搜索设备,在结束配对流程后需要调用调用startDataReceiveService
 *
 */

/// 搜索设备,在结束配对流程后需要调用调用startDataReceiveService
/// @param productInfo 设备信息
/// @param searchBlock 回调
- (void)searchDevice:(LSEProductInfo *)productInfo searchBlock:(LSESearchBlock)searchBlock;

/// 停止搜索设备
/// @param stopSearchBlock 停止收缩回调
- (void)stopSearchDevice:(LSEStopSearchBlock)stopSearchBlock;


-(void)cancelFindTargetDevice;

@end

NS_ASSUME_NONNULL_END
