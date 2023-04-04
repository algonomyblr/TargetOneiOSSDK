//
//  T1Config.h
//  TargetOneSDK
//
//  Created by Senthilkumar R on 20/04/18.
//  Copyright © 2018 Manthan Systems. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface T1Config : NSObject

@property (nonatomic, assign) Boolean enableNotification;
@property (nonatomic, assign) Boolean enableLocation;
@property (nonatomic, assign) Boolean enableDevBuild;

@property (nonatomic, strong) NSArray *arrBlockInApp;

@property (nonatomic, assign) Boolean disableAutoIntegrate;

@property (nonatomic, strong) NSString *devBaseUrl;
@property (nonatomic, strong) NSString *prodBaseUrl;

@property (nonatomic, strong) NSString *tenantHash;

@end
