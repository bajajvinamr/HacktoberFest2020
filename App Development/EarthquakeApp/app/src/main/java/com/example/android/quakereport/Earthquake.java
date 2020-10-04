package com.example.android.quakereport;

public class Earthquake {
    private String mPlace;
    private double mMag;
    private long mDate;
    private String murl;
    public Earthquake(double eMag, String ePlace, long eDate,String eurl)
    {
        mPlace = ePlace;
        mMag = eMag;
        mDate = eDate;
        murl=eurl;
    }
    public String getPlace() {
        return mPlace;
    }
    public double getMagnitude() {
        return mMag;
    }
    public long getDate() {
        return mDate;
    }

    public String getUrl() {
        return murl;
    }
}

