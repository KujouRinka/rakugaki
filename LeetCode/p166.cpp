struct pairHash {
    template<typename T, typename U>
    size_t operator()(const pair<T, U> &i) const {
        return hash<T>()(i.first) ^ hash<U>()(i.second);
    }
};

class Solution {
public:
    string fractionToDecimal(int64_t numerator, int64_t denominator) {
        int flag = 1;
        if (numerator < 0)
            flag *= -1;
        if (denominator < 0)
            flag *= -1;

        unordered_map<pair<int, int>, int, pairHash> see;
        int64_t quotient = numerator / denominator;
        int64_t remainder = numerator % denominator;
        if (remainder == 0)
            return to_string(numerator / denominator);

        string decimalString(flag == 1 ? "" : "-");
        cout << quotient << endl;
        decimalString += to_string(abs(quotient));
        decimalString.reserve(10);

        remainder = abs(remainder);
        denominator = abs(denominator);

        decimalString.push_back('.');

        int pos = decimalString.size();
        while (remainder != 0) {
            remainder *= 10;
            quotient = remainder / denominator;
            remainder %= denominator;
            if (see.count({quotient, remainder}))
                break;
            see.insert({{quotient, remainder}, pos++});
            decimalString.push_back(quotient + '0');
        }
        if (remainder == 0)
            return decimalString;
        decimalString.insert(decimalString.begin() + see[{quotient, remainder}], '(');
        decimalString.push_back(')');
        return decimalString;
    }
};
