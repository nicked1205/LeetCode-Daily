class Solution {
public:
    int n;
    vector<vector<int>> dirs{{0,1},{1,0},{0,-1},{-1,0}};
    vector<int> areas;

    int dfs(vector<vector<int>>& grid, int x, int y, int id) {
        if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] != 1)
            return 0;

        grid[x][y] = id;
        int area = 1;
        for (auto& d : dirs)
            area += dfs(grid, x + d[0], y + d[1], id);

        return area;
    }

    int sumBorders(int x, int y, vector<vector<int>>& grid) {
        int sum = 1;
        int seen[4];
        int k = 0;

        for (auto& d : dirs) {
            int nx = x + d[0];
            int ny = y + d[1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

            int id = grid[nx][ny];
            bool used = false;
            for (int i = 0; i < k; i++) {
                if (seen[i] == id) {
                    used = true;
                    break;
                }
            }
            if (!used) {
                seen[k++] = id;
                sum += areas[id];
            }
        }
        return sum;
    }

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        areas.assign(n * n + 2, 0);

        int id = 2;
        int res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    areas[id] = dfs(grid, i, j, id);
                    res = max(res, areas[id]);
                    id++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    res = max(res, sumBorders(i, j, grid));
                }
            }
        }

        return res;
    }
};
