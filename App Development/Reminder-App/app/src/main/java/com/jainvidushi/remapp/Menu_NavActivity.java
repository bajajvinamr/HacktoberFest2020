package com.jainvidushi.remapp;

import android.app.Activity;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.DigitalClock;

public class Menu_NavActivity extends AppCompatActivity {
    Button views,edits,deletes,ups,runs;
    dbmanag helper=new dbmanag(this);
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_menu__nav);
        views=(Button) findViewById(R.id.button);
        edits=(Button) findViewById(R.id.button2);
        deletes=(Button) findViewById(R.id.button3);
        ups=(Button) findViewById(R.id.button4);
        runs=(Button) findViewById(R.id.button6);
        int b = 0, c = 0;
        int a[] = new int[2];
        a = helper.getrecordnos();
        //  Message.message(getApplicationContext(),Integer.toString(a[0]));
        if (a[0] < 1 && a[1]<1) {
            views.setEnabled(false);
            edits.setEnabled(false);
            deletes.setEnabled(false);
        }
        else
        {
            views.setEnabled(true);
            edits.setEnabled(true);
            deletes.setEnabled(true);
        }
        try {
            b = helper.getcurtask();
            if (b > 0) {
                runs.setEnabled(true);
            }
            else
            {
                runs.setEnabled(false);
            }
            c=helper.upcomingtask();
            if (c>0)
            {
                ups.setEnabled(true);
            }
            else
            {ups.setEnabled(false);
            }
        }
        catch(Exception e){}
    }
    public void delete(View view)
    {
        Intent i = new Intent(this, DeleteActivity.class);
        startActivity(i);
    }
    public void edit(View view)
    {
        Intent i = new Intent(this, EditTaskActivity.class);
        startActivity(i);
    }
    public void running(View view)
    {
        Intent i = new Intent(this, RunTaskActivity.class);
        startActivity(i);
    }
    public void add(View view)
    {
        Intent i = new Intent(this, SetTaskActivity.class);
        startActivity(i);
    }
    public void upcoming(View view)
    {
        Intent i = new Intent(this, UpcomingTaskActivity.class);
        startActivity(i);
    }
    public void view(View view)
    {
        Intent i = new Intent(this, ViewTaskActivity.class);
        startActivity(i);
    }
    public void gohome(View view)
    {
        Intent i = new Intent(this, MainActivity.class);
        startActivity(i);
    }
    public void getdb (View view)
    {
        Intent i = new Intent(this, DeveloperActivity.class);
        startActivity(i);
    }
}
