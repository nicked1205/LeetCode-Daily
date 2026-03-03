class Solution {
private:
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    void find(vector<vector<int>> &mat, vector<int>& res) {
        int max = 0;
        const int m = mat.size();
        const int n = mat[0].size();
        while (true) {
            int maxDirI = -1;
            for (int i = 0; i < 4; i++) {
                int nx = res[0] + dirs[i][0];
                int ny = res[1] + dirs[i][1];
                if (nx >= m || nx < 0 || ny >= n || ny < 0) continue;

                if (mat[nx][ny] > max) {
                    max = mat[nx][ny];
                    maxDirI = i;
                }
            }

            // cout << res[0] << ", " << res[1] << endl;
            // cout << max << endl;
            // cout << maxDirI << endl;

            if (maxDirI == -1) break;

            res[0] += dirs[maxDirI][0];
            res[1] += dirs[maxDirI][1];
        }
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        vector<int> res = {0, 0};
        find(mat, res);

        return res;
    }
};