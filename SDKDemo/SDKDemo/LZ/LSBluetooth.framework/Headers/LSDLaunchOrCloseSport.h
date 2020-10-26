//
//  LSDLaunchOrCloseSport.h
//  LSBluetooth-Library
//
//  Created by boluobill on 16/03/2018.
//  Copyright © 2018 Lifesense. All rights reserved.
//

#import "LSDBaseModel.h"
#import "LSConst.h"

@interface LSDLaunchOrCloseSport : LSDBaseModel

/**
 * 运动类型 (参见运动模式)
 */
@property(nonatomic, assign) LSSportModeType modeType;

/**
 * 运动状态
 */
@property(nonatomic, assign) LSLaunchSportMode state;

@end
