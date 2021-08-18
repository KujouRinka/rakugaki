package com.example.fragmentbestpractice;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;


public class NewsContentFragment extends Fragment {

    private View view;

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container,
                             @Nullable Bundle savedInstanceState) {
        view = inflater.inflate(R.layout.news_content_frag, container, false);
        return view;
    }

    public void refresh(String newsTitle, String newsContent) {
        LinearLayout linearLayout = view.findViewById(R.id.contentLayout);
        linearLayout.setVisibility(View.VISIBLE);
        ((TextView) linearLayout.findViewById(R.id.newsTitle)).setText(newsTitle);
        ((TextView) linearLayout.findViewById(R.id.newsContent)).setText(newsContent);
    }
}
