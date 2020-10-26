//
//  LSUSportHeartRate.h
//  LSBluetooth-Library
//
//  Created by 陈俊铭 on 16/2/22.
//  Copyright © 2016年 Lifesense. All rights reserved.
//

#import "LSUHearRate.h"
#import "LSConst.h"

@interface LSUSportHeartRate : LSUHearRate

@property (nonatomic, assign) LSSportHartDataType type;
@property (nonatomic, assign) LSSportModeType sportMode;
@property (nonatomic, assign) LSSubModeType subMode;

@end
