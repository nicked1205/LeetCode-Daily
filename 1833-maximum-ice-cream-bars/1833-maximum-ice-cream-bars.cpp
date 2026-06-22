class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        const int n = costs.size();

        int maxx = 0;
        for (int i : costs) {
            maxx = max(maxx, i);
        }

        vector<int> cnt(maxx, 0);
        for (int i : costs) {
            cnt[i - 1]++;
        }

        for (int i = 1; i < cnt.size(); i++) {
            cnt[i] = cnt[i - 1] + cnt[i];
        }

        // for (int i : cnt) cout << i << " ";
        // cout << endl;

        vector<int> sorted(n);
        for (int i = n - 1; i >= 0; i--) {
            sorted[cnt[costs[i] - 1] - 1] = costs[i];
            cnt[costs[i] - 1]--;
        }

        // for (int i : sorted) cout << i << " ";
        // cout << endl;

        int summ = 0;
        int res = 0;
        while (res < n && summ + sorted[res] <= coins) {
            summ += sorted[res];
            res++;
        }

        return res;
    }
};