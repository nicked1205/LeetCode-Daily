class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        vector<int> temp(k, 0);
        for (int i = 0; i < k / 2; i++) {
            for (int b = y; b < y + k; b++) {
                temp[b - y] = grid[x + i][b];
                grid[x + i][b] = grid[x + k - 1 - i][b];
                grid[x + k - 1 - i][b] = temp[b - y];
                // cout << temp[b - y] << " ";
            }
            // cout << endl;
        }

        return grid;
    }
};