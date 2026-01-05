class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int minn = 1e5;
        int negCount = 0;
        bool zero = false;
        for (auto& r : matrix) {
            for (int i : r) {
                if (i < 0) negCount++;
                if (i == 0) zero = true;
                minn = min(abs(i), minn);
                sum += abs(i);
            }
        }

        if (negCount % 2 == 1 && !zero) sum -= minn * 2;
        return sum;
    }
};