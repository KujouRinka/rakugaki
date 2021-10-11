class Solution {
public:
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";
        vector<int> unit;
        unit.reserve(4);
        while (num != 0) {
            int tmp = num % 1000;
            num /= 1000;
            unit.push_back(tmp);
        }

        string result;
        for (int i = 3; i >= 0; --i) {
            if (i < unit.size() && unit[i] != 0)
                result += threeNumberDecode(unit[i]) + " " + sec[i];
        }
        result.resize(result.size() - 1);
        return result;
    }

private:
    static vector<string> low;
    static vector<string> mid;
    static vector<string> high;
    static vector<string> sec;
    static string threeNumberDecode(int i) {
        int a, b, c;
        a = i / 100;
        b = i % 100 / 10;
        c = i % 10;
        string t;
        t.reserve(20);
        if (i == 0) {
            return t;
        } else if (i < 10) {
            t += low[c];
        } else if (i < 20) {
            t += mid[c];
        } else if (i < 100) {
            t += high[b] + (low[c].empty() ? "" : " ") + low[c];
        } else {
            string tt = threeNumberDecode(i % 100);
            t += low[a] + " Hundred" + (tt.empty() ? "" : " ") + tt;
        }
        return t;
    }
};

vector<string> Solution::low = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
vector<string> Solution::mid = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
                                "Eighteen", "Nineteen"};
vector<string> Solution::high = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
vector<string> Solution::sec = {"", "Thousand ", "Million ", "Billion "};
