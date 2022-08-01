class Solution {
 public:
  string generateTheString(int n) {
    string s;
		s.reserve(n);
		if (n % 4 == 0) {
		} else if ((n - 1) % 4 == 0) {
			s.append(1, 'c');
		} else if ((n - 2) % 4 == 0) {
			s.append(1, 'c');
			s.append(1, 'd');
		} else {  // (n - 3) % 4 == 0
			s.append(1, 'c');
			s.append(1, 'd');
			s.append(1, 'e');
		}
    fill4n(s, n / 4);
		return s;
  }

 private:
	void fill4n(string &s, int n) {
		if (n == 0)
			return;
		s.append(n * 2 - 1, 'a');
		s.append(n * 2 + 1, 'b');
	}
};

