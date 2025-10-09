class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        int i = 0;
        int steps = 0;
        
        while (i < n) {
            int maxNum = 0;
            int maxNumInd = i;
            for (int j = i + 1; j <= min(n - 1, i + nums[i]); j++) {
                if (j == n - 1) return steps + 1;
                if (nums[j] + j - i > maxNum) {
                    maxNum = nums[j] + j - i;
                    maxNumInd = j;
                }
            }
            steps++;
            i = maxNumInd;
        }

        return -1;
    }
};