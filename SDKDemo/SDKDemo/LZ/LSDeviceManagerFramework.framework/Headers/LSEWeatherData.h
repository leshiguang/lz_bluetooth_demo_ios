//
//  LSEWeatherData.h
//  LSWearable
//
//  Created by 郭景煊 on 17/1/12.
//  Copyright © 2017年 lifesense. All rights reserved.
//

#import <Foundation/Foundation.h>

//Push天气类型设置
typedef NS_ENUM(NSUInteger,LSEWeatherType)
{
    /**
     * 晴(白天)
     */
    LSEWeatherTypeSunnyDuring = 0,
    /**
     * 晴(晚上)
     */
    LSEWeatherTypeSunnyNight,
    /**
     * 多云
     */
    LSEWeatherTypeCloudy,
    /**
     * 晴间多云(白天)
     */
    LSEWeatherTypeSunnyAndCloudyDuring,
    /**
     * 晴间多云(夜晚)
     */
    LSEWeatherTypeSunnyAndCloudyNight,
    /**
     * 大部多云（白天）
     */
    LSEWeatherTypeMostCloudyDuring,
    /**
     * 大部多云（夜晚）
     */
    LSEWeatherTypeMostCloudyNight,
    /**
     * 阴天
     */
    LSEWeatherTypeGloomy,
    /**
     * 阵雨
     */
    LSEWeatherTypeShower,
    /**
     * 雷阵雨
     */
    LSEWeatherTypeThunderyShower,
    /**
     * 冰雹或雷阵雨伴有冰雹
     */
    LSEWeatherTypeHail,
    /**
     * 小雨
     */
    LSEWeatherTypedRizzle,
    /**
     * 中雨
     */
    LSEWeatherTypedModerateRain,
    /**
     * 大雨
     */
    LSEWeatherTypedDownpour,
    /**
     * 暴雨
     */
    LSEWeatherTypedHeavyRains,
    /**
     * 大暴雨
     */
    LSEWeatherTypedBigHeavyRains,
    /**
     * 特大暴雨
     */
    LSEWeatherTypedRainstorm,
    /**
     * 冻雨
     */
    LSEWeatherTypedFreezingRain,
    
    /**
     * 雨夹雪
     */
    LSEWeatherTypedSleet,
    /**
     * 阵雪
     */
    LSEWeatherTypedSnowShower,
    /**
     * 小雪
     */
    LSEWeatherTypedLightSnow,
    /**
     * 中雪
     */
    LSEWeatherTypedModerateSnow,
    /**
     * 大雪
     */
    LSEWeatherTypedBigSnow,
    /**
     * 暴雪
     */
    LSEWeatherTypedBlizzard,
    /**
     * 浮尘
     */
    LSEWeatherTypedFlyAsh,
    /**
     * 扬尘
     */
    LSEWeatherTypedDust,
    /**
     * 沙尘暴
     */
    LSEWeatherTypedStorms,
    /**
     * 强沙尘暴
     */
    LSEWeatherTypedStrongStorms,
    /**
     * 雾
     */
    LSEWeatherTypedFog,
    /**
     * 霾
     */
    LSEWeatherTypedHaze,
    /**
     * 风
     */
    LSEWeatherTypedWind,
    /**
     * 大风
     */
    LSEWeatherTypedBigWind,
    /**
     * 飓风
     */
    LSEWeatherTypedHurricane,
    /**
     * 热带风暴
     */
    LSEWeatherTypedTropicalStorm,
    /**
     * 龙卷风
     */
    LSEWeatherTypedTornado,
    
};


@interface LSEFutureWeatherModel : NSObject

/**
 *  天气气象类型
 */
@property (nonatomic, assign) LSEWeatherType type;

/**
 *  温度范围1
 */
@property (nonatomic, assign) int temperatureOne;

/**
 *  温度范围2
 */
@property (nonatomic, assign) int temperatureTwo;

/**
 *  空气质量指数AQI
 */
@property (nonatomic, assign) int AQI;


/**
 pm25
 */
@property (nonatomic, assign) int pm25;

@end


@interface LSEWeatherData : NSObject


/// 天气更新的时间utc(天气获取时刻的时间，不是手机系统的时间)
@property (nonatomic, assign) long long updateTime;
@property (nonatomic, strong) NSString *where;
/// 查看已经添加的未来天气信息对象
@property (nonatomic, strong) NSArray<LSEFutureWeatherModel*> *weatherModels;

@end


