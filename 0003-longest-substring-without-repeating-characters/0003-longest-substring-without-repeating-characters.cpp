class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0) return 0;
        int i = 0, j = 1, max = 0;
        while (j < n) {
            for (int k = j - 1; k >= i; k--) {
                if (s[j] == s[k]) {
                    if (j - i > max) max = j - i;
                    i = k + 1;
                    break;
                }
            }
            j++;
        }
        if (j - i > max) max = j - i;
        return max;
    }
};