package com.example.guessinggame;

import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import java.util.Random;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {
    public static final int MAX_NUM=100;
    public static final Random RANDOM =new Random();
    private TextView head;
    private TextView msgtv;
    private TextView numtry;
    private EditText numinput;
    private Button submit;
    private Button playagain;
    private Button exit;
    private int numtofind,tries;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        head=(TextView)findViewById(R.id.textView2);
        msgtv=(TextView) findViewById(R.id.textView3);
        numtry=(TextView) findViewById(R.id.textView5);
        numinput=(EditText) findViewById(R.id.editTextNumber);
        playagain=(Button) findViewById(R.id.button2);
                playagain.setOnClickListener(this);
        exit=(Button) findViewById(R.id.button3);
                exit.setOnClickListener(this);
        submit = (Button) findViewById(R.id.button);
                submit.setOnClickListener(this);
                newgame();
    }
    @Override
    public void onClick(View view){
        try {
            if(view ==  submit)
            {
                submit();
            }
        } catch (NumberFormatException e) {
            Toast.makeText(getApplicationContext(), "Enter a valid number", Toast.LENGTH_SHORT).show();
//            numinput.setText("");
        }
        if(view == playagain)
        {
            Intent intent=new Intent();
            intent.setClass(this, this.getClass());
            this.startActivity(intent);
            this.finish();
        }
        else if(view == exit)
        {
            finish();
        }
    }
    private void submit()
    {
        int n=Integer.parseInt(numinput.getText().toString());
        if(n<1 || n>100)
        {
            msgtv.setText("Please Enter a number between 1-100");
            numinput.setText("");
            numtry.setText("Number of tries = "+tries);
        }
        else if(n == numtofind)
        {
            msgtv.setTextColor(0xFF00FF00);
            head.setText("Want to play once again?\nIf Yes then click on Play again else you can Exit");
            msgtv.setText("Congratulations !\nYou found the correct number "+numtofind+" in "+tries+" tries.");
            numinput.setText("");
            submit.setText("EXIT");
            numtry.setVisibility(View.INVISIBLE);
            submit.setVisibility(View.INVISIBLE);
            playagain.setVisibility(View.VISIBLE);
            exit.setVisibility(View.VISIBLE);

//            Intent i = getBaseContext().getPackageManager()
//                    .getLaunchIntentForPackage(getBaseContext().getPackageName());
//            i.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP | Intent.FLAG_ACTIVITY_CLEAR_TASK);
//            startActivity(i);
        }
        else if(n<numtofind)
        {
            msgtv.setText("Please guess a Higher number");
            tries++;
            numtry.setText("Number of tries = "+tries);
            numinput.setText("");
        }
        else
        {
            msgtv.setText("Please guess a Lower number");
            tries++;
            numinput.setText("");
            numtry.setText("Number of tries = "+tries);
        }
    }

    private void newgame()
    {
        numtofind=RANDOM.nextInt(MAX_NUM)+1;
        head.setText("GUESS A NUMBER BETWEEN 1-100");
        numinput.setText("");
//        msgtv.setTextColor(0xFF000000);
        tries=0;
    }
}