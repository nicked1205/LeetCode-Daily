class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        res.reserve(1 << n);
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> subset;
            for (int i = 0; i < n; i++) {
                if ((mask >> i) & 1) subset.push_back(nums[i]);
            }
            res.push_back(subset);
        }
        return res;
    }
};