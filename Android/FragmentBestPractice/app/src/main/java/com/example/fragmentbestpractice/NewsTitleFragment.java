package com.example.fragmentbestpractice;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.Random;


public class NewsTitleFragment extends Fragment {

    private boolean isTwoPane = false;

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.news_title_frag, container, false);
        return view;
    }

    @Override
    public void onActivityCreated(@Nullable Bundle savedInstanceState) {
        super.onActivityCreated(savedInstanceState);
        isTwoPane = getActivity() != null &&
                getActivity().findViewById(R.id.newsContentLayout) != null;
        LinearLayoutManager layoutManager =
                new LinearLayoutManager(getActivity());
        RecyclerView newsTitleRecyclerView = getView().findViewById(R.id.newsTitleRecyclerView);
        newsTitleRecyclerView.setLayoutManager(layoutManager);
        NewsAdapter adapter = new NewsAdapter(getNews());
        newsTitleRecyclerView.setAdapter(adapter);
    }

    private List<News> getNews() {
        ArrayList<News> newsList = new ArrayList<>();
        for (int i = 1; i <= 5; ++i) {
            News news = new News("This is title " + i,
                    getRandomLengthString("This is news content " + i));
            newsList.add(news);
        }
        return newsList;
    }

    private String getRandomLengthString(String content) {
        Random random = new Random();
        int length = random.nextInt(20) + 1;
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < length; ++i) {
            builder.append(content);
        }
        return builder.toString();
    }

    public class NewsAdapter extends RecyclerView.Adapter<NewsAdapter.ViewHolder> {
        private List<News> mNewsList;

        class ViewHolder extends RecyclerView.ViewHolder {
            TextView newsTitleText;

            public ViewHolder(@NonNull View itemView) {
                super(itemView);
                newsTitleText = itemView.findViewById(R.id.newsTitle);
            }
        }

        NewsAdapter(List<News> newsList) {
            mNewsList = newsList;
        }

        @NonNull
        @Override
        public ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
            View view = LayoutInflater.from(parent.getContext())
                    .inflate(R.layout.news_item, parent, false);
            ViewHolder holder = new ViewHolder(view);
            view.setOnClickListener(view1 -> {
                News news = mNewsList.get(holder.getAdapterPosition());
                if (isTwoPane) {
                    NewsContentFragment newsContentFragment =
                            (NewsContentFragment) getParentFragmentManager()
                                    .findFragmentById(R.id.newsContentLayout);
                    if (newsContentFragment != null)
                        newsContentFragment.refresh(news.getTitle(), news.getContent());
                } else {
                    NewsContentActivity.actionStart(parent.getContext(),
                            news.getTitle(), news.getContent());
                }
            });
            return holder;
        }

        @Override
        public void onBindViewHolder(@NonNull ViewHolder holder, int position) {
            News news = mNewsList.get(position);
            holder.newsTitleText.setText(news.getTitle());
        }

        @Override
        public int getItemCount() {
            return mNewsList.size();
        }
    }
}
