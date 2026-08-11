class Solution {
public:
    int missingInteger(vector<int>& nums) {
        const int n = nums.size();
        if (n == 1) return nums[0] + 1;

        int i = 1;
        int presum = nums[0];
        while (i < n && nums[i] == nums[i - 1] + 1) {
            presum += nums[i];
            i++;
        }

        while (find(nums.begin(), nums.end(), presum) != nums.end()) {
            presum++;
        }

        return presum;
    }
};