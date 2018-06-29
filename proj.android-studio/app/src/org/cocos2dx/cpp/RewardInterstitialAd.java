package org.cocos2dx.cpp;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.os.Build;
import android.os.Handler;
import android.os.Looper;
import android.util.Log;
import android.widget.Toast;

import com.vdopia.ads.lw.LVDOAdRequest;
import com.vdopia.ads.lw.LVDOConstants;
import com.vdopia.ads.lw.LVDORewardedAd;
import com.vdopia.ads.lw.RewardedAdListener;

/**
 *
 */

class RewardInterstitialAd implements RewardedAdListener {
    private static final String TAG = "RewardInterstitialAd";
    private String mApikey;
    private LVDORewardedAd mRewardedAd;
    public static Activity app;
    LVDOAdRequest adRequest = new LVDOAdRequest(app);
    private String mRewardAmount;
    public String mRewardName;


    static native void adLoadedRewarded();

    static native void adFailedRewarded();

    static native void adDismissedRewarded();

    static native void adCompletedRewarded();

    static native void adShownErrorRewarded();

    static native void adShownRewarded();


    public RewardInterstitialAd(String apiKey) {
        mApikey = apiKey;
    }


    public void loadAd() {
        mRewardedAd = LVDORewardedAd.getInstance();
        mRewardedAd.fetchRewardAd(app, mApikey, getAdrequest(), this);
    }

    private LVDOAdRequest getAdrequest() {
        return adRequest;
    }


    public void show(final String secret, final String userId, final String rewardName, final String rewardAmount) {

        mRewardAmount = rewardAmount;
        mRewardName = rewardName;
        if (mRewardedAd != null) {
            mRewardedAd.setAdRequest(getAdrequest());
            mRewardedAd.setRewardAdListener(RewardInterstitialAd.this);
            mRewardedAd.showRewardAd(secret, userId, rewardName, rewardAmount);
        }
        Handler handler = new Handler(Looper.getMainLooper());
        handler.post(new Runnable() {
            @Override
            public void run() {
                AlertDialog.Builder builder;
                if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.LOLLIPOP) {
                    builder = new AlertDialog.Builder(app, android.R.style.Theme_DeviceDefault_Dialog);
                } else {
                    builder = new AlertDialog.Builder(app);
                }
                builder.setTitle("Earn 30 Virtual Coins")
                        .setMessage("Watch a Video and Earn " + rewardAmount + " Virtual " + rewardName + "s!")
                        .setPositiveButton("Watch Video", new DialogInterface.OnClickListener() {
                            public void onClick(DialogInterface dialog, int which) {
                                if (mRewardedAd != null) {
                                    mRewardedAd.setAdRequest(getAdrequest());
                                    mRewardedAd.setRewardAdListener(RewardInterstitialAd.this);
                                    mRewardedAd.showRewardAd(secret, userId, rewardName, rewardAmount);
                                }
                            }
                        })
                        .setNegativeButton("No Thanks", new DialogInterface.OnClickListener() {
                            public void onClick(DialogInterface dialog, int which) {
                                dialog.dismiss();
                            }
                        })
                        .setIcon(android.R.drawable.ic_dialog_alert)
                        .show();
            }
        });

    }

    @Override
    public void onRewardedVideoLoaded(LVDORewardedAd lvdoRewardedAd) {
        Log.v(TAG, "onRewardedVideoLoaded");
        adLoadedRewarded();
    }

    @Override
    public void onRewardedVideoFailed(LVDORewardedAd lvdoRewardedAd, LVDOConstants.LVDOErrorCode lvdoErrorCode) {
        Log.v(TAG, "onRewardedVideoFailed with error.." + lvdoErrorCode);
        adFailedRewarded();
    }

    @Override
    public void onRewardedVideoShown(LVDORewardedAd lvdoRewardedAd) {
        Log.v(TAG, "onRewardedVideoShown");
        adShownRewarded();
    }

    @Override
    public void onRewardedVideoShownError(LVDORewardedAd lvdoRewardedAd, LVDOConstants.LVDOErrorCode lvdoErrorCode) {
        Log.v(TAG, "onRewardedVideoShownError");
        adShownErrorRewarded();
    }

    @Override
    public void onRewardedVideoDismissed(LVDORewardedAd lvdoRewardedAd) {
        Log.v(TAG, "onRewardedVideoDismissed");
        adDismissedRewarded();
    }

    @Override
    public void onRewardedVideoCompleted(LVDORewardedAd lvdoRewardedAd) {
        Log.v(TAG, "onRewardedVideoCompleted");
        new Handler(Looper.getMainLooper()).post(new Runnable() {

            @Override
            public void run() {
                Toast.makeText(app, "Thanks! You have earned " + mRewardAmount + "virtual " + mRewardName + "s.", Toast.LENGTH_SHORT).show();
            }
        });

        adCompletedRewarded();
    }


    void destroy() {
        if (mRewardedAd != null) {
            mRewardedAd.destroyView();
        }
    }

    public void setAduserParameteres(String age, String birthdate, String gender, String status, String ethinicity, String sSix, String sSeven, String sEight) {
        adRequest.setEthnicity(ethinicity);
        adRequest.setAge(age);
        adRequest.setGender(Utils.getGender(gender));
        adRequest.setBirthday(Utils.getBirthDate(birthdate));
        adRequest.setMaritalStatus(Utils.getMartitalStatus(status));
        adRequest.setDmaCode(sSix);
        adRequest.setPostalCode(sSeven);
        adRequest.setCurrPostal(sEight);
    }

    public void setAdappParameteres(String appBundle, String appDomain, String appName, String appStoreUrl, String appCategory, String publisherDomain) {
        adRequest.setAppBundle(appBundle);
        adRequest.setAppDomain(appDomain);
        adRequest.setAppName(appName);
        adRequest.setAppStoreUrl(appStoreUrl);
        adRequest.setCategory(appCategory);
        adRequest.setPublisherDomain(publisherDomain);
    }
}
