class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();

        vector<long long> f(n, 0);

        for (int j = 0; j < m; j++) {
            long long now = f[0];
            for (int i = 1; i < n; i++) {
                now = max(now + skill[i - 1] * mana[j], f[i]);
            }
            f[n - 1] = now + skill[n - 1] * mana[j];

            for (int i = n - 2; i >= 0; i--) {
                f[i] = f[i + 1] - skill[i + 1] * mana[j];
            }
        }

        return f[n - 1];
    }
};