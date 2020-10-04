package com.jainvidushi.remapp;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;
import android.os.CountDownTimer;

import org.w3c.dom.Text;

import java.util.Date;

import static com.jainvidushi.remapp.R.id.st;
import static java.lang.Double.parseDouble;
import static java.lang.Long.parseLong;

public class RunTaskActivity extends AppCompatActivity {
    TextView ttname,starttim,dura,des,dleft,hleft,mleft,sleft;
    public long counter,durs;
String runtask;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_run_task);
        ttname= (TextView) findViewById(R.id.tname);
        starttim= (TextView) findViewById(R.id.sttim);
        dura= (TextView) findViewById(R.id.duration);
        des= (TextView) findViewById(R.id.describe);
        dleft= (TextView) findViewById(R.id.left);
        hleft= (TextView) findViewById(R.id.left1);
        mleft= (TextView) findViewById(R.id.left2);
        sleft= (TextView) findViewById(R.id.left3);
        dbmanag helper;
        helper = new dbmanag(this);
        try {
            runtask=helper.getruntask();
           // Message.message(getApplicationContext(),"Running task  " + runtask);
        } catch (Exception e) {
        }
        if (runtask!=null)
       // MyTime stt=new MyTime();
        {MyTime obj=new MyTime();
        String task_name,task_desr,sttime,dur;
        int durn;
        String task[]=new String[8];
        task=runtask.split("/");
        task_name=task[1];
        task_desr=task[2];
        sttime=task[3];
        dur=task[4];
        durs=Long.parseLong(dur);
        int min;
        int hr;
        int day;
        double mydur=durs/1000;
        mydur=mydur/86400;
        day=(int)mydur;
        mydur=mydur-day;
        mydur=mydur*24;
        hr=(int)mydur;
        mydur=mydur-hr;
        mydur=mydur*60;
        min=(int)mydur;
        dur=Integer.toString(day)+"  Days "+ Integer.toString(hr)+ " Hour " +Integer.toString(min)+" Min ";
        String sttimes;
         try {
            sttimes=obj.timestamp_to_date(Long.parseLong(sttime));

            //Message.message(getApplicationContext(),"Running task  " + runtask);
            starttim.setText(sttimes);

        } catch (Exception e) {
        }
        dura.setText(dur);
        ttname.setText(task_name);
        des.setText(task_desr);
        long cur=new Date().getTime();
        long start=Long.parseLong(sttime);
        long t=cur-start;
        durs=durs-t;
        counter=durs;
        new CountDownTimer(durs,1000)
        {

            public void onTick(long millisUntilFinished)
            {
                long temp=millisUntilFinished;
                res_dur_str =timer_str(temp);
                dleft.setText(res_dur_str[0]);
                hleft.setText(res_dur_str[1]);
                mleft.setText(res_dur_str[2]);
                sleft.setText(res_dur_str[3]);
                res_dur_str[0]="";
                res_dur_str[1]="";
                res_dur_str[2]="";
                res_dur_str[3]="";
            }
            public void onFinish()
            {
                dleft.setText("Finish!!");
                hleft.setText("");
                mleft.setText("");
                sleft.setText("");

            }
        }.start();}
        else
        {
            Message.message(getApplicationContext(),"No running task");
        }
    }
    String res_dur_str[]=new String[4];
    public String[] timer_str(long resdur)
    {
        String res_str_in[] = new String[4];
        if (runtask!=null) {
            double mycounter = resdur / 1000;
            mycounter = mycounter / 86400;
            int days = (int) mycounter;
            mycounter = mycounter - days;
            mycounter = mycounter * 24;
            int hrs = (int) mycounter;
            mycounter = mycounter - hrs;
            mycounter = mycounter * 60;
            int mins = (int) mycounter;
            mycounter = mycounter - mins;
            mycounter = mycounter * 60;
            int sec = (int) mycounter;
            res_str_in[0] = Integer.toString(days);
            res_str_in[1] = Integer.toString(hrs);
            res_str_in[2] = Integer.toString(mins);
            res_str_in[3] = Integer.toString(sec);}
            return (res_str_in);
    }
    public void menu_nav(View view)
    {
        Intent i = new Intent(this, Menu_NavActivity.class);
        startActivity(i);
    }

}
