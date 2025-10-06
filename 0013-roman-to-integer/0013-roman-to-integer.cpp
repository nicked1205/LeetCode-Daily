class Solution {
public:
    int romanToInt(string s) {
        int len = s.length();
        int i = 0;
        int res = 0;
        
        while (i < len) {
            auto c = s[i];
            bool spec = false;

            if (c == 'I') {
                if (i + 1 < len && s[i + 1] == 'V') {
                    res += 4;
                    spec = true;
                } else if (i + 1 < len && s[i + 1] == 'X') {
                    res += 9;
                    spec = true;
                } else res += 1;
            } else if (c == 'V') {
                res += 5;
            } else if (c == 'X') {
                if (i + 1 < len && s[i + 1] == 'C') {
                    res += 90;
                    spec = true;
                } else if (i + 1 < len && s[i + 1] == 'L') {
                    res += 40;
                    spec = true;
                } else res += 10;
            } else if (c == 'L') {
                res += 50;
            } else if (c == 'C') {
                if (i + 1 < len && s[i + 1] == 'D') {
                    res += 400;
                    spec = true;
                } else if (i + 1 < len && s[i + 1] == 'M') {
                    res += 900;
                    spec = true;
                } else res += 100;
            } else if (c == 'D') {
                res += 500;
            } else if (c == 'M') {
                res += 1000;
            }

            if (spec) i += 2;
            else i += 1;
        }
        return res;
    }
};