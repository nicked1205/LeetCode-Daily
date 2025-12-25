class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long res = 0;
        sort(happiness.begin(), happiness.end(), greater<int>());
        for (int i = 0; i < k; i++) {
            int val = happiness[i] - i;
            if (val <= 0) break;
            res += val;
        }

        return res;
    }
};