class Solution {
public:
    bool checkOnesSegment(string s) {
        const int n = s.size();
        int i = 0;
        bool found1 = false;

        while (s[i] == '1') i++;

        while (i < n) {
            if (s[i] == '0') i++;
            else return false;
        }

        return true;
    }
};