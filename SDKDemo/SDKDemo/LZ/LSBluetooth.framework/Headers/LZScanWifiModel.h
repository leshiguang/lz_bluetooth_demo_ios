//
//  LSDSanWifiModel.h
//  LSBluetooth
//
//  Created by wm on 2020/9/30.
//

#import "LSDBaseModel.h"
#import "LSConst.h"

NS_ASSUME_NONNULL_BEGIN

@interface LZScanWifiModel : LSDBaseModel
@property (nonatomic, assign) NSUInteger showHidden;
@property (nonatomic, assign) NSUInteger scanType;
@end

NS_ASSUME_NONNULL_END
