//
//  LSDNightMode.h
//  LSBluetooth-Library
//
//  Created by lifesense on 16/8/1.
//  Copyright © 2016年 Lifesense. All rights reserved.
//

#import "LSDBaseModel.h"

@interface LSDNightMode : LSDBaseModel
@property (nonatomic, assign) BOOL isOpen;
@property (nonatomic, assign) int startHour;
@property (nonatomic, assign) int startMin;
@property (nonatomic, assign) int endHour;
@property (nonatomic, assign) int endMin;
@end
