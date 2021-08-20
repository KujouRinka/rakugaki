class Solution {
    public String reverseStr(String s, int k) {
        int len = s.length();
        char[] chArr = s.toCharArray();

        int left = 0, right = 0;
        for (int i = 0; right < len; ++i) {
            left = 2 * k * i;
            right = 2 * k * i + k - 1;
            reverse(chArr, left, right);
        }
        return String.valueOf(chArr);
    }

    void reverse(char[] chArr, int left, int right) {
        if (right >= chArr.length)
            right = chArr.length - 1;
        while (left < right) {
            char ch = chArr[left];
            chArr[left++] = chArr[right];
            chArr[right--] = ch;
        }
    }
}
