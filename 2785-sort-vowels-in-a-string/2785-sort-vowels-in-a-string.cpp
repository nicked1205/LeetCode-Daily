class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        vector<int> map;
        vector<int> cs;
        map.reserve(n);
        cs.reserve(n);
        for (int i = 0; i < n; i++) {
            int c = tolower(s[i]);
            if (c == 'a' || c == 'i' || c == 'o' || c == 'e' || c == 'u') {
                map.push_back(i);
                cs.push_back(s[i]);
            }
        }

        sort(cs.begin(), cs.end());
        for (int i = 0; i < cs.size(); i++) s[map[i]] = cs[i];

        return s;
    }
};