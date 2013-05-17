#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

#include "CBridge.h"

using namespace cocos2d;
using namespace CocosDenshion;

static HelloWorld* sharedHelloWorld;

void internalUserDetailCallback(std::wstring data)
{
    CCLOG("I am in internalUserDetailCallback");
    
    HelloWorld::sharedObject()->updateTestLabel(data);
}

void internalFriendDetailCallback(std::string data)
{
    CCLOG("I am in internalFriendDetailCallback");
    
    HelloWorld::sharedObject()->updateFriendLabel(data);
}


CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();
    sharedHelloWorld = layer;

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);

    
    CCMenuItemImage *pFriendButton = CCMenuItemImage::create(
                                                          "Icon.png",
                                                          "Icon.png",
                                                          this,
                                                          menu_selector(HelloWorld::requestFriendDetails) );
    pFriendButton->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width/2, 20) );
    
    // create menu, it's an autorelease object
    CCMenu* pFriendMenu = CCMenu::create(pFriendButton, NULL);
    pFriendMenu->setPosition( CCPointZero );
    this->addChild(pFriendMenu, 1);

    


    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    mTestLabel = CCLabelTTF::create("Test Data", "Thonburi", 34);
    
    mFriendLabel = CCLabelTTF::create("Friend Test Data", "Thonburi", 34);
    

    mBMFriendLabel = CCLabelBMFont::create("Test BM Friend Label", "bmftest.fnt");
    mBMTestLabel = CCLabelBMFont::create("Test BM Label", "bmftest.fnt");

    // ask director the window size
    CCSize size = CCDirector::sharedDirector()->getWinSize();

    // position the label on the center of the screen
    mTestLabel->setPosition( ccp(size.width * 0.75, size.height - 20) );
    mFriendLabel->setPosition( ccp(size.width * 0.75, size.height/2) );
    
    mBMTestLabel->setPosition(ccp(size.width * 0.25, size.height - 20));
    mBMFriendLabel->setPosition( ccp(size.width * 0.25, size.height/2) );
    // add the label as a child to this layer
    this->addChild(mTestLabel, 1);
    this->addChild(mFriendLabel, 1);
    
    this->addChild(mBMTestLabel, 1);
    this->addChild(mBMFriendLabel, 1);
    
    return true;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    this->requestForUserDetails();
    
    //CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    //exit(0);
#endif
}

HelloWorld*  HelloWorld::sharedObject()
{
    if (sharedHelloWorld == NULL)
    {
        return NULL;
    }
    return sharedHelloWorld;
}


void HelloWorld::requestForUserDetails()
{
    LocalizationWrapper::getUserDetails(internalUserDetailCallback);
}


void HelloWorld::requestFriendDetails()
{
    LocalizationWrapper::getFriendDetails(internalFriendDetailCallback);
}

void HelloWorld::updateTestLabel(std::wstring dataWString)
{
    // Here we have to update the test label.
    
    std::string resultData = "";
    resultData.assign(dataWString.begin(), dataWString.end());
    
    if (this->mTestLabel)
    {
        this->mTestLabel->setString(resultData.c_str());
    }
    else
    {
        CCLOG("mTest Label is NULL");
    }
    
    if (mBMTestLabel)
    {
        mBMTestLabel->setString(resultData.c_str());
    }
    
    
    
    CCLOG("I am in updateTestLabel");
    
}

void HelloWorld::updateFriendLabel(std::string dataString)
{
    CCLOG("Updating Friend's Label");
    if (mFriendLabel)
    {
        this->mFriendLabel->setString(dataString.c_str());
    }
    
    if (mBMFriendLabel)
    {
        mBMFriendLabel->setString(dataString.c_str());
    }
}