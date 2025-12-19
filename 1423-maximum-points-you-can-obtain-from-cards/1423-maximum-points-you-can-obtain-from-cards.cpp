class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int i = n - k;
        int j = n - 1;
        int it = 1;
        int sum = 0;
        for (int l = i; l <= j; l++) sum += cardPoints[l];
        int res = sum;
        while (it < k + 1) {
            sum -= cardPoints[(i + it - 1) % n];
            sum += cardPoints[(j + it) % n];
            res = max(res, sum);
            it++;
        }
        return res;
    }
};