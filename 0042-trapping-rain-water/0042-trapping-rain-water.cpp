using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;

        int m = height.size();
        if (m == 0) return 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        vector<bool> visited(m, false);
        int highestWall = 0;

        minHeap.push({height[0], 0});
        minHeap.push({height[m - 1], m - 1});

        while (!minHeap.empty()) {
            auto col = minHeap.top();
            minHeap.pop();
            int h = col[0];
            int i = col[1];

            visited[i] = true;
            if (h > highestWall) highestWall = h;

            int ir = i + 1;
            int il = i - 1;

            if (ir <= m - 1 && !visited[ir]) {
                visited[ir] = true;
                if (height[ir] < highestWall) res += highestWall - height[ir];
                minHeap.push({height[ir], ir});
            }

            if (il >= 0 && !visited[il]) {
                visited[il] = true;
                if (height[il] < highestWall) res += highestWall - height[il];
                minHeap.push({height[il], il});
            }
        }
        return res;
    }
};