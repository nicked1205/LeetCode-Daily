class Solution {
public:
    int m;
    int n;
    vector<vector<int>> dirs = {{0,1}, {1,0}, {-1,0}, {0,-1}};;
    void dfs(int& area, vector<vector<int>>& grid, int x, int y) {
        if (grid[x][y] == 0) return;

        grid[x][y] = 0;
        area++;
        
        for (auto& dir : dirs) {
            int nx = x + dir[0];
            int ny = y + dir[1];
            if (nx < m && nx >= 0 && ny < n && ny >= 0) dfs(area, grid, nx, ny);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int res = 0;
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                int area = 0;
                dfs(area, grid, x, y);
                res = max(area, res);
            }
        }

        return res;
    }
};