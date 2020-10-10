package com.example.randomnumbergenerator;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import java.util.Random;

public class MainActivity extends AppCompatActivity {
    private Button btn;
    private TextView textView;

    @Override
    protected void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        btn=findViewById(R.id.random_number_button);
        textView=findViewById(R.id.random_number_view);

        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                randomNumber();
            }
        });
    }

    private void randomNumber() {
        Random rand= new Random();
        int n=rand.nextInt(1000);
        n+=1;
        textView.setText(String.valueOf(n));
    }
}