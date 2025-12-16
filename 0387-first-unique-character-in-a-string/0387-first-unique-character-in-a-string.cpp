class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> count;
        unordered_map<char, int> firstPos;

        for (int i = 0; i < s.size(); i++) {
            count[s[i]]++;
            if (!firstPos.count(s[i])) {
                firstPos[s[i]] = i;
            }
        }

        int ans = INT_MAX;
        for (auto& [c, cnt] : count) {
            if (cnt == 1) {
                ans = min(ans, firstPos[c]);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};