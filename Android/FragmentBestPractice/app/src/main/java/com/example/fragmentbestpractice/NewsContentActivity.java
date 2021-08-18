package com.example.fragmentbestpractice;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;


public class NewsContentActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_news_content);

        String title = getIntent().getStringExtra("news_title");
        String content = getIntent().getStringExtra("news_content");
        if (title != null && content != null) {
            NewsContentFragment newsContentFragment = (NewsContentFragment) getSupportFragmentManager().
                    findFragmentById(R.id.newsContentFrag);
            newsContentFragment.refresh(title, content);
        }
    }

    public static void actionStart(Context context, String title, String content) {
        Intent intent = new Intent(context, NewsContentActivity.class);
        intent.putExtra("news_title", title);
        intent.putExtra("news_content", content);
        context.startActivity(intent);
    }
}