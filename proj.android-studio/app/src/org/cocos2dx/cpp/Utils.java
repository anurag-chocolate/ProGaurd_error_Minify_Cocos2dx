package org.cocos2dx.cpp;


import android.annotation.SuppressLint;
import android.util.Log;

import com.vdopia.ads.lw.LVDOAdRequest;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Utils {
    private final static String MALE = "m";
    private final static String FEMALE = "f";
    private final static String SINGLE = "single";
    private final static String MARRIED = "married";
    private static final String TAG = "Utils";

    static Date getBirthDate(String birthdate) {
        @SuppressLint("SimpleDateFormat") SimpleDateFormat sdf = new SimpleDateFormat("dd-mm-yyyy");
        Date date = null;
        try {
            date = sdf.parse(birthdate);
        } catch (ParseException e) {
            Log.e(TAG, "ParseException : " + e.getMessage());
        }
        return date;
    }

    static LVDOAdRequest.LVDOMartialStatus getMartitalStatus(String status) {
        LVDOAdRequest.LVDOMartialStatus lvdoMartialStatus;
        switch (status) {
            case SINGLE:
                lvdoMartialStatus = LVDOAdRequest.LVDOMartialStatus.Single;
                break;
            case MARRIED:
                lvdoMartialStatus = LVDOAdRequest.LVDOMartialStatus.Married;
                break;
            default:
                lvdoMartialStatus = LVDOAdRequest.LVDOMartialStatus.Unknown;
                break;
        }
        return lvdoMartialStatus;
    }

    static LVDOAdRequest.LVDOGender getGender(String gender) {
        LVDOAdRequest.LVDOGender lvdoGender;
        switch (gender) {
            case MALE:
                lvdoGender = LVDOAdRequest.LVDOGender.MALE;
                break;
            case FEMALE:
                lvdoGender = LVDOAdRequest.LVDOGender.FEMALE;
                break;
            default:
                lvdoGender = LVDOAdRequest.LVDOGender.UNKNOWN;
                break;
        }
        return lvdoGender;
    }
}
