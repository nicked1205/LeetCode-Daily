class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> res;
        long long maxI = nums[0];
        long long preSum = maxI + nums[0];
        res.push_back(preSum);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > maxI) maxI = nums[i];
            preSum += maxI + nums[i];
            res.push_back(preSum);
        }
        return res;
    }
};