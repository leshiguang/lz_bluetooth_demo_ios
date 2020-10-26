//
//  LZConnectWifiModel.h
//  LSBluetooth
//
//  Created by wm on 2020/10/8.
//

#import "LSDBaseModel.h"
#import "LSConst.h"

NS_ASSUME_NONNULL_BEGIN

@interface LZConnectWifiModel : LSDBaseModel
@property (nonatomic, strong) NSString *bSsid;
@property (nonatomic, assign) NSInteger connected;
@property (nonatomic, assign) NSInteger passwrodLength;
@property (nonatomic, strong) NSString *password;
@end

NS_ASSUME_NONNULL_END
