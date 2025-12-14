class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;
        int n = nums.size();
        
        int i = 0;
        int zeros = 0;
        while (i < n) {
            if (nums[i] == 0) {
                zeros++;
            } else {
                res += (zeros * (zeros + 1LL)) / 2LL;
                zeros = 0;
            }

            i++;
        }

        res += (zeros * (zeros + 1LL)) / 2LL;

        return res;
    }
};