package com.londonappbrewery.destini;

public class StoryOption {
    private int mStoryText;
    private int mTopButtonText;
    private int mBottomButtonText;
    private int mOption1;
    private int mOption2;

    public StoryOption(int storyResourceID,int TopButtonResourceID,int BottomButtonResourceID,int option1ans, int option2ans){
        mStoryText=storyResourceID;
        mTopButtonText=TopButtonResourceID;
        mBottomButtonText=BottomButtonResourceID;
        mOption1=option1ans;
        mOption2=option2ans;

    }

    public int getStoryText() {
        return mStoryText;
    }

    public void setStoryText(int storyText) {
        mStoryText = storyText;
    }

    public int getTopButtonText() {
        return mTopButtonText;
    }

    public void setTopButtonText(int topButtonText) {
        mTopButtonText = topButtonText;
    }

    public int getBottomButtonText() {
        return mBottomButtonText;
    }

    public void setBottomButtonText(int bottomButtonText) {
        mBottomButtonText = bottomButtonText;
    }

    public int getOption1() {
        return mOption1;
    }

    public void setOption1(int option1) {
        mOption1 = option1;
    }

    public int getOption2() {
        return mOption2;
    }

    public void setOption2(int option2) {
        mOption2 = option2;
    }
}
