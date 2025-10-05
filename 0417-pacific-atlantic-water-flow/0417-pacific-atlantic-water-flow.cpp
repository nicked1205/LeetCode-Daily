class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        set<vector<int>> atl;
        set<vector<int>> pac;

        int m = heights.size();
        int n = heights[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) {
                    flowInward(heights, pac, i, j);
                }
                if (i == m - 1 || j == n - 1) {
                    flowInward(heights, atl, i, j);
                }
            }
        }

        for (auto coords : pac) {
            if (atl.count(coords)) res.push_back(coords);
        }

        return res;
    }

    void flowInward(vector<vector<int>>& heights, set<vector<int>>& sea, int i, int j) {
        int m = heights.size();
        int n = heights[0].size();

        cout << "Exploring " << i << ", " << j << endl;
        sea.insert({i, j});
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        for (auto dir : directions) {
            int ni = i + dir[0];
            int nj = j + dir[1];

            if (ni < 0 || nj < 0 || ni >= m || nj >= n) continue;

            if (sea.count({ni, nj})) continue;

            if (heights[ni][nj] >= heights[i][j]) {
                flowInward(heights, sea, ni, nj);
            }
        }
    }
};