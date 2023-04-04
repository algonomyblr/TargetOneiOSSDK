# **TargetOne Mobile SDK**

### TargetOne-iOS-SDK

TargetOne Mobile SDK enables you to integrate app analytics. TargetOne Mobile SDK helps marketers increase user engagement in the following ways:

Allows you to track actions that users take in your app to analyze how people use your product.
Allows you to segment users based on their actions and run targeted campaigns to these segments.
Allows you to analyze each of your campaigns to understand their impact on user engagement and your business metrics.

**Core Concepts**

Before you begin programming using the Software Development Kit, we recommend that you familiarize yourself with the core concepts in TargetOne Mobile SDK:

• **Customers**: After you integrate the TargetOne Mobile SDK, a customer profile will be created for each person who launches your app or visits your website. The TargetOne customer profile includes a set of default fields, such as device and location. You can also extend the default customer profile data model by adding custom fields that are specific to your business.

• **Clickstream**: TargetOne Mobile SDK enables you to track what actions users perform in your app or website, such as viewing a product, listening to a song, or making a purchase. Events are associated with a customer profile.

• **Segments**: TargetOne enables you to create segments, which are a group of users whose behaviors, activities, or customer profile properties meet a set of criteria you have defined. When you have identified segments of interest, you can save them, target them with a campaign, and then analyze them over time.

• **Campaigns**: TargetOne campaigns enable you to communicate with your users at scale. TargetOne offers various communication channels to reach your users with the right message at the right time.

• **Reports**: TargetOne allows you to build reports to understand the impact of your campaigns on your users. You can use these reports to analyze your user engagement and take product decisions.


**SDK Integration**
        
        Objective-C
        
        T1Config *t1Config = [T1Config new];
        t1Config.enableNotification = YES;
        t1Config.enableLocation = YES;
        [TargetOne sharedInstance] initialize: t1Config];
        
        Swift
        
        TargetOne.setLogLevel(T1_LOG_LEVEL.LL_VERBOSE)
        let targetone = TargetOne.sharedInstance()
        let t1Config = T1Config()
        t1Config.enableNotification = true
        t1Config.enableLocation = true
        t1Config.enableDevBuild = false;
        targetone?.initialize(t1Config)
  
  **Set Customer Profile**
  
    Objective-C
    
    T1CustomerProfile *profile = [T1CustomerProfile new];
    profile.custCode = "cust001"; 
    profile.emailId = @"sample@mail.com"; 
    profile.mobileNumber=@"9876543210";
    [[TargetOne sharedInstance] setCustomerProfile:profile];
    
    Swift
    
    let profile = T1CustomerProfile();
    profile.custCode = "100"
    profile.mobileNumber="9876543210" 
    profile.emailId="sample@email.com" 
    TargetOne.sharedInstance().setCustomerProfile(profile)
   
         
        
