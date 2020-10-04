package com.jainvidushi.remapp;

/**
 * Created by Vidushi on 06-07-2017.
 */
import android.content.Context;
import android.widget.Toast;

public class Message {
    public static void message(Context context, String message) {
        Toast.makeText(context, message, Toast.LENGTH_LONG).show();
    }
}

