#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "LSAccountAuthorizeRequest.h"
#import "LSAccountAuthorizeResponse.h"
#import "LSAuthAccountService.h"
#import "LSAuthorizationDelegate.h"
#import "LSAuthorizationService.h"
#import "LSAuthorizeRequest.h"
#import "LSAuthorizeResponse.h"
#import "LSKeyChainAccessUtils.h"
#import "LSProtocolPathUtils.h"
#import "LSReportTimezoneRequest.h"
#import "LSAuthorization.h"

FOUNDATION_EXPORT double LSAuthorizationVersionNumber;
FOUNDATION_EXPORT const unsigned char LSAuthorizationVersionString[];

