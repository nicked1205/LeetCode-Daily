class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;
        long long res1 = 6;
        long long res2 = 6;
        for (int i = 2; i <= n; i++) {
            int oldr1 = res1;
            res1 = (res1 * 2 + res2 * 2) % MOD;
            res2 = (oldr1 * 2 + res2 * 3) % MOD;
        }
        return (int)((res1 + res2) % MOD);
    }
};