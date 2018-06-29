#include <2d/CCFontAtlasCache.h>
#include <platform/android/jni/JniHelper.h>
#include <base/CCDirector.h>
#include "HelloWorldScene.h"

#define LOG_TAG    "VdopiaAdsJNI"
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)

#define CLASS_NAME "org/cocos2dx/cpp/AppActivity"

using namespace cocos2d;

#ifdef __cplusplus
extern "C" {
#endif

// Reward Ad methods
void loadRewardedAd(const char *param) {

    JniMethodInfo methodInfo;

    if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "loadRewardedAd",
                                        "(Ljava/lang/String;)V")) {
        LOGD("Failed to find static method of reward  ad load");
        return;
    }

    jstring jgameId = methodInfo.env->NewStringUTF(param);

    methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jgameId);


}

void showRewardedAd(const char *secretKey, const char *userId, const char *rewardname,
                    const char *amount) {
    JniMethodInfo methodInfo;
    if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "showRewardedAd",
                                        "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V")) {
        LOGD("Failed to find static method of reward ad show");
        return;
    }

    jstring jsecretKey = methodInfo.env->NewStringUTF(secretKey);

    jstring juserId = methodInfo.env->NewStringUTF(userId);

    jstring jrewardName = methodInfo.env->NewStringUTF(rewardname);

    jstring jamount = methodInfo.env->NewStringUTF(amount);
    methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jsecretKey,
                                         juserId, jrewardName, jamount);
}
JNIEXPORT void JNICALL
Java_org_cocos2dx_cpp_RewardInterstitialAd_adLoadedRewarded(JNIEnv *env, jobject jobj) {

    auto scene = Director::getInstance()->getRunningScene();

    if (typeid(*scene) == typeid(HelloWorld)) {
        LOGD("ad Loaded Rewarded");
        static_cast<HelloWorld *>(scene)->rewardAdLoaded();
    } else {
        LOGD("gameScene is still NULL");
    }

}

JNIEXPORT void JNICALL
Java_org_cocos2dx_cpp_RewardInterstitialAd_adFailedRewarded(JNIEnv *env, jobject jobj) {

    auto scene = Director::getInstance()->getRunningScene();

    if (typeid(*scene) == typeid(HelloWorld)) {
        static_cast<HelloWorld *>(scene)->rewardAdFailed();
    } else {
        LOGD("gameScene is still NULL");
    }
}

JNIEXPORT void JNICALL
Java_org_cocos2dx_cpp_RewardInterstitialAd_adDismissedRewarded(JNIEnv *env, jobject jobj) {

    auto scene = Director::getInstance()->getRunningScene();

    if (typeid(*scene) == typeid(HelloWorld)) {
        static_cast<HelloWorld *>(scene)->rewardAdDismissed();
    } else {
        LOGD("gameScene is still NULL");
    }

}
JNIEXPORT void JNICALL
Java_org_cocos2dx_cpp_RewardInterstitialAd_adCompletedRewarded(JNIEnv *env, jobject jobj) {

    auto scene = Director::getInstance()->getRunningScene();

    if (typeid(*scene) == typeid(HelloWorld)) {
        static_cast<HelloWorld *>(scene)->rewardAdCompleted();
    } else {
        LOGD("gameScene is still NULL");
    }

}
JNIEXPORT void JNICALL
Java_org_cocos2dx_cpp_RewardInterstitialAd_adShownErrorRewarded(JNIEnv *env, jobject jobj) {

    auto scene = Director::getInstance()->getRunningScene();

    if (typeid(*scene) == typeid(HelloWorld)) {
        static_cast<HelloWorld *>(scene)->rewardAdShownError();
    } else {
        LOGD("gameScene is still NULL");
    }

}

JNIEXPORT void JNICALL
Java_org_cocos2dx_cpp_RewardInterstitialAd_adShownRewarded(JNIEnv *env, jobject jobj) {
    auto scene = Director::getInstance()->getRunningScene();

    if (typeid(*scene) == typeid(HelloWorld)) {
        static_cast<HelloWorld *>(scene)->rewardAdShown();
    } else {
        LOGD("gameScene is still NULL");
    }
}
void setAdRequestUserParams(const char *age, const char *birthdate, const char *gender,
                            const char *mstatus, const char *ethinicty, const char *string6,
                            const char *string7, const char *string8) {
    JniMethodInfo methodInfo;

    if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "setAdUserParams",
                                        "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V")) {
        LOGD("Failed to find static method of interstitial ad load");
        return;
    }

    jstring jage = methodInfo.env->NewStringUTF(age);
    jstring jbirthDate = methodInfo.env->NewStringUTF(birthdate);
    jstring jgender = methodInfo.env->NewStringUTF(gender);
    jstring jstatus = methodInfo.env->NewStringUTF(mstatus);
    jstring jethinicty = methodInfo.env->NewStringUTF(ethinicty);
    jstring jstring6 = methodInfo.env->NewStringUTF(string6);
    jstring jstring7 = methodInfo.env->NewStringUTF(string7);
    jstring jstring8 = methodInfo.env->NewStringUTF(string8);


    methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jage, jbirthDate,
                                         jgender, jstatus, jethinicty, jstring6, jstring7,
                                         jstring8);
}

void setAdRequestAppParams(const char *appBundle, const char *appDomain, const char *appName,
                           const char *appStoreUrl, const char *appCategory,
                           const char *publisherDomain) {
    JniMethodInfo methodInfo;

    if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "loadInterstitialAd",
                                        "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V")) {
        LOGD("Failed to find static method of interstitial ad load");
        return;
    }

    jstring jappBundle = methodInfo.env->NewStringUTF(appBundle);
    jstring jappDomain = methodInfo.env->NewStringUTF(appDomain);
    jstring jappName = methodInfo.env->NewStringUTF(appName);
    jstring jappStoreUrl = methodInfo.env->NewStringUTF(appStoreUrl);
    jstring jappCategory = methodInfo.env->NewStringUTF(appCategory);
    jstring jpublisherDomain = methodInfo.env->NewStringUTF(publisherDomain);

    methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jappBundle,
                                         jappDomain, jappName, jappStoreUrl, jappCategory,
                                         jpublisherDomain);
}
#ifdef __cplusplus
}
#endif