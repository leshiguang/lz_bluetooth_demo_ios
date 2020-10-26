//
//  LSScaleWifiModel.h
//  LSBluetooth
//
//  Created by wm on 2020/10/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LSScaleWifiModelItem : NSObject
@property (nonatomic, copy) NSString *ssidName;
@property (nonatomic, copy) NSString *bssid;
@end

@interface LSScaleWifiModel : NSObject
@property (nonatomic, copy) NSArray *wifiModelAry;
@end

NS_ASSUME_NONNULL_END
