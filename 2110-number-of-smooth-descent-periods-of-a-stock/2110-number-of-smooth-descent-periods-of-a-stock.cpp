class Solution {
public:
    long long getDescentPeriods(vector<int>& p) {
        int n = p.size();
        long long res = 0;
        long long period = 1;
        int i = 1;
        while (i < n) {
            if (p[i - 1] - p[i] == 1) {
                period++;
            } else {
                res += (period *(period + 1)) / 2;
                period = 1;
            }
            i++;
        }
        res += (period *(period + 1)) / 2;
        return res;
    }
};