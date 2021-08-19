class Solution {
    public String reverseVowels(String s) {
        char[] chArr = s.toCharArray();
        int len = chArr.length;
        int start = 0, end = len - 1;
        String vowels = "aeiouAEIOU";
        while (start < end) {
            while (start < len && vowels.indexOf(chArr[start]) < 0)
                start++;
            while (end >= 0 && vowels.indexOf(chArr[end]) < 0)
                end--;
            if (start < end) {
                char tmp = chArr[start];
                chArr[start] = chArr[end];
                chArr[end] = tmp;
                start++;
                end--;
            }
        }
        return new String(chArr);
    }
}
