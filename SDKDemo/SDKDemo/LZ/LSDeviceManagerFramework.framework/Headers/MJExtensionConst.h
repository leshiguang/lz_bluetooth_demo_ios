
#ifndef __MJExtensionConst__H__
#define __MJExtensionConst__H__

#import <Foundation/Foundation.h>

// 过期
#define MJExtensionDeprecated(instead) NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, instead)

// 构建错误
#define MJExtensionBuildError(clazz, msg) \
NSError *error = [NSError errorWithDomain:msg code:250 userInfo:nil]; \
[clazz setMj_error:error];

// 日志输出
#ifdef DEBUG
#define MJExtensionLog(...) NSLog(__VA_ARGS__)
#else
#define MJExtensionLog(...)
#endif

/**
 * 断言
 * @param condition   条件
 * @param returnValue 返回值
 */
#define MJExtensionAssertError(condition, returnValue, clazz, msg) \
[clazz setMj_error:nil]; \
if ((condition) == NO) { \
    MJExtensionBuildError(clazz, msg); \
    return returnValue;\
}

#define MJExtensionAssert2(condition, returnValue) \
if ((condition) == NO) return returnValue;

/**
 * 断言
 * @param condition   条件
 */
#define MJExtensionAssert(condition) MJExtensionAssert2(condition, )

/**
 * 断言
 * @param param         参数
 * @param returnValue   返回值
 */
#define MJExtensionAssertParamNotNil2(param, returnValue) \
MJExtensionAssert2((param) != nil, returnValue)

/**
 * 断言
 * @param param   参数
 */
#define MJExtensionAssertParamNotNil(param) MJExtensionAssertParamNotNil2(param, )

/**
 * 打印所有的属性
 */
#define MJLogAllIvars \
-(NSString *)description \
{ \
    return [self mj_keyValues].description; \
}
#define MJExtensionLogAllProperties MJLogAllIvars


#define MJPropertyTypeInt  @"i"
#define MJPropertyTypeShort  @"s"
#define MJPropertyTypeFloat  @"f"
#define MJPropertyTypeDouble  @"d"
#define MJPropertyTypeLong  @"l"
#define MJPropertyTypeLongLong  @"q"
#define MJPropertyTypeChar  @"c"
#define MJPropertyTypeBOOL1  @"c"
#define MJPropertyTypeBOOL2  @"b"
#define MJPropertyTypePointer  @"*"

#define MJPropertyTypeIvar  @"^{objc_ivar=}"
#define MJPropertyTypeMethod  @"^{objc_method=}"
#define MJPropertyTypeBlock  @"@?"
#define MJPropertyTypeClass  @"#"
#define MJPropertyTypeSEL  @":"
#define MJPropertyTypeId  @"@"


///**
// *  类型（属性类型）
// */
//extern NSString *const MJPropertyTypeInt;
//extern NSString *const ;
//extern NSString *const ;
//extern NSString *const ;
//extern NSString *const ;
//extern NSString *const ;
//extern NSString *const ;
//extern NSString *const ;
//extern NSString *const ;
//extern NSString *const ;
//
//extern NSString *const ;
//extern NSString *const ;
//extern NSString *const ;
//extern NSString *const ;
//extern NSString *const ;
//extern NSString *const ;

#endif