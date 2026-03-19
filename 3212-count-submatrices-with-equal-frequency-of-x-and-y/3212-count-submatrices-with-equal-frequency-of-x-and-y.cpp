class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        vector<vector<vector<int>>> cnt(m, vector<vector<int>>(n, vector<int>(2, 0)));
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c = grid[i][j];
                if (c == 'X') cnt[i][j][0]++;
                else if (c == 'Y') cnt[i][j][1]++;
                if (i != 0) {
                    cnt[i][j][0] += cnt[i - 1][j][0];
                    cnt[i][j][1] += cnt[i - 1][j][1];
                }
                if (j != 0) {
                    cnt[i][j][0] += cnt[i][j - 1][0];
                    cnt[i][j][1] += cnt[i][j - 1][1];
                }
                if (i != 0 && j != 0) {
                    cnt[i][j][0] -= cnt[i - 1][j - 1][0];
                    cnt[i][j][1] -= cnt[i - 1][j - 1][1];
                }

                // cout << cnt[i][j][0] << "X, " << cnt[i][j][1] << "Y at " << i << ", " << j << endl;
                if (cnt[i][j][0] > 0 && cnt[i][j][0] == cnt[i][j][1]) res++;
            }
        }
        return res;
    }
};