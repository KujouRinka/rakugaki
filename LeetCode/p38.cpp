class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        return splitCount(countAndSay(n - 1));
    }

private:
    static string splitCount(string s) {
        string return_s;
        auto front = s.begin();
        auto back = s.begin();
        while (back != s.end()) {
            int same_count = 0;
            while (back != s.end() && *back == *front) {
                ++same_count;
                ++back;
            }
            return_s += to_string(same_count);
            return_s += *front;
            front = back;
            same_count = 0;
        }
        return return_s;
    }
};
