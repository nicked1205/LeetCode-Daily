class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 1;
        int maxFreq = 0;
        sort(nums.begin(), nums.end());
        long long sum = 0;
        while (j <= n) {
            if (sum <= k) {
                if (j - i > maxFreq) maxFreq = j - i;
                if (j < n) sum += 1LL * (nums[j] - nums[j - 1]) * (j - i);
                j++;
            }
            else {
                sum -= nums[j - 1] - nums[i];
                i++;
            }
        }

        return maxFreq;
    }
};