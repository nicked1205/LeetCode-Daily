class Solution {
public:
    int minOperations(string s) {
        const int n = s.size();
        char prev = s[0];
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == prev) {
                cnt++;
                prev = s[i] == '1' ? '0' : '1';
            } else prev = s[i];
        }

        return min(cnt, n - cnt);
    }
};