const char *table = "0123456789abcdef";

class Solution {
public:
    string toHex(int num) {
        uint uNum = num;
        for (int i = 7; i >= 0; --i) {
            char ch = table[(uNum >> (i * 4)) & 0xf];
                vec.push_back(ch);
        }
        auto it = find_if(vec.begin(), vec.end(), [](char ch) -> bool {
            return ch != '0';
        });
        if (it == vec.end())
            return "0";
        return {it, vec.end()};
    }

private:
    vector<char> vec;
};
