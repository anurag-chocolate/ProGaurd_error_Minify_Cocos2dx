#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#include <jni.h>
#include "platform/android/jni/JniHelper.h"
#include <jni.h>
#include "cocos2d.h"
#include "AppDelegate.h"

#endif

/* implement these functions with sdk api of different platforms */
#ifdef __cplusplus
extern "C" {
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
//   Interstitial Ad methods
void loadInterstitialAd(const char *parameter);
void showInterstitialAd();

//   Interstitial Ad listener methods
void adLoadedInterstitial();
void adFailedInterstitial();
void adDismissedInterstitial();
void adClickedInterstitial();
void adShownInterstitial();

//   Rewarded Ad methods
void loadRewardedAd(const char *parameter);
void showRewardedAd(const char *secretkey, const char *userId, const char *rewardname,
                    const char *amount);

//   Rewarded Ad listener methods
void adLoadedRewarded();
void adFailedRewarded();
void adDismissedRewarded();
void adCompletedRewarded();
void adShownErrorRewarded();
void adShownRewarded();

void setAdRequestUserParams(const char string[3], const char string1[11], const char string2[2],
                            const char string3[7], const char string4[6], const char string5[4],
                            const char string6[7], const char string7[7]);

void setAdRequestAppParams(const char string[7], const char string1[7], const char string2[16],
                           const char string3[11], const char string4[1], const char string5[6]);

#endif
#ifdef __cplusplus
}
#endif


