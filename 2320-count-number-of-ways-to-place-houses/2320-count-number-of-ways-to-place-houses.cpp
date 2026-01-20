class Solution {
public:
    const int MOD = 1e9 + 7;
    long long fib(int n) {
        long long a = 0, b = 1;
        for (int i = 0; i < n; i++) {
            long long c = (a + b) % MOD;
            a = b;
            b = c;
        }
        return a;
    }

    int countHousePlacements(int n) {
        long long waysOneSide = fib(n + 2);
        return (int)(waysOneSide * waysOneSide % MOD);
    }
};