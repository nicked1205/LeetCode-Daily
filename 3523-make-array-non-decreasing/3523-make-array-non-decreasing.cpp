class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int res = 0;
        int pre = 0;
        for (int n : nums) {
            if (n >= pre) {
                pre = n;
                res++;
            }
        }

        return res;
    }
};