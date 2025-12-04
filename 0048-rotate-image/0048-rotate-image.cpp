class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int start = 0;
        for (int k = n - 1; k > 0; k-=2) {
            for (int i = start; i < k + start; i++) {
                swap(matrix, start, i, n - 1 - i, start);
                swap(matrix, n - 1 - i, start, n - 1 - start,  n - 1 - i);
                swap(matrix, n - 1 - start, n - 1 - i, i, n - 1 - start);
            }
            start++;
        }
    }

    void swap(vector<vector<int>>& matrix, int x1, int y1, int x2, int y2) {
        int temp = matrix[x1][y1];
        matrix[x1][y1] = matrix[x2][y2];
        matrix[x2][y2] = temp;
    }
};