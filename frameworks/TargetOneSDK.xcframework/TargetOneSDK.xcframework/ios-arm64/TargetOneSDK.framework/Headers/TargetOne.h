//
//  TargetOne.h
//  TargetOneSDKDemo
//
//  Created by Senthilkumar R on 29/03/18.
//  Copyright © 2018 Manthan Systems. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <CoreLocation/CoreLocation.h>
#import <TargetOneSDK/T1Config.h>
#import <TargetOneSDK/T1CustomerProfile.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 100000
#define XC8_AVAILABLE 1
#import <UserNotifications/UserNotifications.h>
#endif

typedef NS_ENUM(NSUInteger, T1_LOG_LEVEL) {
    T1_LL_NONE, T1_LL_FATAL, T1_LL_ERROR, T1_LL_WARN, T1_LL_INFO, T1_LL_DEBUG, T1_LL_VERBOSE
};

@protocol TargetOneNotificationDelegate <NSObject>
@optional
- (void)handleNotification:(NSDictionary*)userinfo;
@optional
- (void) didReceiveDeviceToken:(NSString*)deviceToken;
@optional
- (void)didRegisterForRemoteNotifications:(UIApplication*)app deviceToken:(NSData*)inDeviceToken;

@end

@interface TargetOne : NSObject <UNUserNotificationCenterDelegate, CLLocationManagerDelegate>


@property (nonatomic, weak) id <TargetOneNotificationDelegate> delegate;
@property (nonatomic) Boolean devEnabled;
@property (nonatomic, strong) NSString *devBaseUrl;
@property (nonatomic, strong) NSString *prodBaseUrl;
@property (nonatomic, strong) NSString *tenentHash;
+ (instancetype) sharedInstance;
+ (void)setLogLevel:(T1_LOG_LEVEL)logLevel;
+ (Boolean) autoIntegarteStatus;
+ (void) handleDidFailRegisterForRemoteNotification:(NSError*)err;
+ (void) t1_Log:(T1_LOG_LEVEL)logLevel message:(NSString*) message;

- (void) sendClickStream: (NSString *) eventName withProps:(NSDictionary*) properties;
- (void) setCustomerProfile : (T1CustomerProfile*) profile;
- (void) sendRealtime: (NSString *) eventName apiName: (NSString *) apiName withProps:(NSDictionary*) properties onSuccess:(void (^)(NSDictionary*))successBlock onFailure:(void (^)(NSError *))failureBlock;
- (void) initialize : (T1Config *) config;
- (void) setEventHeader: (NSDictionary*) properties;
- (void) notificationOpen:(NSDictionary * )userInfo;
- (void) handleNotification:(NSDictionary*)userinfo;
- (Boolean) handleRemoteNotification:(NSDictionary*) userinfo;
- (void) registerDeviceToken:(NSData*) deviceToken;
-(void) presentModalView:(NSDictionary * )userInfo;

- (Boolean) handleRemoteNotification:(NSDictionary*) userinfo withCompletionHandler:(void (^)(UNNotificationPresentationOptions options))completionHandler API_AVAILABLE(ios(10.0));

- (void)setUserNotificationCategories:(NSSet<UNNotificationCategory*>*)categories API_AVAILABLE(ios(10.0));


@end
