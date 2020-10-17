package com.aplikasi.alquranque;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;

public class AboutActivity extends AppCompatActivity {

    private ImageView backKen;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_about);
        //intent
        backKen = (ImageView) findViewById(R.id.backKenK);
        backKen.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent back =new Intent(AboutActivity.this, DashboardActivity.class);
                startActivity(back);
                finish();
            }
        });
    }
        @Override
        public void onBackPressed() {
            Intent back =new Intent(AboutActivity.this, DashboardActivity.class);
            startActivity(back);
            finish();
        }
    }
