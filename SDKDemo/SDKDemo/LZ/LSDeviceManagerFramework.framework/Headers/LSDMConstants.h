//
//  LSDMConstants.h
//  LSDeviceManagerFramework
//
//  Created by Wenzheng Zhang on 2017/9/12.
//  Copyright © 2017年 Wenzheng Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>



//运动卡路里数据类型
typedef NS_ENUM(NSUInteger,LSDMSportCaloriesDataType) {
    //旧运动卡路里数据
    LSDMSportCaloriesDataTypeOld,
    //新运动卡路里数据
    LSDMSportCaloriesDataTypeNew,
};

// 游泳模式类型
typedef NS_ENUM(NSUInteger,LSESwimType)
{
    //手动进入游泳模式
    LSESwimTypeManuallyEnter,
    //自动识别游泳模式
    LSESwimTypeAutomaticEnter,
};

// 跑步类型
typedef enum : NSUInteger {
    //watch跑步数据（手动）
    LSERunningTypeWatchSportMode,
    //自动识别跑步数据
    LSERunningTypeAutoSportMode,
    //轨迹跑有通知到APP
    LSERunningTypeGPSSportMode,
    //轨迹跑没有通知到APP
    LSERunningTypeNoGPSSportMode,
    
    /// mio手表手动发起自带Gps数据
    LSErunningTypeMantleGPSSportMode = 8,
    
    /// MAF180跑
    LSERunningMAF180Mode = 20,
    
} LSERunningType;

//手环发送运动模式类型
typedef NS_ENUM(NSUInteger,LSDMSportModeType) {
    /**
     * 跑步模式
     */
    LSDMSportModeTypeSportMode = 1,
    /**
     * 健走模式
     */
    LSDMWalkingModeTypeSportMode,
    /**
     * 骑行模式
     */
    LSDMCyclingModeTypeSportMode,
    /**
     * 游泳模式
     */
    LSDMSwimingModeTypeSportMode,
    /**
     * 健身模式
     */
    LSDMKeepfitModeTypeSportMode,
    /**
     * 新跑步模式
     */
    LSDMRunningModeTypeSportMode,
    /**
     * 新跑步模式-12分钟跑
     */
    LSDM12MinRunningModeTypeSportMode,
    /**
     * 新跑步模式-6分钟走
     */
    LSDM6MinWalkingModeTypeSportMode,

};

//手环发送子模式类型
typedef NS_ENUM(NSUInteger, LSDMSubModeType) {
    //手动进入步模式
    LSDMSubModeTypeManuallyEnter,
    //自动识别模式
    LSDMSubModeTypeAutomaticEnter,
};

//手环发送运动健走子模式类型
typedef NS_ENUM(NSUInteger,LSDMWalkingSubModeType)
{
    //手动进入健走模式
    LSDMWalkingSubModeTypeManuallyEnter,
    //自动识别健走模式
    LSDMWalkingSubModeTypeAutomaticEnter,
};

/**
 * 步频信息
 */
typedef NS_ENUM(NSUInteger, LSDMStepFreqStatus) {
    /**
     * 跑步开始
     */
    LSDMStepFreqStatusRunStart,
    /**
     * 跑步结束
     */
    LSDMStepFreqStatusRunOver,
    /**
     * 跑步暂停
     */
    LSDMStepFreqStatusRunPause,
    /**
     * 跑步重新开始
     */
    LSDMStepFreqStatusRunReStart
};
typedef LSDMStepFreqStatus LSDMWalkFreq;

typedef LSDMStepFreqStatus LSDMWalkFreq;

typedef LSDMStepFreqStatus LSDMRunningStepStatus;




@interface NSString (LSA6Peripheral)

/**
 通过model 判断是否是a6设备
 
 @return yes & no
 */
- (BOOL)isA6DeviceModel;

- (BOOL)isEcgDeviceModel;

@end

@interface LSDMConstants : NSObject



@end
