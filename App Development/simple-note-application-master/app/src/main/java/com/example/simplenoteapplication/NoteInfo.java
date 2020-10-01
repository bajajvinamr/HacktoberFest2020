package com.example.simplenoteapplication;

import android.os.Build;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.annotation.RequiresApi;

import java.io.Serializable;

public class NoteInfo implements Serializable {
    String _Title;
    String _Content;
    String _Date="";
    String _Tag;
    @RequiresApi(api = Build.VERSION_CODES.O)
    public NoteInfo(String aTitle, String aContent,String aTag){
        this._Title = aTitle;
        this._Content = aContent;
        this._Tag = aTag;
    }

    public NoteInfo(String aTitle, String aContent,String aTag,String aDate)
    {
        this._Title = aTitle;
        this._Content = aContent;
        this._Tag = aTag;
        this._Date = aDate;
    }



    public String get_Content() {
        return _Content;
    }
    public String get_Title() {
        return _Title;
    }
    public String get_Tag() {
        return _Tag;
    }

    public void set_Content(String _Content) {
        this._Content = _Content;
    }
    public void set_Title(String _Title) {
        this._Title = _Title;
    }
    public void set_Date(String _Date) {this._Date = _Date;}
    public void set_Tag(String _Tag) {
        this._Tag = _Tag;
    }

    @Override
    public boolean equals(@Nullable Object obj) {
        return super.equals(obj);
    }

    @NonNull
    @Override
    public String toString() {
        return super.toString();
    }

    public String get_Date() {
        return _Date;
    }
}
