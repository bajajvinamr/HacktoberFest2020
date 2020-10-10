package com.londonappbrewery.destini;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    TextView mstoryTextView;
    Button buttonTop;
    Button buttonBottom;
    int mtext;
    int mbuttontoptext;
    int mbuttonbottomtext;
    int mStoryIndex;


    // TODO: Steps 4 & 8 - Declare member variables here:
    private StoryOption[] mStory= new StoryOption[]{
            new StoryOption(R.string.T1_Story,R.string.T1_Ans1,R.string.T1_Ans2,1,2),
            new StoryOption(R.string.T2_Story,R.string.T2_Ans1,R.string.T2_Ans2,1,2),
            new StoryOption(R.string.T3_Story,R.string.T3_Ans1,R.string.T3_Ans2,1,2),
            new StoryOption(R.string.T4_End,R.string.T1_Ans1,R.string.T1_Ans2,1,2),
            new StoryOption(R.string.T5_End,R.string.T1_Ans1,R.string.T1_Ans2,1,2),
            new StoryOption(R.string.T6_End,R.string.T1_Ans1,R.string.T1_Ans2,1,2)
    };


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mStoryIndex=0;

        // TODO: Step 5 - Wire up the 3 views from the layout to the member variables:
        mstoryTextView = (TextView) findViewById(R.id.storyTextView);
        buttonTop = (Button) findViewById(R.id.buttonTop);
        buttonBottom=(Button)findViewById(R.id.buttonBottom);

        mtext = mStory[mStoryIndex].getStoryText();
        mstoryTextView.setText(mtext);
        mbuttontoptext=mStory[mStoryIndex].getTopButtonText();
        buttonTop.setText(mbuttontoptext);
        mbuttonbottomtext=mStory[mStoryIndex].getBottomButtonText();
        buttonBottom.setText(mbuttonbottomtext);


        // TODO: Steps 6, 7, & 9 - Set a listener on the top button:
        buttonTop.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Log.d("destiny","Top Button Pressed");
                checkAnswer(1);
                updateText();

            }
        });


        // TODO: Steps 6, 7, & 9 - Set a listener on the bottom button:
        buttonBottom.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Log.d("destiny","Bottom Button Pressed");
                checkAnswer(2);
                updateText();

            }
        });


    }
    private void updateText() {
        if (mStoryIndex <= 2)
        {
            mtext = mStory[mStoryIndex].getStoryText();
            mstoryTextView.setText(mtext);
            mbuttontoptext=mStory[mStoryIndex].getTopButtonText();
            buttonTop.setText(mbuttontoptext);
            mbuttonbottomtext=mStory[mStoryIndex].getBottomButtonText();
            buttonBottom.setText(mbuttonbottomtext);

        }
        else
        {
            mtext = mStory[mStoryIndex].getStoryText();
            mstoryTextView.setText(mtext);
            buttonBottom.setVisibility(View.GONE);
            buttonTop.setVisibility(View.GONE);
        }
    }
    private void checkAnswer(int UserSelection)
    {
        int option1= mStory[mStoryIndex].getOption1();
        int option2=mStory[mStoryIndex].getOption2();
        if((mStoryIndex==0) && (UserSelection==option1))
        {
            mStoryIndex=2;
        }
        else if((mStoryIndex==0) && (UserSelection==option2))
        {
            mStoryIndex=1;
        }
        else if((mStoryIndex==1) && (UserSelection==option1))
        {
            mStoryIndex=2;
        }
        else if((mStoryIndex==1) && (UserSelection==option2))
        {
            mStoryIndex=3;
        }
        else if((mStoryIndex==2) && (UserSelection==option1))
        {
            mStoryIndex=5;
        }
        else if((mStoryIndex==2) && (UserSelection==option2))
        {
            mStoryIndex=4;
        }
    }






}
