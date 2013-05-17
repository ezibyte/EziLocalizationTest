//
//  IOSLocalizationTest.mm
//  EziLocalizationTest
//
//  Created by Paras Mendiratta on 17/05/13.
//
//

#include "IOSLocalizationTest.h"

@implementation IOSLocalizationTest

#include <string.h>
#include <cstring>
#include <iostream>

static IOSLocalizationTest* testManager;

@synthesize mUserCallback;

void LocalizationWrapper::getUserDetails(LocalizationWrapper::UserDetailCallback callback)
{
    NSLog(@"Inside IOS");
    
    [[IOSLocalizationTest sharedTest] setMUserCallback:callback];
    [[IOSLocalizationTest sharedTest] getUserDetails];
}

+(IOSLocalizationTest*) sharedTest
{
    if (testManager == nil)
    {
        testManager = [[IOSLocalizationTest alloc] init];
    }
    
    return testManager;
}

-(void)getUserDetails
{
    // We have write our test here.
    
    std::wstring testString = L"dßdýdうd⬅";
    
    if (mUserCallback)
    {
        (mUserCallback)(testString);
    }
}

@end