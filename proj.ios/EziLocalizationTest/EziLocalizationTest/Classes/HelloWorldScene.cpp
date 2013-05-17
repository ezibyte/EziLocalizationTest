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

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    mTestLabel = CCLabelTTF::create("dßdýdうd⬅", "Thonburi", 34);

    // ask director the window size
    CCSize size = CCDirector::sharedDirector()->getWinSize();

    // position the label on the center of the screen
    mTestLabel->setPosition( ccp(size.width / 2, size.height - 20) );

    // add the label as a child to this layer
    this->addChild(mTestLabel, 1);

    this->requestForUserDetails();
    
    return true;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
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


void HelloWorld::updateTestLabel(std::wstring dataWString)
{
    // Here we have to update the test label.
    CCLOG("I am in updateTestLabel");
}