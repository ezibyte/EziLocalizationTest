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
    
    //std::wstring testString = L"dßdýdうd⬅";
    NSString* specialString = [NSString stringWithFormat:@"dßdýdうd⬅", nil];
    
    const char *cString = [specialString cStringUsingEncoding:NSUTF8StringEncoding];
    char * oldlocaleinfo = setlocale(LC_CTYPE, "");
    char * localeinfo = setlocale(LC_CTYPE, "C");//UTF-8
    
    printf ("Locale is: %s\n", localeinfo );
    wchar_t *outStr = NULL;
    size_t size = mbstowcs(NULL, cString, 0);
    outStr = new wchar_t[size + 1];
    if (outStr) {
        memset(outStr, 0, size * sizeof(wchar_t));
        size_t ret = mbstowcs(outStr, cString, size+1);
        if (ret == -1) {
            delete[] outStr;
            outStr = NULL;
        }
    }
    localeinfo = setlocale(LC_CTYPE, oldlocaleinfo);
    std::wstring testString(outStr);
    if (mUserCallback)
    {
        (mUserCallback)(testString);
    }
}

@end