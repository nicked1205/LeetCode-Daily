#include <iostream>
using namespace std;

class Solution {
struct Coordinate {
    int x, y;
    
    bool operator==(const Coordinate &other) const {
        return x == other.x && y == other.y;
    }
};

public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (m == 0) return 0;
        int n = heightMap[0].size();
        if (n == 0) return 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            minHeap.push({heightMap[i][0], i, 0});
            minHeap.push({heightMap[i][n-1], i, n-1});
            visited[i][0] = visited[i][n-1] = true;
        }
        for (int j = 1; j < n-1; j++) {
            minHeap.push({heightMap[0][j], 0, j});
            minHeap.push({heightMap[m-1][j], m-1, j});
            visited[0][j] = visited[m-1][j] = true;
        }

        vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

        int trapped = 0;
        int maxBoundary = INT_MIN;

        while (!minHeap.empty()) {
            auto cell = minHeap.top();
            minHeap.pop();
            int h = cell[0], x = cell[1], y = cell[2];

            maxBoundary = max(maxBoundary, h);

            for (auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny]) continue;

                visited[nx][ny] = true;
                if (heightMap[nx][ny] < maxBoundary) {
                    trapped += maxBoundary - heightMap[nx][ny];
                }
                minHeap.push({heightMap[nx][ny], nx, ny});
            }
        }

        return trapped;
    }
};