class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int j = 0;
        int i = 0;
        int n = nums.size();
        int res = 0;
        while (j < n) {
            while (j < n && nums[j] - nums[i] <= k) j++;
            res++;
            i = j;
        }
        return res;
    }
};