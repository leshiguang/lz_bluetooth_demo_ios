//
//  LSDeviceManager+Commons.h
//  LSDeviceManagerFrameworkTests
//
//  Created by alex.wu on 2019/9/9.
//  Copyright © 2019 Wenzheng Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSDeviceManager.h"
NS_ASSUME_NONNULL_BEGIN

@interface LSDeviceManager(Commons)


//UUID
-(NSString*)UUIDString;

//获取当前时间戳
-(NSNumber *)timeStamp;


-(NSString*)objectToJson:(id)object;


- (NSString *)dictToJson:(NSDictionary *)dict;


- (BOOL)containsSportType:(NSNumber *)type inArry:(NSArray<NSNumber *> *) array;

- (LSSportItemType)sportTypeInsteadof:(ScreenContentType)type;

- (ScreenContentType)screenTypeInsteadof:(LSSportItemType)type;

- (void)log2file:(NSString *)format,...;

-(NSCalendar *) currentCalendar;

//一天时间的开始
- (NSDate *)dateAtStartOfDay:(NSDate *)date;

-(NSString *)firstTimeWithDate:(NSString *)date ;

- (NSDate *)dateWithString:(NSString *)string withFormat:(NSString *)format ;

//一天的结束时间
- (NSDate *)dateAtEndOfDay:(NSDate *)date;


- (id)jsonToObject:(NSString *)json;

-(NSDate *)dataFormatter:(NSString *)str;

-(NSDate *)stringToDate:(NSString *)str;

-(NSString *)dateToStr:(NSDate *)date;


- (NSArray<NSString *> *)seperatedImagesFromImageUrl:(NSString *)imageurl;

- (NSString *)dateStringWithDate:(NSDate *)date;


/**
 *  计算T
 *
 *  @param step   20S步数
 *  @param height 身高(cm)
 *
 *  @return T
 */
+ (int)calcT:(int)step height:(int)height;

+ (float)calcEX:(int)t;

/**
 *  获取20S的卡路里
 *
 *  @param weight 体重(kg)
 *  @param height 身高(cm)
 *  @param step   20s的步数
 *
 *  @return  单位Kcal(千卡/大卡）
 */
+ (float)calcCalories:(float)weight height:(int)height step:(int)step;


+ (int)calcDistance:(int)step height:(int)height interval:(int)interval;

-(double)countCalorieWithWeight:(double)weight time:(int)time speed:(double)speed;

@end

NS_ASSUME_NONNULL_END
