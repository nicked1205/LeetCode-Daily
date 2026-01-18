class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int i = 0;
        int res = 0;
        while (i < n - 1) {
            int sell = 0;
            while (i < n - 1 && prices[i] > prices[i + 1]) i++;
            sell = prices[i];
            i++;

            while (i < n - 1 && prices[i] < prices[i + 1]) i++;
            if (i < n) res += prices[i] - sell;
            i++;
        }

        return res < 0 ? 0 : res;
    }
};