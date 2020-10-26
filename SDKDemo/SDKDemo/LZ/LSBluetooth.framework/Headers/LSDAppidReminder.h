//
//  LSDAppidReminder.h
//  LSBluetooth-Library
//
//  Created by ljj on 7/11/2018.
//  Copyright © 2018 Lifesense. All rights reserved.
//

#import "LSDBaseModel.h"
#import "LSConst.h"


NS_ASSUME_NONNULL_BEGIN

@interface LSDAppidReminder : LSDBaseModel

@property (nonatomic, assign)   LSCallReminderAlertType type;
@property (nonatomic, assign)   int isOpen;//0关 1开  ff删除所有
@property (nonatomic, retain)   NSString *appid; //包名



@end

NS_ASSUME_NONNULL_END
