//
//  IOSLocalizationTest.h
//  EziLocalizationTest
//
//  Created by Paras Mendiratta on 17/05/13.
//
//

#ifndef __EziLocalizationTest__IOSLocalizationTest__
#define __EziLocalizationTest__IOSLocalizationTest__

#include <iostream>

#include "CBridge.h"

@interface IOSLocalizationTest : NSObject

+(IOSLocalizationTest*) sharedTest;

@property (assign) LocalizationWrapper::UserDetailCallback mUserCallback;

-(void)getUserDetails;

@end

#endif /* defined(__EziLocalizationTest__IOSLocalizationTest__) */
