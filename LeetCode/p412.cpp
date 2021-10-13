class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> vec;
        vec.reserve(n);
        for (int i = 1; i <= n; ++i) {
            string ss;
            if (i % 3 == 0)
                ss += "Fizz";
            if (i % 5)
                ss += "Buzz";
            if (ss.empty())
                ss = to_string(i);
            vec.push_back(ss);
        }
        return vec;
    }
};
