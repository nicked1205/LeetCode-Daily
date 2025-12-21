class Solution {
public:
    void deleteColumn(int ind, vector<string>& strs) {
        for (auto& s : strs) s.erase(s.begin() + ind);
    }
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size();
        int n = strs[0].size();
        int res = 0;
        int j = 0;
        while (j < n) {
            bool valid = true;
            for (int i = 1; i < m; i++) {
                if (strs[i][j] < strs[i - 1][j]) {
                    int k = j - 1;
                    while (k >= 0 && strs[i][k] <= strs[i - 1][k]) k--;
                    if (k == -1) {
                        valid = false;
                        res++;
                        break;
                    }
                }
            }
            if (valid) j++;
            else deleteColumn(j, strs);
        }
        return res;
    }
};