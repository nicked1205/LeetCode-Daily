class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            int j = 0;
            while (j < n && grid[i][j] >= 0) j++;
            res += n - j;
        }

        return res;
    }
};