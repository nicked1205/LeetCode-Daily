class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<long long, long long> cnt;
        vector<long long> vals;
        vals.reserve(power.size());
        for (int p : power) {
            if (++cnt[p] == 1) vals.push_back(p);
        }

        sort(vals.begin(), vals.end());
        int m = (int)vals.size();

        vector<long long> gain(m);
        vector<int> next_idx(m);
        for (int i = 0; i < m; i++) {
            gain[i] = vals[i] * cnt[vals[i]];
            long long ban_to = vals[i] + 2;
            int j = int(upper_bound(vals.begin(), vals.end(), ban_to) - vals.begin());
            next_idx[i] = j;
        }

        vector<long long> dp(m + 1, 0);
        for (int i = m - 1; i >= 0; i--) {
            long long skip = dp[i + 1];
            long long take = gain[i] + dp[next_idx[i]];
            dp[i] = max(skip, take);
        }
        return dp[0];
    }
};
