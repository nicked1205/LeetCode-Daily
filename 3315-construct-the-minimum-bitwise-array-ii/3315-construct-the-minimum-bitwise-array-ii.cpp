class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (int& n : nums) {
            if (n % 2 == 0) {
                ans.push_back(-1);
            } else {
                int leftmost1 = ((n + 1) & (-n - 1)) / 2;
                ans.push_back(n - leftmost1);
            }
        }
        return ans;
    }
};