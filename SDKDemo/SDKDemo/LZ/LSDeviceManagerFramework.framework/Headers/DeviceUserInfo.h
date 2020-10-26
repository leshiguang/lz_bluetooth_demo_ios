//
//  DeviceUserInfo.h
//  LSWearable
//
//  Created by lifesense on 16/12/6.
//  Copyright © 2016年 lifesense. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DeviceUserInfo : NSObject
/** 
 *体重 kg */
@property (nonatomic, assign) float weight;
/** 
 *身高 cm */
@property (nonatomic, assign) int height;

@property (nonatomic, assign) int age;


/**
 sex 0-男， 1-女
 */
@property (nonatomic, assign) int sex;

/*用户在乐心上看到的乐心id*/
@property (nonatomic, assign) long id_p;
@end
