namespace std {
    template<>
    struct hash<pair<int64_t, int64_t>> {
        typedef size_t result_type;
        typedef pair<int64_t, int64_t> argument_type;
        size_t operator()(const argument_type &p) const;
    };

    size_t hash<pair<int64_t, int64_t>>::operator()(const argument_type &p) const {
        return hash<int64_t>()(p.first) ^ hash<int64_t>()(p.second);
    }
}

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
