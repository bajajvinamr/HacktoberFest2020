package com.example.engineersk.mydiceapp;

import androidx.appcompat.app.AppCompatActivity;

import android.media.MediaPlayer;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;

import com.daimajia.androidanimations.library.Techniques;
import com.daimajia.androidanimations.library.YoYo;

import java.util.Random;

public class MainActivity extends AppCompatActivity {

    private ImageView mDiceImage1;
    private ImageView mDiceImage2;
    private Button mRollDiceButton;

    final int[] diceImage = {0, R.drawable.dice1,  R.drawable.dice2, R.drawable.dice3,
            R.drawable.dice4, R.drawable.dice5,  R.drawable.dice6};

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mDiceImage1 = findViewById(R.id.imageDice1ID);
        mDiceImage2 = findViewById(R.id.imageDice2ID);
        mRollDiceButton = findViewById(R.id.rollDiceBtnID);
        final MediaPlayer mp = MediaPlayer.create(this, R.raw.dice_sound);


        Random initialRandomDiceRoll = new Random();
        mDiceImage1.setImageResource(diceImage[1 + initialRandomDiceRoll.nextInt(6)]);
        mDiceImage2.setImageResource(diceImage[1 + initialRandomDiceRoll.nextInt(6)]);

        mRollDiceButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Random randomDiceRoll = new Random();
                int randomDiceIndex1 = 1 + randomDiceRoll.nextInt(6);
                int randomDiceIndex2 = 1 + randomDiceRoll.nextInt(6);
                mDiceImage1.setImageResource(diceImage[randomDiceIndex1]);
                mDiceImage2.setImageResource(diceImage[randomDiceIndex2]);

                YoYo.with(Techniques.Shake)
                        .duration(500)
                        .repeat(0)
                        .playOn(mDiceImage1);

                YoYo.with(Techniques.Shake)
                        .duration(500)
                        .repeat(0)
                        .playOn(mDiceImage2);

                mp.start();
            }
        });
    }
}
