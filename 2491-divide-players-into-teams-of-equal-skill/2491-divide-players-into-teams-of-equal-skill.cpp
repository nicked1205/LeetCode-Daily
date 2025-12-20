class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int n = skill.size();
        int i = 0;
        long long res = 0;
        int sum = skill[0] + skill[n - 1];
        while (i < n / 2) {
            if (sum != skill[i] + skill[n - i - 1]) return -1;
            sum = skill[i] + skill[n - i - 1];
            res += skill[i] * skill[n - i - 1];
            i++;
        }
        return res;
    }
};