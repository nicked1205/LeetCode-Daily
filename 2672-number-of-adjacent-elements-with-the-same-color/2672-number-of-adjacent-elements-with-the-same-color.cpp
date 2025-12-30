class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> colors(n, 0);
        vector<int> res;
        int count = 0;
        for (auto& q : queries) {
            int i = q[0];
            int c = q[1];
            if (c == colors[i]) {
                res.push_back(count);
                continue;
            }
            if (i >= 1 && colors[i - 1] != 0 && colors[i - 1] == colors[i]) count--;
            if (i < n - 1 && colors[i + 1] != 0 && colors[i + 1] == colors[i]) count--;
            colors[i] = c;
            if (i >= 1 && colors[i - 1] == c) count++;
            if (i < n - 1 && colors[i + 1] == c) count++;
            res.push_back(count);
        }
        return res;
    }
};