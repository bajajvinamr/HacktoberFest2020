package com.aplikasi.alquranque;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.graphics.Bitmap;
import android.os.Bundle;
import android.view.KeyEvent;
import android.view.View;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.ImageView;
import android.widget.ProgressBar;

public class KiblatActivity extends AppCompatActivity {

    WebView webView;
    ProgressBar bar;
    private ImageView backIn;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_kiblat);
        webView = (WebView) findViewById(R.id.webView);
        bar=(ProgressBar) findViewById(R.id.progressBar2);
        webView.setWebViewClient(new KiblatActivity.myWebclient());
        webView.getSettings().setJavaScriptEnabled(true);
        webView.loadUrl("https://qiblafinder.withgoogle.com/");

        //intent
        backIn = (ImageView) findViewById(R.id.backKenK);
        backIn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent back =new Intent(KiblatActivity.this, DashboardActivity.class);
                startActivity(back);
                finish();
            }
        });


    }


    public class myWebclient extends WebViewClient {
        @Override
        public void onPageFinished(WebView view, String url) {
            super.onPageFinished(view, url);
            bar.setVisibility(View.GONE);
        }

        @Override
        public void onPageStarted(WebView view, String url, Bitmap favicon) {
            super.onPageStarted(view, url, favicon);
        }

        @Override
        public boolean shouldOverrideUrlLoading(WebView view, String url) {
            view.loadUrl(url);
            return super.shouldOverrideUrlLoading(view, url);
        }
    }

    @Override
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        if((keyCode==KeyEvent.KEYCODE_BACK) && webView.canGoBack()){
            webView.goBack();
            return true;
        }

        return super.onKeyDown(keyCode, event);
    }
    @Override
    public void onBackPressed() {
        Intent back =new Intent(KiblatActivity.this, DashboardActivity.class);
        startActivity(back);
        finish();
    }
}