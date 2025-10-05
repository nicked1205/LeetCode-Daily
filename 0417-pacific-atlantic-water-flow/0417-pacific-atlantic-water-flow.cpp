class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));
        
        queue<pair<int,int>> pacQ, atlQ;
        
        for (int i = 0; i < m; i++) {
            pacQ.push({i, 0});
            pac[i][0] = true;
        }
        for (int j = 0; j < n; j++) {
            pacQ.push({0, j});
            pac[0][j] = true;
        }
        
        for (int i = 0; i < m; i++) {
            atlQ.push({i, n-1});
            atl[i][n-1] = true;
        }
        for (int j = 0; j < n; j++) {
            atlQ.push({m-1, j});
            atl[m-1][j] = true;
        }
        
        bfs(heights, pacQ, pac);
        bfs(heights, atlQ, atl);
        
        vector<vector<int>> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pac[i][j] && atl[i][j])
                    res.push_back({i, j});
            }
        }
        return res;
    }

private:
    void bfs(vector<vector<int>>& heights, queue<pair<int,int>>& q, vector<vector<bool>>& vis) {
        int m = heights.size(), n = heights[0].size();
        vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            for (auto [di, dj] : dirs) {
                int ni = i + di, nj = j + dj;
                if (ni < 0 || nj < 0 || ni >= m || nj >= n) continue;
                if (vis[ni][nj]) continue;
                if (heights[ni][nj] >= heights[i][j]) {
                    vis[ni][nj] = true;
                    q.push({ni, nj});
                }
            }
        }
    }
};
