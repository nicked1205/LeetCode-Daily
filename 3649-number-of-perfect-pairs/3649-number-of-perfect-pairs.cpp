class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        vector<long long> a(n);
        for (int i  = 0; i < n; i++) a[i] = llabs(nums[i]);

        sort(a.begin(), a.end());
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < n && a[j] <= 2 * a[i]) j++;
            res += (j - i - 1);
        }
        return res;
    }
};