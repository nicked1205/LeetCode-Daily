class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        const int n = nums.size();

        for (int i = 0; i < 1 << n; i++) {
            string s = "";
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) s+="1";
                else s+="0";
            }
            if (find(nums.begin(), nums.end(), s) == nums.end()) return s;
        }

        return "";
    }
};