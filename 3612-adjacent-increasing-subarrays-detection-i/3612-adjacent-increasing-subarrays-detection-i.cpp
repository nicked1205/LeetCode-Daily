class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2 * k) return false;
        if (k == 1) return true;

        vector<int> inc(n, 1);
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) 
                inc[i] = inc[i - 1] + 1;
        }

        for (int i = 0; i <= n - 2 * k; i++) {
            if (inc[i + k - 1] >= k && inc[i + 2 * k - 1] >= k)
                return true;
        }
        return false;
    }
};