package com.jainvidushi.remapp;

/**
 * Created by Vidushi on 06-07-2017.
 */

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import java.text.ParseException;
import java.util.Date;

import static android.R.attr.duration;
import static android.R.attr.name;
import static com.jainvidushi.remapp.R.id.ids;
import static com.jainvidushi.remapp.R.id.st;
//import static com.jainvidushi.remapp.dbmanag.myDbHelper.Duration;
//import static com.jainvidushi.remapp.dbmanag.myDbHelper.StartTime;
//import static com.jainvidushi.remapp.dbmanag.myDbHelper.Duration;
//import static com.jainvidushi.remapp.dbmanag.myDbHelper.StartTime;
//import static com.jainvidushi.remapp.dbmanag.myDbHelper.CreateTime;
//import static com.jainvidushi.remapp.dbmanag.myDbHelper.StartTime;


public class dbmanag {
     myDbHelper myhelper;

    public dbmanag(Context context)
    {
        myhelper = new myDbHelper(context);
    }

    public long insertData(String name, String desc,long start_time, long duration,String status)
    {
        SQLiteDatabase dbb = myhelper.getWritableDatabase();
        ContentValues contentValues = new ContentValues();
        contentValues.put(myDbHelper.NAME, name);
        contentValues.put(myDbHelper.Description, desc);
        contentValues.put(myDbHelper.StartTime, start_time);
        contentValues.put(myDbHelper.Duration, duration);
        contentValues.put(myDbHelper.Status, status);
        long id = dbb.insert(myDbHelper.TABLE_NAME, null , contentValues);

        return id;
    }
    public String getData()
    {
        SQLiteDatabase db = myhelper.getWritableDatabase();
        String[] columns = {myDbHelper.UID,myDbHelper.NAME,myDbHelper.Description, myDbHelper.StartTime, myDbHelper.Duration,myDbHelper.Status};
        Cursor cursor =db.query(myDbHelper.TABLE_NAME,columns,null,null,null,null,null);
        StringBuffer buffer= new StringBuffer();
        while (cursor.moveToNext())
        {
            int cid =cursor.getInt(cursor.getColumnIndex(myDbHelper.UID));
            String name =cursor.getString(cursor.getColumnIndex(myDbHelper.NAME));
            String  desc =cursor.getString(cursor.getColumnIndex(myDbHelper.Description));
            long st =cursor.getLong(cursor.getColumnIndex(myDbHelper.StartTime));
            long durn =cursor.getLong(cursor.getColumnIndex(myDbHelper.Duration));
            String status =cursor.getString(cursor.getColumnIndex(myDbHelper.Status));
            buffer.append(cid+ "   " + name + "   " + desc + " " + st+" " + durn+" " + status+ " \n");
        }
        return buffer.toString();
    }

    public String selectData()
    {
        SQLiteDatabase db = myhelper.getWritableDatabase();
        // String[] columns = {myDbHelper.UID,myDbHelper.NAME,myDbHelper.Description,myDbHelper.StartTime,myDbHelper.Duration,myDbHelper.CreateTime,myDbHelper.EditTime,myDbHelper.Status};
        Cursor cursor =db.rawQuery("SELECT * FROM 'MyTable' WHERE MyStatus = 'ACTIVE' ORDER BY StartTime ASC",null);
        StringBuffer buffer= new StringBuffer();
        while (cursor.moveToNext())
        {
            int cid =cursor.getInt(cursor.getColumnIndex(myDbHelper.UID));
            String name =cursor.getString(cursor.getColumnIndex(myDbHelper.NAME));
            String  desc =cursor.getString(cursor.getColumnIndex(myDbHelper.Description));
            long st =cursor.getLong(cursor.getColumnIndex(myDbHelper.StartTime));
            long durn =cursor.getLong(cursor.getColumnIndex(myDbHelper.Duration));
            String status =cursor.getString(cursor.getColumnIndex(myDbHelper.Status));
            buffer.append(cid+ " /  " + name + " /  " + desc + " /" + st+"/ " + durn+" /" + status+ " \n");
        }
        return buffer.toString();
    }
    public int[] getrecordnos()
    {
        SQLiteDatabase db = myhelper.getWritableDatabase();
        // String[] columns = {myDbHelper.UID,myDbHelper.NAME,myDbHelper.Description,myDbHelper.StartTime,myDbHelper.Duration,myDbHelper.CreateTime,myDbHelper.EditTime,myDbHelper.Status};
        Cursor cursor =db.rawQuery("SELECT * FROM MyTable WHERE MyStatus = 'ACTIVE' ",null);
        int ret[]=new int[2];
        ret[0]=cursor.getCount();
        cursor.close();
        Cursor cursor2 =db.rawQuery("SELECT * FROM 'MyTable' WHERE MyStatus = 'COMPLETE' ",null);
        ret[1]=cursor2.getCount();
        cursor2.close();
        return ret;

    }
    public int getcurtask()throws ParseException
    {

        long cur=new Date().getTime();

        SQLiteDatabase db = myhelper.getWritableDatabase();
        // String[] columns = {myDbHelper.UID,myDbHelper.NAME,myDbHelper.Description,myDbHelper.StartTime,myDbHelper.Duration,myDbHelper.CreateTime,myDbHelper.EditTime,myDbHelper.Status};
        Cursor cursor =db.rawQuery("SELECT * FROM MyTable WHERE MyStatus = 'ACTIVE' AND StartTime<="+ cur+ " AND (StartTime + Duration)>" + cur+ "",null);
        int ret;
        ret=cursor.getCount();
        cursor.close();
        return ret;
    }
    public String gettasklist(String mystatus)
    {
        SQLiteDatabase db = myhelper.getWritableDatabase();
        // String[] columns = {myDbHelper.UID,myDbHelper.NAME,myDbHelper.Description,myDbHelper.StartTime,myDbHelper.Duration,myDbHelper.CreateTime,myDbHelper.EditTime,myDbHelper.Status};
        Cursor cursor =db.rawQuery("SELECT * FROM MyTable WHERE MyStatus = '"+mystatus+"' ORDER BY _id DESC",null);
      //  return "SELECT * FROM MyTable WHERE MyStatus = '" + mystatus +"' ORDER BY CreateTime ASC";
        StringBuffer buffer= new StringBuffer();
        int a= cursor.getCount();
        buffer.append(a+"@");
        while (cursor.moveToNext())
        {
            int cid =cursor.getInt(cursor.getColumnIndex(myDbHelper.UID));
            String name =cursor.getString(cursor.getColumnIndex(myDbHelper.NAME));
            String  desc =cursor.getString(cursor.getColumnIndex(myDbHelper.Description));
            long st =cursor.getLong(cursor.getColumnIndex(myDbHelper.StartTime));
            long durn =cursor.getLong(cursor.getColumnIndex(myDbHelper.Duration));
            String status =cursor.getString(cursor.getColumnIndex(myDbHelper.Status));
            buffer.append(cid+ "/" + name + "@");
        }
        return buffer.toString();
    }
    public String gettaskdetail(String myid)
    {
        SQLiteDatabase db = myhelper.getWritableDatabase();
        // String[] columns = {myDbHelper.UID,myDbHelper.NAME,myDbHelper.Description,myDbHelper.StartTime,myDbHelper.Duration,myDbHelper.CreateTime,myDbHelper.EditTime,myDbHelper.Status};
        Cursor cursor =db.rawQuery("SELECT * FROM MyTable WHERE _id = '"+myid+"' ORDER BY _id ASC",null);
        //  return "SELECT * FROM MyTable WHERE MyStatus = '" + mystatus +"' ORDER BY CreateTime ASC";
        StringBuffer buffer= new StringBuffer();
        while (cursor.moveToNext())
        {
            int cid =cursor.getInt(cursor.getColumnIndex(myDbHelper.UID));
            String name =cursor.getString(cursor.getColumnIndex(myDbHelper.NAME));
            String  desc =cursor.getString(cursor.getColumnIndex(myDbHelper.Description));
            long st =cursor.getLong(cursor.getColumnIndex(myDbHelper.StartTime));
            long durn =cursor.getLong(cursor.getColumnIndex(myDbHelper.Duration));
            String status =cursor.getString(cursor.getColumnIndex(myDbHelper.Status));
            buffer.append(name + "/" + desc + "/" + st+"/" + durn+ "/");
        }
        return buffer.toString();
    }
    public String getruntask()throws ParseException
    {

        long cur=new Date().getTime();

        SQLiteDatabase db = myhelper.getWritableDatabase();
        // String[] columns = {myDbHelper.UID,myDbHelper.NAME,myDbHelper.Description,myDbHelper.StartTime,myDbHelper.Duration,myDbHelper.CreateTime,myDbHelper.EditTime,myDbHelper.Status};
        Cursor cursor =db.rawQuery("SELECT * FROM MyTable WHERE MyStatus = 'ACTIVE' AND StartTime<="+ cur+ " AND (StartTime + Duration)>" + cur+ "",null);
        StringBuffer buffer= new StringBuffer();
        cursor.moveToFirst();
            int cid =cursor.getInt(cursor.getColumnIndex(myDbHelper.UID));
            String name =cursor.getString(cursor.getColumnIndex(myDbHelper.NAME));
            String  desc =cursor.getString(cursor.getColumnIndex(myDbHelper.Description));
            long st =cursor.getLong(cursor.getColumnIndex(myDbHelper.StartTime));
            long durn =cursor.getLong(cursor.getColumnIndex(myDbHelper.Duration));
            String status =cursor.getString(cursor.getColumnIndex(myDbHelper.Status));
            buffer.append(cid+ "/ " + name + "/" + desc + "/" + st+"/" + durn+"/"+ status+"");
        return buffer.toString();
    }

    public  int delete(int ids)
    {
        SQLiteDatabase db = myhelper.getWritableDatabase();
        String[] whereArgs ={Integer.toString(ids)};
        int count =db.delete(myDbHelper.TABLE_NAME ,myDbHelper.UID+" = ?",whereArgs);
        return  count;
    }
    public int upcomingtask()throws ParseException
    {

        long cur=new Date().getTime();

        SQLiteDatabase db = myhelper.getWritableDatabase();
        // String[] columns = {myDbHelper.UID,myDbHelper.NAME,myDbHelper.Description,myDbHelper.StartTime,myDbHelper.Duration,myDbHelper.CreateTime,myDbHelper.EditTime,myDbHelper.Status};
        Cursor cursor =db.rawQuery("SELECT * FROM MyTable WHERE MyStatus = 'ACTIVE' AND StartTime>"+ cur+ "",null);
        int ret;
        ret=cursor.getCount();
        cursor.close();
        return ret;
    }
    public String getupcomingtask()throws ParseException
    {

        long cur=new Date().getTime();

        SQLiteDatabase db = myhelper.getWritableDatabase();
        // String[] columns = {myDbHelper.UID,myDbHelper.NAME,myDbHelper.Description,myDbHelper.StartTime,myDbHelper.Duration,myDbHelper.CreateTime,myDbHelper.EditTime,myDbHelper.Status};
        Cursor cursor =db.rawQuery("SELECT * FROM MyTable WHERE MyStatus = 'ACTIVE' AND StartTime>"+ cur+" ORDER BY StartTime ASC",null);
        StringBuffer buffer= new StringBuffer();
        cursor.moveToFirst();
        String name =cursor.getString(cursor.getColumnIndex(myDbHelper.NAME));
        String  desc =cursor.getString(cursor.getColumnIndex(myDbHelper.Description));
        long st =cursor.getLong(cursor.getColumnIndex(myDbHelper.StartTime));
        long durn =cursor.getLong(cursor.getColumnIndex(myDbHelper.Duration));
        buffer.append(name + "/" + desc + "/" + st+"/" + durn+"/"+"");
        return buffer.toString();
    }
    public int updateName(int ids , String newName, String newdesc, long startt, long durn,String status)
    {
        SQLiteDatabase db = myhelper.getWritableDatabase();
        ContentValues contentValues = new ContentValues();
        contentValues.put(myDbHelper.NAME,newName);
        contentValues.put(myDbHelper.Description,newdesc);
        contentValues.put(myDbHelper.StartTime,startt);
        contentValues.put(myDbHelper.Duration,durn);
        contentValues.put(myDbHelper.Status,status);
        String[] whereArgs= {Integer.toString(ids)};

        int count =db.update(myDbHelper.TABLE_NAME,contentValues, myDbHelper.UID+" = ?",whereArgs );
        return count;
    }
    public int updatetask(int ids , String newName, String newdesc, long startt, long durn)
    {
        SQLiteDatabase db = myhelper.getWritableDatabase();
        ContentValues contentValues = new ContentValues();
        contentValues.put(myDbHelper.NAME,newName);
        contentValues.put(myDbHelper.Description,newdesc);
        contentValues.put(myDbHelper.StartTime,startt);
        contentValues.put(myDbHelper.Duration,durn);
        contentValues.put(myDbHelper.Status,"ACTIVE");
        String[] whereArgs= {Integer.toString(ids)};

        int count =db.update(myDbHelper.TABLE_NAME,contentValues, myDbHelper.UID+" = ?",whereArgs );
        return count;
    }
    public int updatestatus()
    {
        long cur=new Date().getTime();
       // "SELECT * FROM MyTable WHERE MyStatus = 'ACTIVE' AND StartTime<="+ cur+ " AND (StartTime + Duration)>" + cur+ ""
        SQLiteDatabase db = myhelper.getWritableDatabase();
        ContentValues contentValues = new ContentValues();
        contentValues.put(myDbHelper.Status,"COMPLETE");
        String[] whereArgs= {"ACTIVE"};
        int count =db.update(myDbHelper.TABLE_NAME,contentValues, myDbHelper.StartTime+" < "+cur+" AND (StartTime+Duration) < "+ cur+" AND "+myDbHelper.Status+" =?",whereArgs);
        return count;
    }
    static class myDbHelper extends SQLiteOpenHelper
    {
        private static final String DATABASE_NAME = "MyDB";    // Database Name
        private static final String TABLE_NAME = "MyTable";   // Table Name
        private static final int DATABASE_Version = 1;    // Database Version
        private static final String UID="_id";     // Column I (Primary Key)
        private static final String NAME = "Name";    //Column II
        private static final String Description= "Description";    // Column III
        private static final String StartTime= "StartTime";    // Column IV
        private static final String Duration= "Duration";    // Column V
        private static final String Status= "MyStatus";    // Column VI
        private static final String CREATE_TABLE = "CREATE TABLE "+TABLE_NAME+
                " ("+UID+" INTEGER PRIMARY KEY AUTOINCREMENT, "+NAME+" VARCHAR(50) ,"+Description+" VARCHAR(200) ,"+StartTime+" INT(15) ,"+Duration+" INT(10) ,"+Status+" VARCHAR(12));";
        private static final String DROP_TABLE ="DROP TABLE IF EXISTS "+TABLE_NAME;
        private Context context;

        public myDbHelper(Context context) {
            super(context, DATABASE_NAME, null, DATABASE_Version);
            this.context=context;
        }

        public void onCreate(SQLiteDatabase db) {

            try {
                db.execSQL(CREATE_TABLE);
            } catch (Exception e) {
                Message.message(context,""+e);
            }
        }

        @Override
        public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
            try {
                Message.message(context,"OnUpgrade");
                db.execSQL(DROP_TABLE);
                onCreate(db);
            }catch (Exception e) {
                Message.message(context,""+e);
            }
        }
    }
}