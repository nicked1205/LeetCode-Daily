class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const long long MOD = 1000000007;
        unordered_map<long long, long long> left, right;
        
        for (int x : nums) right[x]++;

        long long res = 0;
        for (int j = 0; j < nums.size(); j++) {
            right[nums[j]]--;

            long long val = nums[j] * 2LL;

            if (left.count(val) && right.count(val)) {
                res = (res + (left[val] % MOD) * (right[val] % MOD)) % MOD;
            }

            left[nums[j]]++;
        }

        return (int)(res % MOD);
    }
};