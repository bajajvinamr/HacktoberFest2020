package com.jainvidushi.remapp;

import android.app.Activity;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import org.w3c.dom.Text;

import static android.R.id.text1;
import static android.icu.lang.UCharacter.GraphemeClusterBreak.V;

public class DeleteActivity extends AppCompatActivity {
    int pgn = 1;
    String alltask;
    String tasklist[] = new String[100];
    String totalrec = "";
    TextView Totalr,page;
    Button next, prev;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_delete);
        Totalr = (TextView) findViewById(R.id.trec);
        next = (Button) findViewById(R.id.n);
        prev = (Button) findViewById(R.id.p);
        page = (TextView) findViewById(R.id.pg);
    }

    public void menu_nav(View view) {
        Intent i = new Intent(this, Menu_NavActivity.class);
        startActivity(i);
    }
    public void complete(View view) {
        call();
        dbmanag helper;
        helper = new dbmanag(this);
        alltask = helper.gettasklist("COMPLETE");
        tasklist = alltask.split("@");
        totalrec = tasklist[0];
        page.setText(Integer.toString(pgn));
        Totalr.setText(totalrec);
        totalpg = (int) (Math.ceil((Integer.parseInt(totalrec) / 10)));
        if ((Integer.parseInt(totalrec)) > 10) {
            next.setVisibility(View.VISIBLE);
        }
        int[] textViews = {R.id.t1, R.id.t2, R.id.t3, R.id.t4, R.id.t5, R.id.t6, R.id.t7, R.id.t8, R.id.t9, R.id.t10};
        int[] textViews1 = {R.id.c1, R.id.c2, R.id.c3, R.id.c4, R.id.c5, R.id.c6, R.id.c7, R.id.c8, R.id.c9, R.id.c10};
        int[] but = {R.id.b1, R.id.b2, R.id.b3, R.id.b4, R.id.b5, R.id.b6, R.id.b7, R.id.b8, R.id.b9, R.id.b10};
        if ((Integer.parseInt(totalrec)) > 10) {
            startrec = (pgn - 1) * 10;
            endrec = pgn * 10;
        } else {
            startrec = 0;
            endrec = Integer.parseInt(totalrec);
        }
        for (int i = startrec; i < endrec; i++) {
            String b[] = new String[2];
            b = tasklist[i + 1].split("/");
            TextView tv = (TextView) findViewById(textViews[i]);
            TextView tv1 = (TextView) findViewById(textViews1[i]);
            Button butt=(Button) findViewById(but[i]);
            tv.setText(b[1]);
            tv1.setText(b[0]);
            butt.setVisibility(View.VISIBLE);
        }
    }
    int startrec, endrec, totalpg;
    public void actives(View view) {
        call();
        dbmanag helper = new dbmanag(this);
        alltask = helper.gettasklist("ACTIVE");
        tasklist = alltask.split("@");
        totalrec = tasklist[0];
        page.setText(Integer.toString(pgn));
        Totalr.setText(totalrec);
        totalpg = (int) (Math.ceil((Integer.parseInt(totalrec) / 10)));
        if ((Integer.parseInt(totalrec)) > 10) {
            next.setVisibility(View.VISIBLE);
        }
        int[] textViews = {R.id.t1, R.id.t2, R.id.t3, R.id.t4, R.id.t5, R.id.t6, R.id.t7, R.id.t8, R.id.t9, R.id.t10};
        int[] textViews1 = {R.id.c1, R.id.c2, R.id.c3, R.id.c4, R.id.c5, R.id.c6, R.id.c7, R.id.c8, R.id.c9, R.id.c10};
        int[] but = {R.id.b1, R.id.b2, R.id.b3, R.id.b4, R.id.b5, R.id.b6, R.id.b7, R.id.b8, R.id.b9, R.id.b10};
        if ((Integer.parseInt(totalrec)) > 10) {
            startrec = (pgn - 1) * 10;
            endrec = pgn * 10;
        } else {
            startrec = 0;
            endrec = Integer.parseInt(totalrec);
        }
        for (int i = startrec; i < endrec; i++) {
            String b[] = new String[2];
            b = tasklist[i + 1].split("/");
            TextView tv = (TextView) findViewById(textViews[i]);
            TextView tv1 = (TextView) findViewById(textViews1[i]);
            Button butt=(Button) findViewById(but[i]);
            tv.setText(b[1]);
            tv1.setText(b[0]);
            butt.setVisibility(View.VISIBLE);
        }

    }
    public void v1(View view) {
        TextView id1;
        id1 = (TextView) findViewById(R.id.c1);
        Intent i = new Intent(getApplicationContext(), Sub_Delete_Activity.class);
        i.putExtra("MyID", id1.getText());
        startActivity(i);
    }

    public void v2(View view) {
        TextView id2;
        id2 = (TextView) findViewById(R.id.c2);
        Intent i = new Intent(getApplicationContext(), Sub_Delete_Activity.class);
        i.putExtra("MyID", id2.getText());
        startActivity(i);
    }

    public void v3(View view) {
        TextView id3;
        id3 = (TextView) findViewById(R.id.c3);
        Intent i = new Intent(getApplicationContext(), Sub_Delete_Activity.class);
        i.putExtra("MyID", id3.getText());
        startActivity(i);
    }

    public void v4(View view) {
        TextView id4;
        id4 = (TextView) findViewById(R.id.c4);
        Intent i = new Intent(getApplicationContext(), Sub_Delete_Activity.class);
        i.putExtra("MyID", id4.getText());
        startActivity(i);
    }

    public void v5(View view) {
        TextView id5;
        id5 = (TextView) findViewById(R.id.c5);
        Intent i = new Intent(getApplicationContext(), Sub_Delete_Activity.class);
        i.putExtra("MyID", id5.getText());
        startActivity(i);
    }

    public void v6(View view) {
        TextView id6;
        id6 = (TextView) findViewById(R.id.c6);
        Intent i = new Intent(getApplicationContext(), Sub_Delete_Activity.class);
        i.putExtra("MyID", id6.getText());
        startActivity(i);
    }

    public void v7(View view) {
        TextView id7;
        id7 = (TextView) findViewById(R.id.c7);
        Intent i = new Intent(getApplicationContext(), Sub_Delete_Activity.class);
        i.putExtra("MyID", id7.getText());
        startActivity(i);
    }

    public void v8(View view) {
        TextView id8;
        id8 = (TextView) findViewById(R.id.c8);
        Intent i = new Intent(getApplicationContext(), Sub_Delete_Activity.class);
        i.putExtra("MyID", id8.getText());
        startActivity(i);
    }

    public void v9(View view) {
        TextView id9;
        id9 = (TextView) findViewById(R.id.c9);
        Intent i = new Intent(getApplicationContext(), Sub_Delete_Activity.class);
        i.putExtra("MyID", id9.getText());
        startActivity(i);
    }

    public void v10(View view) {
        TextView id10;
        id10 = (TextView) findViewById(R.id.c10);
        Intent i = new Intent(getApplicationContext(), Sub_Delete_Activity.class);
        i.putExtra("MyID", id10.getText());
        startActivity(i);
    }
    public void nclick(View view) {
        prev.setVisibility(View.VISIBLE);
        pgn = pgn + 1;
        page.setText(Integer.toString(pgn));
        if (totalpg <= pgn) {
            next.setVisibility(View.INVISIBLE);
        }
        int[] textViews = {R.id.t1, R.id.t2, R.id.t3, R.id.t4, R.id.t5, R.id.t6, R.id.t7, R.id.t8, R.id.t9, R.id.t10};
        int[] textViews1 = {R.id.c1, R.id.c2, R.id.c3, R.id.c4, R.id.c5, R.id.c6, R.id.c7, R.id.c8, R.id.c9, R.id.c10};
        int[] but = {R.id.b1, R.id.b2, R.id.b3, R.id.b4, R.id.b5, R.id.b6, R.id.b7, R.id.b8, R.id.b9, R.id.b10};
        for (int i=0;i<10;i++)
        {
            TextView tv2 = (TextView) findViewById(textViews[i]);
            TextView tv3 = (TextView) findViewById(textViews1[i]);
            Button butt=(Button) findViewById(but[i]);
            butt.setVisibility(View.INVISIBLE);
            tv2.setText("");
            tv3.setText("");
        }
        if ((Integer.parseInt(totalrec)) > (pgn * 10)) {
            startrec = (pgn - 1) * 10;
            endrec = pgn * 10;
        } else {
            startrec = (pgn - 1) * 10;
            endrec = Integer.parseInt(totalrec);
        }
        for (int i = startrec,j=0; i < endrec; i++,j++) {
            String b[] = new String[2];
            b = tasklist[i + 1].split("/");
            TextView tv = (TextView) findViewById(textViews[j]);
            TextView tv1 = (TextView) findViewById(textViews1[j]);
            Button butt=(Button) findViewById(but[j]);
            butt.setVisibility(View.VISIBLE);
            tv.setText(b[1]);
            tv1.setText(b[0]);
        }
    }
    public void pclick(View view)
    {
        pgn=pgn-1;
        page.setText(Integer.toString(pgn));
        if (pgn==1)
        {
            prev.setVisibility(View.INVISIBLE);
        }
        next.setVisibility(View.VISIBLE);
        int[] textViews = {R.id.t1, R.id.t2, R.id.t3, R.id.t4, R.id.t5, R.id.t6, R.id.t7, R.id.t8, R.id.t9, R.id.t10};
        int[] textViews1 = {R.id.c1, R.id.c2, R.id.c3, R.id.c4, R.id.c5, R.id.c6, R.id.c7, R.id.c8, R.id.c9, R.id.c10};
        int[] but = {R.id.b1, R.id.b2, R.id.b3, R.id.b4, R.id.b5, R.id.b6, R.id.b7, R.id.b8, R.id.b9, R.id.b10};
        for (int i=0;i<10;i++)
        {
            TextView tv2 = (TextView) findViewById(textViews[i]);
            TextView tv3 = (TextView) findViewById(textViews1[i]);
            Button butt=(Button) findViewById(but[i]);
            butt.setVisibility(View.INVISIBLE);
            tv2.setText("");
            tv3.setText("");
        }
        if ((Integer.parseInt(totalrec)) > (pgn * 10)) {
            startrec = (pgn - 1) * 10;
            endrec = pgn * 10;
        } else {
            startrec = (pgn - 1) * 10;
            endrec = Integer.parseInt(totalrec);
        }
        for (int i = startrec,j=0; i < endrec; i++,j++) {
            String b[] = new String[2];
            b = tasklist[i + 1].split("/");
            TextView tv = (TextView) findViewById(textViews[j]);
            TextView tv1 = (TextView) findViewById(textViews1[j]);
            Button butt=(Button) findViewById(but[j]);
            butt.setVisibility(View.VISIBLE);
            tv.setText(b[1]);
            tv1.setText(b[0]);
        }
    }
    public void call()
    {
        int[] textViews = {R.id.t1, R.id.t2, R.id.t3, R.id.t4, R.id.t5, R.id.t6, R.id.t7, R.id.t8, R.id.t9, R.id.t10};
        int[] textViews1 = {R.id.c1, R.id.c2, R.id.c3, R.id.c4, R.id.c5, R.id.c6, R.id.c7, R.id.c8, R.id.c9, R.id.c10};
        int[] but = {R.id.b1, R.id.b2, R.id.b3, R.id.b4, R.id.b5, R.id.b6, R.id.b7, R.id.b8, R.id.b9, R.id.b10};
        for (int i=0;i<10;i++)
        {
            TextView tv2 = (TextView) findViewById(textViews[i]);
            TextView tv3 = (TextView) findViewById(textViews1[i]);
            Button butt=(Button) findViewById(but[i]);
            butt.setVisibility(View.INVISIBLE);
            tv2.setText("");
            tv3.setText("");
        }
    }
}






