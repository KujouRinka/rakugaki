class Solution {
public:
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs) {
        initSpecial(price, special);
        search(0, special, needs, 0);
        return min_price;
    }

private:
    int min_price = 0x7fffffff;

    static void initSpecial(vector<int> &price, vector<vector<int>> &special) {
        auto sz_p = price.size();
        vector<int> v(sz_p + 1);
        for (int i = 0; i < sz_p; ++i) {
            if (i > 0)
                v[i - 1] = 0;
            v[i] = 1;
            v[sz_p] = price[i];
            special.push_back(v);
        }
    }

    void search(int sp_ind, vector<vector<int>> &special, vector<int> &needs, int sum) {
        if (sp_ind == special.size()) {
            if (sum < min_price && fullNeeds(needs))
                min_price = sum;
            return;
        }
        bool f = true;
        vector<int> &sp_unit = special[sp_ind];
        for (int sp_count = 0; f; ++sp_count) {
            vector<int> needs_copy(needs);
            for (int j = 0; j < needs_copy.size(); ++j) {
                if (needs_copy[j] < sp_unit[j] * sp_count) {
                    f = false;
                    break;
                }
                needs_copy[j] -= sp_unit[j] * sp_count;
            }
            if (f)
                search(sp_ind + 1, special, needs_copy, sum + sp_unit[needs.size()] * sp_count);
        }
    }

    static bool fullNeeds(const vector<int> &needs) {
        for (int i: needs) {
            if (i != 0)
                return false;
        }
        return true;
    }
};
