class Solution {
public:
    int maxDepth(string s) {
        int summ = 0;
        int maxx = 0;
        for (char c : s) {
            if (c == '(') summ++;
            else if (c == ')') summ--;
            maxx = max(summ, maxx);
        }
        return maxx;
    }
};