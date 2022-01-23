class StockPrice {
public:
    StockPrice() = default;

    void update(int timestamp, int price) {
        max_time = max(max_time, timestamp);
        if (time_price.count(timestamp)) {
            int old = time_price[timestamp];
            if (--price_count[old] == 0)
                price_count.erase(old);
        }
        time_price[timestamp] = price;
        ++price_count[price];
    }

    int current() {
        return time_price[max_time];
    }

    int maximum() {
        return price_count.rbegin()->first;
    }

    int minimum() {
        return price_count.begin()->first;
    }

private:
    int max_time = -1;
    unordered_map<int, int> time_price;
    map<int, int> price_count;
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */

