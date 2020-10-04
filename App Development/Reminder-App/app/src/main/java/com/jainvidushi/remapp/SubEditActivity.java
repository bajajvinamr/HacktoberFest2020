package com.jainvidushi.remapp;

import android.app.DatePickerDialog;
import android.app.TimePickerDialog;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.DatePicker;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.TimePicker;

import java.text.ParseException;
import java.util.Calendar;
import java.util.Date;

import static android.icu.lang.UCharacter.GraphemeClusterBreak.V;
import static com.jainvidushi.remapp.R.id.t1;

public class SubEditActivity extends AppCompatActivity implements View.OnClickListener {
    dbmanag helper;
    TextView idf;
    Button btnDatePicker, btnTimePicker;
    EditText txtDate, txtTime;
    private int mYear, mMonth, mDay, mHour, mMinute;
    EditText Name, Descr, DurDay, DurHr, DurMin, StDat, StTime;
    String s;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sub_edit);
        idf = (TextView) findViewById(R.id.ids);
        Name = (EditText) findViewById(R.id.tn_edit);
        Descr = (EditText) findViewById(R.id.editText_edit);
        DurDay = (EditText) findViewById(R.id.dur_day_edit);
        DurHr = (EditText) findViewById(R.id.dur_hour_edit);
        DurMin = (EditText) findViewById(R.id.dur_min_edit);
        StDat = (EditText) findViewById(R.id.in_date_edit);
        StTime = (EditText) findViewById(R.id.in_time_edit);
        btnDatePicker = (Button) findViewById(R.id.btn_date_edit);
        btnTimePicker = (Button) findViewById(R.id.btn_time_edit);
        txtDate = (EditText) findViewById(R.id.in_date_edit);
        txtTime = (EditText) findViewById(R.id.in_time_edit);
        btnDatePicker.setOnClickListener(this);
        btnTimePicker.setOnClickListener(this);
        s = getIntent().getStringExtra("MyID");
        //   idf.setText(s);
        dbmanag helper = new dbmanag(this);
        String getdata = helper.gettaskdetail(s);
        String b[] = new String[4];
        b = getdata.split("/");
        Name.setText(b[0]);
        Descr.setText(b[1]);
        String q = b[2];
        MyTime obj = new MyTime();
        long pass;
        pass = Long.parseLong(q);
        try {
            q = obj.timestamp_to_date(pass);
        } catch (Exception e) {
        }
        String dr = b[3];
        long drs;
        drs = Long.parseLong(dr);
        int min;
        int hr;
        int day;
        double mydur = drs / 1000;
        mydur = mydur / 86400;
        day = (int) mydur;
        mydur = mydur - day;
        mydur = mydur * 24;
        hr = (int) mydur;
        mydur = mydur - hr;
        mydur = mydur * 60;
        min = (int) mydur;
        DurDay.setText(Integer.toString(day));
        DurHr.setText(Integer.toString(hr));
        DurMin.setText(Integer.toString(min));
        String start[] = new String[2];
        start = q.split(" ");
        StDat.setText(start[0]);
        StTime.setText(start[1]);
    }

    public void menu_nav(View view) {
        Intent i = new Intent(this, Menu_NavActivity.class);
        startActivity(i);
    }

    public void onClick(View v) {
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
                            if (monthOfYear < 10 && dayOfMonth < 10) {
                                txtDate.setText("0" + dayOfMonth + "-" + "0" + (monthOfYear + 1) + "-" + year);
                            } else if (monthOfYear < 10 && dayOfMonth >= 10) {
                                txtDate.setText(dayOfMonth + "-" + "0" + (monthOfYear + 1) + "-" + year);
                            } else if (monthOfYear >= 10 && dayOfMonth < 10) {
                                txtDate.setText("0" + dayOfMonth + "-" + (monthOfYear + 1) + "-" + year);
                            } else {
                                txtDate.setText(dayOfMonth + "-" + (monthOfYear + 1) + "-" + year);
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
                            if (minute < 10 && hourOfDay < 10) {

                                txtTime.setText("0" + hourOfDay + ":" + "0" + minute);
                            } else if (hourOfDay < 10 && minute >= 10) {
                                txtTime.setText("0" + hourOfDay + ":" + minute);
                            } else if (hourOfDay >= 10 && minute < 10) {
                                txtTime.setText(hourOfDay + ":" + "0" + minute);
                            } else {
                                txtTime.setText(hourOfDay + ":" + minute);
                            }
                        }
                    }, mHour, mMinute, false);
            timePickerDialog.show();
        }
    }

    public void edittask(View view) throws ParseException {
        helper = new dbmanag(this);
        String t1 = Name.getText().toString();
        String t2 = Descr.getText().toString();
        String dd = DurDay.getText().toString();
        String dh = DurHr.getText().toString();
        String dm = DurMin.getText().toString();
        String sd = StDat.getText().toString();
        String st = StTime.getText().toString();
        int ndd = Integer.parseInt(dd);
        int ndh = Integer.parseInt(dh);
        int ndm = Integer.parseInt(dm);
        long ndur = (ndd * 24 * 60 * 60) + (ndh * 60 * 60) + (ndm * 60);
        ndur = ndur * 1000;
        MyTime d_t = new MyTime();
        MyTime t_d = new MyTime();
        String Start_date = sd + " " + st;
        long new_start_time = d_t.date_to_timestamp(Start_date);
        long cur = new Date().getTime();
        if (t1.isEmpty() || t2.isEmpty())
            Message.message(getApplicationContext(), "Enter Both Name and Description");
        else {
            long count = helper.updatetask(Integer.parseInt(s), t1, t2, new_start_time, ndur);
            if (count == 1)

                Message.message(getApplicationContext(), "Update successful");

            else
                Message.message(getApplicationContext(), "Update failed");
        }
    }
}




