class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> cnt;
        for (char c : text) {
            cnt[c]++;
        }

        const vector<char> cs = {'b', 'a', 'l', 'o', 'n'};
        if (cnt[cs[0]] == 0) return 0;

        int res = cnt[cs[0]];
        for (int i = 0; i < 5; i++) {
            if (cnt[cs[i]] == 0) return 0;
            int count = i == 2 || i == 3 ? cnt[cs[i]] / 2 : cnt[cs[i]];
            res = min(res, count);
        }

        return res;
    }
};