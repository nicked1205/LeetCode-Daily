class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> seen;
        int n = s.length();
        queue<string> q;
        q.push(s);
        seen.insert(s);
        string ans = s;

        while (!q.empty()) {
            auto str = q.front();
            q.pop();
            string cop = str;

            if (str < ans) ans = str;
            
            add(cop, a, n);
            if (seen.find(cop) == seen.end()) {
                q.push(cop);
                seen.insert(cop);
            }
            
            string cop2 = str;
            rotate(cop2, b, n);
            if (seen.find(cop2) == seen.end()) {
                q.push(cop2);
                seen.insert(cop2);
            }
        }
        return ans;
    }

    inline void add(string& s, int a, int n) {
        for (int i = 1; i < n; i+=2) {
            s[i] = (char)((s[i] + a - 48) % 10 + 48);
        }
    }

    inline void rotate(string& s, int b, int n) {
        reverse(s.begin(), s.begin() + n - b);
        reverse(s.begin() + n - b, s.end());
        reverse(s.begin(), s.end());
    }
};