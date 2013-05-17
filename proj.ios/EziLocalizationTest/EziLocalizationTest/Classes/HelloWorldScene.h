#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::CCLayer
{
    
    void requestForUserDetails();
    void requestFriendDetails();
    
    cocos2d::CCLabelTTF* mTestLabel;
    cocos2d::CCLabelTTF* mFriendLabel;
    cocos2d::CCLabelBMFont* mBMTestLabel;
    cocos2d::CCLabelBMFont* mBMFriendLabel;
    
public:
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();

    // there's no 'id' in cpp, so we recommend to return the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);

    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(HelloWorld);
    
    static HelloWorld*  sharedObject();
    
    void updateTestLabel(std::wstring dataWString);
    void updateFriendLabel(std::string dataString);

};

#endif // __HELLOWORLD_SCENE_H__
