//
//  LSDNotDisturbMode.h
//  LSBluetooth-Library
//
//  Created by boluobill on 2018/8/22.
//  Copyright © 2018 Lifesense. All rights reserved.
//

#import "LSDBaseModel.h"

@interface LSDNotDisturbMode : LSDBaseModel

@property (nonatomic, assign) BOOL isNotDisturbOpen;
@property (nonatomic, assign) int startHour;
@property (nonatomic, assign) int startMin;
@property (nonatomic, assign) int endHour;
@property (nonatomic, assign) int endMin;
@property (nonatomic, assign) BOOL isLightWhenUpOpen;

@end
