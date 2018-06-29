/****************************************************************************
Copyright (c) 2015-2017 Chukong Technologies Inc.
 
http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
package org.cocos2dx.cpp;

import org.cocos2dx.lib.Cocos2dxActivity;
import android.os.Bundle;
import android.util.Log;

public class AppActivity extends Cocos2dxActivity {

    private static final String TAG = "VdopiaActivity";
   // static InterstitialAd mInterstitialAd;
    static RewardInterstitialAd mRewardAd;

    @Override
    protected void onCreate(final Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        //InterstitialAd.app = this;
        RewardInterstitialAd.app = this;
    }

    /*public static void loadInterstitialAd(String apiKey) {
        Log.v(TAG, "loadInterstitialAd from JNI");
        mInterstitialAd = new InterstitialAd(apiKey);
        mInterstitialAd.loadAd();
    }

    public static void showInterstitialAd() {
        Log.v(TAG, "showInterstitialAd from JNI");
        if (mInterstitialAd != null) {
            mInterstitialAd.show();
        }
    }*/

    public static void loadRewardedAd(String apiKey) {
        Log.v(TAG, "loadRewardAd from JNI");
        mRewardAd = new RewardInterstitialAd(apiKey);
        mRewardAd.loadAd();

    }

    public static void showRewardedAd(String secret, String userId, String rewardName, String rewardAmount) {
        Log.v(TAG, "showRewardAd from JNI");
        if (mRewardAd != null) {
            mRewardAd.show(secret, userId, rewardName, rewardAmount);
        }
    }

    public static void setAdUserParams(String age, String birthdate, String gender, String status, String sFive, String sSix, String sSeven, String sEight) {
        if (mRewardAd != null) {
            mRewardAd.setAduserParameteres(age, birthdate, gender, status, sFive, sSix, sSeven, sEight);
        }
       /* if (mInterstitialAd != null) {
            mInterstitialAd.setAduserParameteres(age, birthdate, gender, status, sFive, sSix, sSeven, sEight);
        }*/
    }

    public static void setAdAppParams(String appBundle, String appDomain, String appName, String appStoreUrl, String appCategory, String publisherDomain) {
        if (mRewardAd != null) {
            mRewardAd.setAdappParameteres(appBundle, appDomain, appName, appStoreUrl, appCategory, publisherDomain);
        }
        /*if (mInterstitialAd != null) {
            mInterstitialAd.setAdappParameteres(appBundle, appDomain, appName, appStoreUrl, appCategory, publisherDomain);

        }*/
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        /*if (mInterstitialAd != null) {
            mInterstitialAd.destroy();
        }*/
        if (mRewardAd != null) {
            mRewardAd.destroy();
        }
    }
}
