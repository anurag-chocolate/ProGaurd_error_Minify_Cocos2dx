#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#define buttonTextFontSize 12
#define buttonHeight 30
#define buttonWidth 120
#define selecedColor Color3B(199,140,295)
#define normalTextColor Color3B(100,50,300)
#define ShowInterestialAdButtonTag 02
#define ShowRewardAdButtonTag 04
#define LoadInterestialAdButtonTag 01
#define LoadRewardAdButtonTag 03
#define COCOS2D_DEBUG 1



USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


    auto bg = cocos2d::LayerColor::create(Color4B(356, 153, 55, 205));
    this->addChild(bg);


//Load ad method
    setAdRequestUserParams("23", "23/11/1990", "m", "single", "Asian", "999",
                           "123123", "321321");
    setAdRequestAppParams("Vdopia", "Vdopia", "Vdopia-demo.com", "vdopia.com", "123.com",
                          "Movie");
    CCLOG("loadRewardAdFunction");
    //const char *apiKey = "0DqXTL";
    const char *apiKey = "r7BmFo";
    loadRewardedAd(apiKey);

    return true;
}


/*void HelloWorld::interstitialAdLoaded() {
    CCLOG("%s","AD loaded");
}

void HelloWorld::interstitialAdShown() {
    CCLOG("%s","AD shown");
}

void HelloWorld::interstitialAdFailed() {

    CCLOG("%s","AD Failed");

}

void HelloWorld::interstitialAdDismissed() {

}

void HelloWorld::interstitialAdClicked() {

}*/


void HelloWorld::rewardAdLoaded() {
    //showRewardedAd("7rZyMDqEguoDJ12o", "Chocolate1", "coin", "30");

    float xPosition = 180;
    float buttonYPosition =180;
    //origin.y + visibleSize.height - headerImage->getContentSize().height - 50;

    auto loadInterstitialAdButtonBg = cocos2d::LayerColor::create(Color4B(452, 23, 291, 55));
    loadInterstitialAdButtonBg->setPosition(Vec2(xPosition, buttonYPosition));
    loadInterstitialAdButtonBg->setContentSize(cocos2d::Size(buttonWidth, buttonHeight));
    this->addChild(loadInterstitialAdButtonBg,1, LoadInterestialAdButtonTag);

    auto loadInterstitialAdButton = cocos2d::ui::Button::create();
    loadInterstitialAdButton->setPosition(Vec2(60, 13));
    loadInterstitialAdButton->setScale9Enabled(true);
    loadInterstitialAdButton->setContentSize(cocos2d::Size(buttonWidth, buttonHeight));
    loadInterstitialAdButton->setTitleFontSize(buttonTextFontSize);
    loadInterstitialAdButton->setTitleText("Click to see the ad");
    loadInterstitialAdButton->setTitleColor(normalTextColor);
    loadInterstitialAdButton->setPressedActionEnabled(true);
    loadInterstitialAdButton->addTouchEventListener(
            [](Ref *pSender, cocos2d::ui::Widget::TouchEventType type) {
                if (type == cocos2d::ui::Widget::TouchEventType::ENDED) {

                    showRewardedAd("7rZyMDqEguoDJ12o", "Chocolate1", "coin", "30");


                    CCLOG("%s","Ad Show method called");
                }
            });

    loadInterstitialAdButtonBg->addChild(loadInterstitialAdButton, 1, LoadInterestialAdButtonTag);
     CCLOG("rewardAdLoaded");

}

void HelloWorld::rewardAdFailed() {
    CCLOG("rewardAdFailed");

}

void HelloWorld::rewardAdCompleted() {
    CCLOG("rewardAdCompleted");

}

void HelloWorld::rewardAdShown() {
    CCLOG("rewardAdShown");;
}

void HelloWorld::rewardAdShownError() {
    CCLOG("rewardAdShownError");

}

void HelloWorld::rewardAdDismissed() {
    CCLOG("rewardAdDismissed");


}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
