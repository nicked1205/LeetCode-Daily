class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i = 0;
        int j = 0;
        const int m = firstList.size();
        const int n = secondList.size();
        vector<vector<int>> res = {};
        while (i < m && j < n) {
            int a_start = firstList[i][0], a_end = firstList[i][1];
            int b_start = secondList[j][0], b_end = secondList[j][1];
            if (a_start <= b_end && b_start <= a_end) {
                res.push_back({max(a_start, b_start), min(a_end, b_end)});
            }

            if (a_end <= b_end) i++;
            else j++;
        }
        return res;
    }
};