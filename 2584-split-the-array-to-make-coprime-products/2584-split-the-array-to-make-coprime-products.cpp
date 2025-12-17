class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        unordered_map<int, int> last;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            for (int p = 2; p * p <= x; p++) {
                if (x % p == 0) {
                    last[p] = i;
                    while (x % p == 0) x /= p;
                }
            }
            if (x > 1) last[x] = i;
        }
        
        int far = 0;
        for (int i = 0; i < n - 1; i++) {
            int x = nums[i];
            for (int p = 2; p * p <= x; p++) {
                if (x % p == 0) {
                    far = max(far, last[p]);
                    while (x % p == 0) x /= p;
                }
            }
            if (x > 1) far = max(far, last[x]);

            if (i == far) return i;
        }

        return -1;
    }
};