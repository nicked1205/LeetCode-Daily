class Solution {
public:
    long long maxGCDScore(vector<int>& nums, int k) {
        int n = nums.size();
        long long res = 0;
        for (int i = 0; i < n; i++) {
            long long gCd = nums[i], count = 0, min_pow = 1000000002;
            for (int j = i; j < n; j++) {
                gCd = gcd(gCd, nums[j]);
                int pow = nums[j] & -nums[j];
                if (pow < min_pow) {
                    min_pow = pow, count = 1;
                } else if (pow == min_pow) {
                    count++;
                }
                long long cur = gCd * ((count <= k) ? 2 : 1) * (j - i + 1);
                res = max(res, cur);
            }
        }
        return res;
    }
};