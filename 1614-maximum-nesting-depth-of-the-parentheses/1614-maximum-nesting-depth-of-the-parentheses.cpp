class Solution {
public:
    int maxDepth(string s) {
        int summ = 0;
        int maxx = 0;
        for (char c : s) {
            if (c == '(') {
                summ++;
                maxx = max(summ, maxx);
            }
            else if (c == ')') summ--;
        }
        return maxx;
    }
};