class Solution {
public:
    int compareVersion(string version1, string version2) {
        auto len1 = version1.size(), len2 = version2.size();
        int p1 = 0, p2 = 0;
        int t1 = 0, t2 = 0;
        while (p1 < len1 || p2 < len2) {
            t1 = 0;
            for (; p1 < len1 && version1[p1] != '.'; ++p1) {
                t1 *= 10;
                t1 += version1[p1] - '0';
            }
            p1++;

            t2 = 0;
            for (; p2 < len2 && version2[p2] != '.'; ++p2) {
                t2 *= 10;
                t2 += version2[p2] - '0';
            }
            p2++;

            if (t1 != t2)
                return t1 > t2 ? 1 : -1;
        }
        return 0;
    }
};
