class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        int maxTime = 0;

        minHeap.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        while (!minHeap.empty()) {
            auto top = minHeap.top();
            int h = top[0];
            int x = top[1];
            int y = top[2];
            minHeap.pop();

            if (h > maxTime) maxTime = h;

            if (x ==  n - 1 && y == n - 1) break;

            for (auto dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

                if (visited[nx][ny]) continue;

                visited[nx][ny]= true;
                minHeap.push({grid[nx][ny], nx, ny});
            }
        }

        return maxTime;
    }
};