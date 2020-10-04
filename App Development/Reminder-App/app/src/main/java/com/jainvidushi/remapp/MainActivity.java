package com.jainvidushi.remapp;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
//import android.content.Context;
//import android.v.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import java.text.ParseException;
import android.os.Handler;

public class MainActivity extends AppCompatActivity {
    TextView Display;
    //Button MyMenu;
    dbmanag helper;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        //MyMenu= (Button) findViewById(R.id.mn);
        helper = new dbmanag(this);
        final Handler handler=new Handler();
        handler.postDelayed(new Runnable() {
            @Override
            public void run() {
                int count=helper.updatestatus();
                //Message.message(getApplicationContext(),"update row="+ Integer.toString(count));
                int a[] = new int[2];
                int b=0,c=0;
                a = helper.getrecordnos();
              //  Message.message(getApplicationContext(),Integer.toString(a[0]));
                if (a[0]<1)
                {
                    Message.message(getApplicationContext(),"You dont't have any active task");
                    Intent i = new Intent(getApplicationContext(), SetTaskActivity.class);
                    startActivity(i);
                }
                else if(a[0]>0){
                    try {
                        b = helper.getcurtask();
                        if (b>0)
                        {
                      //  Message.message(getApplicationContext(),"Current task  " + Integer.toString(b));
                        Intent i = new Intent(getApplicationContext(), RunTaskActivity.class);
                        startActivity(i);}
                        else {
                            c = helper.upcomingtask();
                            if (c > 0) {
                                Intent i = new Intent(getApplicationContext(), UpcomingTaskActivity.class);
                                startActivity(i);
                            } else {
                                Intent i = new Intent(getApplicationContext(), Menu_NavActivity.class);
                                startActivity(i);
                            }
                        }
                    } catch (Exception e) {Message.message(getApplicationContext(),""+e);
                    }
                }
            }

        },1500);
      //  MyMenu.setVisibility(View.VISIBLE);
    }
    //dbmanag obj=new dbmanag();
    //int a[] = new int[2];
    //public void next(View view) {
    //    a = helper.getrecordnos();
    //    Display.setText(a[0]+" " + a[1]);
    //}

  //  public void next(View view)
  //  {
  //      int a[] = new int[2];
  //      a = helper.getrecordnos();
  //      Message.message(this,Integer.toString(a[0]));
  //  }
    public void menu_nav(View view)
    {
        Intent i = new Intent(this, Menu_NavActivity.class);
        startActivity(i);
    }
}