class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;

        int i = 25;
        string res = "";

        while (i >= 0 && count[i] == 0) i--;

        int time = 0;

        while (i >= 0) {
            if (count[i] == 0) {
                i--;
                time = 0;
                continue;
            }

            while (time < repeatLimit && count[i] > 0) {
                res += char('a' + i);
                count[i]--;
                time++;
            }

            if (count[i] > 0) {
                int j = i - 1;
                while (j >= 0 && count[j] == 0) j--;

                if (j < 0) break;

                res += char('a' + j);
                count[j]--;
                time = 0;
            }
        }

        return res;
    }
};
