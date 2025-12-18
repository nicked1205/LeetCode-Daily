class Solution {
public:
    int hIndex(vector<int>& c) {
        sort(c.begin(), c.end(), greater<int>());

        int i = 0, j = 0;
        while (j < c.size() && c[j] >= j - i + 1) {
            j++;
        }
        return j - i;
    }
};