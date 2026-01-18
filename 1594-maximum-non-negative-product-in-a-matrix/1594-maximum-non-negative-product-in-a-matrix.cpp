class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const int MOD = 1e9 + 7;

        vector<vector<long long>> maxDp(m, vector<long long>(n));
        vector<vector<long long>> minDp(m, vector<long long>(n));

        maxDp[0][0] = minDp[0][0] = grid[0][0];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                long long mx = LLONG_MIN;
                long long mn = LLONG_MAX;

                if (i > 0) {
                    mx = max({mx, maxDp[i-1][j] * grid[i][j], minDp[i-1][j] * grid[i][j]});
                    mn = min({mn, maxDp[i-1][j] * grid[i][j], minDp[i-1][j] * grid[i][j]});
                }
                if (j > 0) {
                    mx = max({mx, maxDp[i][j-1] * grid[i][j], minDp[i][j-1] * grid[i][j]});
                    mn = min({mn, maxDp[i][j-1] * grid[i][j], minDp[i][j-1] * grid[i][j]});
                }

                maxDp[i][j] = mx;
                minDp[i][j] = mn;
            }
        }

        long long res = maxDp[m-1][n-1];
        return res < 0 ? -1 : res % MOD;
    }
};
