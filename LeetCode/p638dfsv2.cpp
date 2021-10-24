class Solution {
public:
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs) {
        this->price = price;
        this->special = special;
        sz = price.size();
        initSpecial();
        search(0, needs, 0);
        return min_price;
    }

private:
    int min_price = 0x7fffffff;
    vector<int> price;
    vector<vector<int>> special;
    int sz;

    void initSpecial() {
        vector<int> v(sz + 1);
        for (int i = 0; i < sz; ++i) {
            if (i > 0)
                v[i - 1] = 0;
            v[i] = 1;
            v[sz] = price[i];
            special.push_back(v);
        }
    }

    void search(int sp_ind, vector<int> &needs, int sum) {
        if (sum >= min_price)
            return;

        bool fn = fullNeeds(needs);
        if (fn) {
            min_price = min(min_price, sum);
            return;
        }

        if (sp_ind == special.size())
            return;

        vector<int> &sp_unit = special[sp_ind];
        for (int sp_count = 0; ; ++sp_count) {
            if (check(sp_unit, needs, sp_count)) {
                for (int i = 0; i < sz; ++i)
                    needs[i] -= sp_unit[i] * sp_count;
                search(sp_ind + 1, needs, sum + sp_unit.back() * sp_count);
                for (int i = 0; i < sz; ++i)
                    needs[i] += sp_unit[i] * sp_count;
            } else {
                break;
            }
        }
    }

    static inline bool fullNeeds(const vector<int> &needs) {
        return accumulate(needs.begin(), needs.end(), 0) == 0;
    }

    bool check(const vector<int> &sp, const vector<int> &needs, int fac) {
        for (int i = 0; i < sz; ++i) {
            if (needs[i] < sp[i] * fac)
                return false;
        }
        return true;
    }
};
