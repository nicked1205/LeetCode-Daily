class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        int sumL = 0, sumR = 0;
        for (int i = 0; i < n; i++) {
            sumR += nums[i];
        }

        for (int i = 0; i < n - 1; i++) {
            sumR -= nums[i];
            sumL += nums[i];

            if (abs(sumR - sumL) % 2 == 0) res++;
        }

        return res;
    }
};