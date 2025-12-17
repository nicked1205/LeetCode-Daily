class Solution {
public:
    int sumInd(int i) {
        int sum = 0;
        while (i != 0) {
            sum += i % 10;
            i/=10;
        }
        return sum;
    }

    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (sumInd(nums[i]) == i) return i;
        }
        return -1;
    }
};