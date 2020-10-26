//
//  LSWifiConfig.h
//  LSWifiConfig
//
//  Created by 陈俊铭 on 16/3/9.
//  Copyright © 2016年 陈俊铭. All rights reserved.
//

#include <UIKit/UIKit.h>


@class LSWifiConfig;

//extern void handler_WifiConfig_callback(void *object, int errCode);


/**
 *  WifiConfig错误代码
 */
typedef NS_ENUM(NSInteger, LSWifiConfigCode) {
    /**
     *  配对成功
     */
    LSWifiConfigSuccess = 0,
    /**
     *  配对超时
     */
    LSWifiConfigTimeOut,
    /**
     * 出错
     */
    LSWifiConfigError,
    
};

/**
 *  WifiConfig委托
 */
@protocol LSWifiConfigDelegate <NSObject>

@optional
/**
 *  WifiConfig回调
 *
 *  @param WifiConfig 实例
 *  @param errCode 错误代码，WifiConfigCode
 */
- (void)wifiConfigCallBack:(LSWifiConfig *)WifiConfig errCode:(LSWifiConfigCode)errCode;

@end

/**
 *  连接乐心智能设备的WifiConfig，目前支持IOS6.0以上版本
 */
@interface LSWifiConfig : NSObject

/**
 * 事件回调委托
 */
@property (nonatomic, weak) id<LSWifiConfigDelegate> delegate;

/**
 * 超时时间，单位毫秒,默认50秒
 */
@property (nonatomic, assign) int timeout;

/**
 LSWifiConfig单例对象

 @return LSWifiConfig对象
 */
+ (instancetype)shared;

/**
 *  停止WifiConfig接收发送
 */
- (void)stop;

/**
 *  开始配置
 *
 *  @param ssid WIFI的SSID,可为nil
 *  @param pwd  WIFI密码
 */
- (void)startConfig:(NSString *)ssid pwd:(NSString *)pwd;

/**
 * WifiConfig版本
 *
 */
+ (NSString *)version;

/**
 * C++ 调 OC,这个函数勿动，非外部使用
 */
- (void)bridgeCallDelegate:(int)errCode;

@end
