package com.aplikasi.alquranque;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.Intent;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.os.Vibrator;
import android.view.MenuItem;
import android.view.View;
import android.widget.TextView;

public class DzikirActivity extends AppCompatActivity {

    TextView dzikir;
    int zikir = 0;
    Vibrator vibe;
    MediaPlayer mediaPlayer;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_dzikir);
        getSupportActionBar().setDisplayHomeAsUpEnabled(true);
        dzikir = (TextView) findViewById(R.id.dzikir);
        vibe = (Vibrator) getSystemService(Context.VIBRATOR_SERVICE);
    }

    public void subhanallah(View view) {
        mediaPlayer = MediaPlayer.create(getApplicationContext(), R.raw.tasbih);
        mediaPlayer.start();
        zikir = zikir + 1;
        tampil(zikir);
        vibe.vibrate(100);
    }

    public void alhamdulillah(View view) {
        mediaPlayer = MediaPlayer.create(getApplicationContext(), R.raw.tahmid);
        mediaPlayer.start();
        zikir = zikir + 1;
        tampil(zikir);
        vibe.vibrate(100);
    }
    public void reset(View view) {
        zikir = 0;
        tampil(zikir);
        vibe.vibrate(100);
    }

    public void lailahaillallah(View view) {
        mediaPlayer = MediaPlayer.create(getApplicationContext(), R.raw.tahlil);
        mediaPlayer.start();
        zikir = zikir + 1;
        tampil(zikir);
        vibe.vibrate(100);
    }

    public void allahuakbar(View view) {
        mediaPlayer = MediaPlayer.create(getApplicationContext(), R.raw.takbir);
        mediaPlayer.start();
        zikir = zikir + 1;
        tampil(zikir);
        vibe.vibrate(100);
    }

    public void tampil(int z) {
        dzikir.setText("" + z);
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()) {
                  case android.R.id.home:
                // todo: goto back activity from here
                Intent intent = new Intent(DzikirActivity.this, DashboardActivity.class);
                intent.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP | Intent.FLAG_ACTIVITY_NEW_TASK);
                startActivity(intent);
                finish();
                return true;
        }
        return super.onOptionsItemSelected(item);
    }
    @Override
    public void onBackPressed() {
        Intent back =new Intent(DzikirActivity.this, DashboardActivity.class);
        startActivity(back);
        finish();
    }

}