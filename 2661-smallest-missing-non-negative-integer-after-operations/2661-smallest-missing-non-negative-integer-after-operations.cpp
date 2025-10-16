class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int> cnt;
        for (int num : nums) {
            int rem = ((num % value) + value) % value;  // normalize remainder
            cnt[rem]++;
        }

        int minCount = INT_MAX, bestRem = 0;
        for (int r = 0; r < value; r++) {
            int c = cnt.count(r) ? cnt[r] : 0;
            if (c < minCount) {
                minCount = c;
                bestRem = r;
            }
        }
        return minCount * value + bestRem;
    }
};