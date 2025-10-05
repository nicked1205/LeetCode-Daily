class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        int s = nums.size();

        for (int i = 0; i < s; i++) {
            int l = i + 1;
            int r = s - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                
                if (abs(sum - target) < abs(res - target)) res = sum;

                if (sum == target) return target;
                else if (sum < target) l++;
                else r--;
            }
        }

        return res;
    }
};