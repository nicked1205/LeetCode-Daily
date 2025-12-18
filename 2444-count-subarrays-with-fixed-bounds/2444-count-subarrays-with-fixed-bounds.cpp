class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long j = 1;
        long long maI = nums[0] == maxK ? 0 : -1;
        long long miI = nums[0] == minK ? 0 : -1;
        long long start = (nums[0] > maxK || nums[0] < minK) ? 0 : -1;
        long long res = (minK == maxK && miI == 0) ? 1 : 0;
        while (j < nums.size()) {
            int b = nums[j];
            if (b < minK || b > maxK) {
                start = j;
            }
            if (b == minK) {
                miI = j;
            }
            if (b == maxK) {
                maI = j;
            }
            if (miI >= 0 && maI >= 0 && start < miI && start < maI) res += min(miI, maI) - start;
            j++;
        }

        return res;
    }
};