class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);

        // Build max number
        string maxS = s;
        char repMax = 0;
        for (char c : s) {
            if (c != '9') {
                repMax = c;
                break;
            }
        }
        if (repMax) {
            for (char &c : maxS)
                if (c == repMax) c = '9';
        }

        string minS = s;
        char repMin = 0;
        if (s[0] != '1') {
            repMin = s[0];
            for (char &c : minS)
                if (c == repMin) c = '1';
        } else {
            for (int i = 1; i < s.size(); i++) {
                if (s[i] != '0' && s[i] != '1') {
                    repMin = s[i];
                    break;
                }
            }
            if (repMin) {
                for (char &c : minS)
                    if (c == repMin) c = '0';
            }
        }

        return stoi(maxS) - stoi(minS);
    }
};
