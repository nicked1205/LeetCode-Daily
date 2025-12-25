class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long res = 0;
        sort(happiness.begin(), happiness.end(), greater<int>());
        int dec = 0;
        for (int i = 0; i < k; i++) {
            int val = happiness[i] - dec;
            if (val <= 0) break;
            res += val;
            dec++;
        }

        return res;
    }
};