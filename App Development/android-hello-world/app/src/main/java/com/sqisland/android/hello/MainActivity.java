package com.sqisland.android.hello;

import android.app.Activity;
import android.os.Bundle;

public class MainActivity extends Activity {
  @Override
  protected void onCreate(Bundle savedInstanceState) {
    //system.out.log .............. kya hota tha bc bhool gaya, java me kaise krte the HEllo World
    super.onCreate(savedInstanceState);
    setContentView(R.layout.activity_main);
  }
}
