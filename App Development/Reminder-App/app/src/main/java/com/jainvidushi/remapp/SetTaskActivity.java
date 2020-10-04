package com.jainvidushi.remapp;

import android.app.DatePickerDialog;
import android.app.TimePickerDialog;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.DatePicker;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.TimePicker;

import org.w3c.dom.Text;

import java.text.ParseException;
import java.util.Calendar;
import java.util.Date;

import static android.os.Build.VERSION_CODES.M;
import static com.jainvidushi.remapp.R.id.st;

public class SetTaskActivity extends AppCompatActivity implements
        View.OnClickListener {
    EditText Name,Descr,DurDay,DurHr,DurMin,StDat,StTime;
    dbmanag helper;
    Button btnDatePicker, btnTimePicker;
    EditText txtDate, txtTime;
    private int mYear, mMonth, mDay, mHour, mMinute;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_set_task);
        Name= (EditText) findViewById(R.id.tn);
        Descr= (EditText) findViewById(R.id.editText);
        DurDay= (EditText) findViewById(R.id.dur_day);
        DurHr= (EditText) findViewById(R.id.dur_hour);
        DurMin= (EditText) findViewById(R.id.dur_min);
        StDat= (EditText) findViewById(R.id.in_date);
        StTime= (EditText) findViewById(R.id.in_time);
        btnDatePicker=(Button)findViewById(R.id.btn_date);
        btnTimePicker=(Button)findViewById(R.id.btn_time);
        txtDate=(EditText)findViewById(R.id.in_date);
        txtTime=(EditText)findViewById(R.id.in_time);
        btnDatePicker.setOnClickListener(this);
        btnTimePicker.setOnClickListener(this);
        helper = new dbmanag(this);
    }
    public void settask(View view)throws ParseException
    {
        String t1 = Name.getText().toString();
        String t2 = Descr.getText().toString();
        String dd=DurDay.getText().toString();
        String dh=DurHr.getText().toString();
        String dm=DurMin.getText().toString();
        String sd=StDat.getText().toString();
        String st=StTime.getText().toString();
        if (dd.equals(""))
        {
            dd="0";
        }
        if (dh.equals(""))
        {
            dh="0";
        }
        if (dm.equals(""))
        {
            dm="0";
        }
        int ndd=Integer.parseInt(dd);
        int ndh=Integer.parseInt(dh);
        int ndm=Integer.parseInt(dm);
        long ndur=(ndd*24*60*60)+(ndh*60*60)+(ndm*60);
        ndur=ndur*1000;
        MyTime d_t=new MyTime();
        MyTime t_d=new MyTime();
        String Start_date=sd+" "+st;
        long new_start_time=d_t.date_to_timestamp(Start_date);
        long cur=new Date().getTime();
        if(t1.isEmpty() || t2.isEmpty())
        {
            Message.message(getApplicationContext(),"Enter Both Name and Description");
        }
        else
        {
            long id = helper.insertData(t1,t2,new_start_time,ndur,"ACTIVE");
            if(id<=0)
            {
                Message.message(getApplicationContext(),"Insertion Unsuccessful");
                Name.setText("");
                Descr.setText("");
                DurDay.setText("");
                DurHr.setText("");
                DurMin.setText("");
                StDat.setText("");
                StTime.setText("");
            } else
            {
                Message.message(getApplicationContext(),"Insertion Successful");
                Name.setText("");
                Descr.setText("");
                DurDay.setText("");
                DurHr.setText("");
                DurMin.setText("");
                StDat.setText("");
                StTime.setText("");
            }
        }
    }
    @Override
    public void onClick(View v){
        if (v == btnDatePicker) {

            // Get Current Date
            final Calendar c = Calendar.getInstance();
            mYear = c.get(Calendar.YEAR);
            mMonth = c.get(Calendar.MONTH);
            mDay = c.get(Calendar.DAY_OF_MONTH);


            DatePickerDialog datePickerDialog = new DatePickerDialog(this,
                    new DatePickerDialog.OnDateSetListener() {

                        @Override
                        public void onDateSet(DatePicker view, int year,
                                              int monthOfYear, int dayOfMonth) {
                            if (monthOfYear<10 && dayOfMonth<10) {
                                txtDate.setText("0" + dayOfMonth + "-" + "0" + (monthOfYear + 1) + "-" + year);
                            }
                            else if (monthOfYear<10 && dayOfMonth>=10)
                            {
                                txtDate.setText(dayOfMonth + "-" + "0" + (monthOfYear + 1) + "-" + year);
                            }
                            else if (monthOfYear>=10 && dayOfMonth<10)
                            {
                                txtDate.setText("0" + dayOfMonth + "-" + (monthOfYear + 1) + "-" + year);
                            }
                            else
                            {
                                txtDate.setText( dayOfMonth + "-"  + (monthOfYear + 1) + "-" + year);
                            }

                        }
                    }, mYear, mMonth, mDay);
            datePickerDialog.show();
        }
        if (v == btnTimePicker) {

            // Get Current Time
            final Calendar c = Calendar.getInstance();
            mHour = c.get(Calendar.HOUR_OF_DAY);
            mMinute = c.get(Calendar.MINUTE);

            // Launch Time Picker Dialog
            TimePickerDialog timePickerDialog = new TimePickerDialog(this,
                    new TimePickerDialog.OnTimeSetListener() {

                        @Override
                        public void onTimeSet(TimePicker view, int hourOfDay,
                                              int minute) {
                            if (minute<10 && hourOfDay<10) {

                                txtTime.setText("0" + hourOfDay + ":" + "0" + minute);
                            }

                            else if (hourOfDay<10 && minute>=10)
                            {
                                txtTime.setText("0"+ hourOfDay + ":" + minute);
                            }
                            else if (hourOfDay>=10 && minute<10)
                            {
                                txtTime.setText(hourOfDay + ":" + "0" + minute);
                            }
                            else
                            {
                                txtTime.setText(hourOfDay + ":"  + minute);
                            }
                        }
                    }, mHour, mMinute, false);
            timePickerDialog.show();
        }
    }
    public void menu_nav(View view)
    {
        Intent i = new Intent(this, Menu_NavActivity.class);
        startActivity(i);
    }
}