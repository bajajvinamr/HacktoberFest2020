package com.aplikasi.alquranque;

import androidx.appcompat.app.AppCompatActivity;
import androidx.cardview.widget.CardView;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

public class DashboardActivity extends AppCompatActivity {
    private CardView cvQuran;
    private CardView cvProfile;
    private CardView cvHadist;
    private CardView cvKiblat;
    private CardView cvDzikir;
    private long exitTime = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.activity_dashboard);
        //intent
        cvQuran = (CardView) findViewById(R.id.btn_quran);
        cvQuran.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent quran =new Intent(DashboardActivity.this, AlquranActivity.class);
                startActivity(quran);
                finish();
            }
        });

        //intent
        cvProfile = (CardView) findViewById(R.id.btn_about);
        cvProfile.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent about =new Intent(DashboardActivity.this, AboutActivity.class);
                startActivity(about);
                finish();
            }
        });
        //intent
        cvHadist = (CardView) findViewById(R.id.btn_hadist);
        cvHadist.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent hadist =new Intent(DashboardActivity.this, HadistActivity.class);
                startActivity(hadist);
                finish();
            }
        });
        //intent
        cvKiblat = (CardView) findViewById(R.id.btn_kiblat);
        cvKiblat.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent kiblat =new Intent(DashboardActivity.this, KiblatActivity.class);
                startActivity(kiblat);
                finish();
            }
        });
        //intent
        cvDzikir = (CardView) findViewById(R.id.btn_dzikir);
        cvDzikir.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent dzikir =new Intent(DashboardActivity.this, DzikirActivity.class);
                startActivity(dzikir);
                finish();
            }
        });
    }
    @Override
    public void onBackPressed() {


        if ((System.currentTimeMillis() - exitTime) > 2000) {
            Toast.makeText(this, "Press again to exit", Toast.LENGTH_SHORT).show();
            exitTime = System.currentTimeMillis();
        } else {
            finish();
        }


    }
}
