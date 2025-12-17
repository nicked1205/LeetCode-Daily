class Solution {
public:
    bool isPrime(int x) {
        for (int d = 2; d * d <= x; d++) {
            if (x % d == 0)
                return false;
        }
        return x >= 2;
    }

    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>> res;
        for (int x = 1; x <= n/2; x++) {
            if (isPrime(x) && isPrime(n - x)) res.push_back({x, n - x});
        }
        return res;
    }
};