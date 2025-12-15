class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        int prev = nums[0];
        res.push_back({prev});
        int count = 1;
        for (int i = 1; i < n; i++) {
            // cout << i << " = " << nums[i] << endl;
            if (nums[i] != prev) {
                // cout << "Diff" << endl;
                res[0].push_back(nums[i]);
                count = 1;
            } else {
                // cout << "Same" << endl;
                if (count >= res.size()) res.push_back({});
                res[count].push_back(nums[i]);
                count++;
            }
            prev = nums[i];
        }

        return res;
    }
};