class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end(), greater<int>());
        int res = 0;
        int i = 1;
        int n = piles.size();
        while (i < n - (i + 1) / 2) {
            res += piles[i];
            i += 2;
        }
        return res;
    }
};