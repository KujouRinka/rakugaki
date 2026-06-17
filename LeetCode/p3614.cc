class Solution {
public:
  char processStr(const string &s, long long k) {
    int64_t str_length = 0;

    for (auto ch: s) {
      if (ch == '*') {
        // pop
        if (str_length > 0) {
          --str_length;
        }
      } else if (ch == '#') {
        // dup
        str_length *= 2;
      } else if (ch == '%') {
        // reverse
      } else {
        // append
        ++str_length;
      }
    }
    cout << "length: " << str_length << endl;

    char ret = '.';
    for (auto ch : std::views::reverse(s)) {
      if (out_of(str_length, k)) {
        break;
      }

      int64_t next_length = str_length;
      if (ch == '*') {
        // pop
        next_length += 1;
      } else if (ch == '#') {
        // dup
        if (str_length & 1) {
          throw logic_error("unreachable");
        }
        next_length /= 2;
        if (k >= next_length) {
          k -= next_length;
        }
      } else if (ch == '%') {
        k = next_length - k - 1;
      } else {
        next_length -= 1;
        if (out_of(next_length, k)) {
          ret = ch;
          break;
        }
      }

      str_length = next_length;
    }
    return ret;
  }

private:
  static bool out_of(int64_t length, int64_t cur) {
    return cur + 1 > length;
  }
};

