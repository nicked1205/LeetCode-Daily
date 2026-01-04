class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long res = 0;
        vector<long long> count(24, 0);
        for (int h : hours) count[h % 24]++;
        res += (count[0] * (count[0] - 1)) / 2;
        res += (count[12] * (count[12] - 1)) / 2;
        for (int i = 1; i <= 11; i++) {
            res += count[i] * count[24 - i];
        }
        return res;
    }
};