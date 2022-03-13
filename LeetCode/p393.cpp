class Solution {
    enum : uint8_t {
        ONE = 0,
        TWO = 0xc0,
        THREE = 0xe0,
        FOUR = 0xf0,
        PREF = 0x80,
    };

public:
    bool validUtf8(const vector<int> &data) {
        auto sz = data.size();
        bool stat = true;
        for (int p = 0; stat && p < sz;) {
            auto d = static_cast<uint8_t>(data[p]);
            if (eq(d & mask(7), ONE)) {
                ++p;
            } else if (eq(d & mask(5), TWO)) {
                if (sz - p < 2) {
                    stat = false;
                    break;
                }
                if (preEq(data[p + 1]))
                    p += 2;
                else
                    stat = false;
            } else if (eq(d & mask(4), THREE)) {
                if (sz - p < 3) {
                    stat = false;
                    break;
                }
                if (preEq(data[p + 1]) && preEq(data[p + 2]))
                    p += 3;
                else
                    stat = false;
            } else if (eq(d & mask(3), FOUR)) {
                if (sz - p < 4) {
                    stat = false;
                    break;
                }
                if (preEq(data[p + 1]) && preEq(data[p + 2]) && preEq(data[p + 3]))
                    p += 4;
                else
                    stat = false;
            } else {
                stat = false;
            }
        }
        return stat;
    }

private:
    static inline uint8_t mask(int i) {
        return ~((1 << i) - 1);
    }

    static inline bool eq(uint8_t a, uint8_t b) {
        return (a ^ b) == 0;
    }

    static inline bool preEq(uint8_t a) {
        return eq(a & mask(6), PREF);
    }
};

