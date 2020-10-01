package com.example.simplenoteapplication;

import androidx.annotation.RequiresApi;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Build;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

import java.io.Serializable;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

public class NoteDetailActivity extends AppCompatActivity {
    public static final String EXTRA_REPLY = "com.example.android.notedetailactivity.extra.REPLY";
    private EditText mTitleSave;
    private EditText mContentSave;
    private EditText mTagSave;

    @RequiresApi(api = Build.VERSION_CODES.O)

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_note_detail);

        Intent intent = getIntent();
        NoteInfo message = (NoteInfo) intent.getSerializableExtra(MainActivity.EXTRA_MESSAGE);

        EditText titleEdit = findViewById(R.id.title_edit);
        titleEdit.setText(message.get_Title());

        EditText tagEdit = findViewById(R.id.tag_edit);
        tagEdit.setText(message.get_Tag());

        EditText contentEdit = findViewById(R.id.content_edit);
        contentEdit.setText(message.get_Content());
    }

    @RequiresApi(api = Build.VERSION_CODES.O)
    public void SaveNoteDetailsClick(View view) {
        mTitleSave = findViewById(R.id.title_edit);
        mContentSave = findViewById(R.id.content_edit);

        mTagSave = findViewById(R.id.tag_edit);
        String returnTitle = mTitleSave.getText().toString();
        String returnContent = mContentSave.getText().toString();
        String returnTag = mTagSave.getText().toString();
        Date date = Calendar.getInstance().getTime();
        DateFormat dateFormat = new SimpleDateFormat("yyyy-mm-dd hh:mm:ss");
        String returnDate = dateFormat.format(date);
        NoteInfo replyMessage = new NoteInfo(returnTitle, returnContent,returnTag,returnDate);

        Intent replyIntent = new Intent();
        replyIntent.putExtra(EXTRA_REPLY, (Serializable) replyMessage);
        setResult(RESULT_OK, replyIntent);
        Toast.makeText(NoteDetailActivity.this, "Changes are saved!", Toast.LENGTH_SHORT).show();
        finish();
    }




}
