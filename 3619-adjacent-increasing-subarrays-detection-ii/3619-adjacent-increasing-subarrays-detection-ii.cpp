class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> lengths;
        
        int len = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                len++;
            } else {
                lengths.push_back(len);
                len = 1;
            }
        }
        lengths.push_back(len);

        int maxK = 0;
        int maxHalfL = lengths[0] / 2;
        int m = lengths.size();
        for (int i = 1; i < m; i++) {
            maxK = max(maxK, min(lengths[i], lengths[i - 1]));
            maxHalfL = max(maxHalfL, (int)lengths[i] / 2);
        }

        return max(maxK, maxHalfL);
    }
};