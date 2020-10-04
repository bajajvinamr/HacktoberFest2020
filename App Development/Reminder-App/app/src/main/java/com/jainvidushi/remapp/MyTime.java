package com.jainvidushi.remapp;

/**
 * Created by Vidushi on 03-07-2017.
 */
import java.text.ParseException;
import java.util.*;
import java.lang.*;
import java.io.*;
import java.text.SimpleDateFormat;
import java.util.Date;


public class MyTime
{
    SimpleDateFormat dateFormat = new SimpleDateFormat("dd-MM-yyyy HH:mm");
    public long date_to_timestamp(String str_date)throws ParseException
    {
        Date mydate = dateFormat.parse(str_date);
        long time = mydate.getTime();
        return time;
    }
    public String timestamp_to_date(long time)throws ParseException
    {
        String string3  = dateFormat.format(new Date(time));
        return string3;
    }
    public String current_date()throws ParseException
    {
        String string2  = dateFormat.format(new Date());
        return string2;

    }
}

