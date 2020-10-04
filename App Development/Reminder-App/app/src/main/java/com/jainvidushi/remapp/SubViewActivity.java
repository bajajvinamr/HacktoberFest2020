package com.jainvidushi.remapp;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import org.w3c.dom.Text;

public class SubViewActivity extends AppCompatActivity {
    TextView idf,Name,Descr,DurDay,DurMin,DurHr,StDat,StTime;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sub_view);
        idf= (TextView) findViewById(R.id.ids);
        Name= (TextView) findViewById(R.id.tn_v);
        Descr= (TextView) findViewById(R.id.edittext_v);
        DurDay= (TextView) findViewById(R.id.dur_day_v);
        DurHr= (TextView) findViewById(R.id.dur_hour_v);
        DurMin= (TextView) findViewById(R.id.dur_min_v);
        StDat= (TextView) findViewById(R.id.in_date_v);
        StTime= (TextView) findViewById(R.id.in_time_v);
         String s=getIntent().getStringExtra("MyID");
         //idf.setText(s);
        dbmanag helper=new dbmanag(this);
        String getdata=helper.gettaskdetail(s);
        String b[]=new String[4];
        b=getdata.split("/");
        Name.setText(b[0]);
        Descr.setText(b[1]);
        String q=b[2];
        MyTime obj=new MyTime();
        long pass;
        pass=Long.parseLong(q);
        try {
            q=obj.timestamp_to_date(pass);
        } catch (Exception e) {
        }
        String dr=b[3];
        long drs;
        drs=Long.parseLong(dr);
        int min;
        int hr;
        int day;
        double mydur=drs/1000;
        mydur=mydur/86400;
        day=(int)mydur;
        mydur=mydur-day;
        mydur=mydur*24;
        hr=(int)mydur;
        mydur=mydur-hr;
        mydur=mydur*60;
        min=(int)mydur;
        DurDay.setText(Integer.toString(day)+" days");
        DurHr.setText(Integer.toString(hr)+" hours");
        DurMin.setText(Integer.toString(min)+" min");
        String start[]=new String[2];
        start=q.split(" ");
        StDat.setText(start[0]);
        StTime.setText(start[1]);
    }
    public void menu_nav(View view)
    {
        Intent i = new Intent(this, Menu_NavActivity.class);
        startActivity(i);
    }
}
