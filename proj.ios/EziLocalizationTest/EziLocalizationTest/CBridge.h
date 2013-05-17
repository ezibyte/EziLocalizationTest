//
//  CBridge.h
//  EziLocalizationTest
//
//  Created by Paras Mendiratta on 17/05/13.
//
//

#ifndef EziLocalizationTest_CBridge_h
#define EziLocalizationTest_CBridge_h

namespace LocalizationWrapper
{

    typedef void (*UserDetailCallback)(std::wstring);
    void getUserDetails(UserDetailCallback callback);

};
    
#endif
