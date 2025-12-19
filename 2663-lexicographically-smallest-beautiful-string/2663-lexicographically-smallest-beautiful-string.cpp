class Solution {
public:
    string smallestBeautifulString(string s, int k) {
        int n = s.size();
        int i = n - 1;
        while (i >= 0) {
            bool found = false;
            for (char c = s[i] + 1; c < 'a' + k; c++) {
                if ((i >= 1 && c == s[i - 1]) || (i >= 2 && c == s[i - 2]))
                    continue;
                found = true;
                break;
            }
            if (found) break;
            i--;
        }
        if (i == -1) return "";

        for (int j = s[i] + 1; j < k + 'a'; j++) {
            char c = j;
            if (!((i >= 1 && c == s[i - 1]) || (i >= 2 && c == s[i - 2]))) {
                s[i] = c;
                break;
            }
        }
        i++;
        while (i < n) {
            for (int j = 0; j < k; j++) {
                char c = 'a' + j;
                if (!((i >= 1 && c == s[i - 1]) || (i >= 2 && c == s[i - 2]))) {
                    s[i] = c;
                    break;
                }
            }
            i++;
        }
        return s;
    }
};