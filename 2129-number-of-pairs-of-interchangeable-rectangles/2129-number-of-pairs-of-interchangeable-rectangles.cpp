class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<string, long long> count;
        long long res = 0;

        for (auto& rect : rectangles) {
            int w = rect[0], h = rect[1];
            int g = gcd(w, h);
            string ratio = to_string(w / g) + "/" + to_string(h / g);

            res += count[ratio];
            count[ratio]++;
        }

        return res;
    }
};