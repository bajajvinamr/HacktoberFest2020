package com.jainvidushi.remapp;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import org.w3c.dom.Text;

import static com.jainvidushi.remapp.R.id.t1;
import static com.jainvidushi.remapp.R.id.t2;

public class Sub_Delete_Activity extends AppCompatActivity {
    TextView idf,Name,Descr;
    String s;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sub__delete_);
        idf= (TextView) findViewById(R.id.ids);
        Name= (TextView) findViewById(R.id.tn_v);
        Descr= (TextView) findViewById(R.id.edittext_v);
        s=getIntent().getStringExtra("MyID");
        //  idf.setText(s);
        dbmanag helper=new dbmanag(this);
        String getdata=helper.gettaskdetail(s);
        String b[]=new String[4];
        b=getdata.split("/");
        Name.setText(b[0]);
        Descr.setText(b[1]);
    }
    public void menu_nav(View view)
    {
        Intent i = new Intent(this, Menu_NavActivity.class);
        startActivity(i);
    }
    public void deletetask(View view)
    {
        dbmanag helper=new dbmanag(this);
        long count = helper.delete(Integer.parseInt(s));
        if (count == 1)

            Message.message(getApplicationContext(), "Delete successful");

        else
            Message.message(getApplicationContext(), "Delete failed");
    }
}
