package com.example.simplenoteapplication;

import androidx.annotation.Nullable;
import androidx.annotation.RequiresApi;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Build;
import android.os.Bundle;
import android.os.Parcelable;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.ContextMenu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.Toast;

import com.google.android.material.floatingactionbutton.FloatingActionButton;
import com.google.gson.Gson;
import com.google.gson.annotations.SerializedName;
import com.google.gson.reflect.TypeToken;

import java.io.Serializable;
import java.lang.reflect.Type;
import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    public static final String EXTRA_MESSAGE = "com.example.android.Simple Note application.Extra.Object";
    public static final int TEXT_REQUEST = 1;
    public static int positionToBeChanged = 0;
    public static boolean isAddingNewNote = false;
    public ArrayList<NoteInfo> note_details;
    private ListView listView;
    private EditText editSearch;
    private NoteAdapter adapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        note_details = getListData();
        listView = findViewById(R.id.listView);
        editSearch = findViewById(R.id.searchBar);

        adapter = new NoteAdapter(this,note_details);
        listView.setAdapter(adapter);

        listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int position, long l) {
                positionToBeChanged = position;
                NoteInfo message = (NoteInfo)  adapterView.getItemAtPosition(position);
                Intent intent = new Intent(getApplicationContext(),NoteDetailActivity.class);
                intent.putExtra(MainActivity.EXTRA_MESSAGE, (Serializable) message);
                startActivityForResult(intent,TEXT_REQUEST);
            }
        });
        editSearch.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence charSequence, int i, int i1, int i2) {
            }

            @Override
            public void onTextChanged(CharSequence charSequence, int i, int i1, int i2) {

            }

            @Override
            public void afterTextChanged(Editable editable) {
                String text = editSearch.getText().toString().toLowerCase();
                adapter.filter(text);
            }
        });

        FloatingActionButton fab = findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @RequiresApi(api = Build.VERSION_CODES.O)
            @Override
            public void onClick(View view) {
                isAddingNewNote = true;
                Intent intent = new Intent(getApplicationContext(), NoteDetailActivity.class);
                NoteInfo message = new NoteInfo("", "", "");
                intent.putExtra(MainActivity.EXTRA_MESSAGE,message);
                startActivityForResult(intent, TEXT_REQUEST);
            }
        });
        registerForContextMenu(listView);
    }


    @Override
    protected void onPause() {
        super.onPause();
        saveData();
    }
    @Override
    protected void onStop() {
        super.onStop();
        saveData();
    }

    private void saveData(){
        SharedPreferences prefs=this.getSharedPreferences("MyList",Context.MODE_PRIVATE);
        SharedPreferences.Editor edit=prefs.edit();
        Gson gson = new Gson();
        String json = gson.toJson(note_details);
        edit.putString("MyList", json);
        edit.commit();
        Toast.makeText(getApplicationContext(),"All changes saved" ,Toast.LENGTH_LONG).show();
    }



    @Override
    public void onCreateContextMenu(ContextMenu menu, View v, ContextMenu.ContextMenuInfo menuInfo)
    {
        super.onCreateContextMenu(menu, v, menuInfo);
        MenuInflater inflater = getMenuInflater();
        inflater.inflate(R.menu.context_menu,menu);
    }

    @Override
    public boolean onContextItemSelected(MenuItem item){
        if(item.getItemId()==R.id.optionDelete){
            AdapterView.AdapterContextMenuInfo info = (AdapterView.AdapterContextMenuInfo) item.getMenuInfo();
            int index = info.position;
            switch(item.getItemId()){
                case R.id.optionDelete:
                {
                    note_details.remove(index);
                    adapter.notifyDataSetChanged();
                    listView.setAdapter(adapter);
                    Toast.makeText(getApplicationContext(),"Deleted!",Toast.LENGTH_LONG).show();
                } break;
            }
        }

        return true;
    }
    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (requestCode == TEXT_REQUEST){
            if(resultCode == RESULT_OK){
                NoteInfo reply = (NoteInfo) data.getSerializableExtra(NoteDetailActivity.EXTRA_REPLY);
                final ListView listView =  findViewById(R.id.listView);

                if(isAddingNewNote == true){
                    note_details.add(0,reply);
                }
                else{
                    note_details.remove(positionToBeChanged);
                    note_details.add(positionToBeChanged,reply);
                }

                isAddingNewNote = false;
                saveData();
                adapter = new NoteAdapter(this,note_details);
                listView.setAdapter(adapter);
            }
        }
    }
    private ArrayList<NoteInfo> getListData(){
        SharedPreferences prefs=this.getSharedPreferences("MyList", Context.MODE_PRIVATE);
        Gson gson = new Gson();
        String json = prefs.getString("MyList",null);
        Type type = new TypeToken<ArrayList<NoteInfo>>() {}.getType();
        note_details = gson.fromJson(json,type);
        if (note_details == null)
        {
            note_details = new ArrayList<>();
        }
        return note_details;
    }
}
