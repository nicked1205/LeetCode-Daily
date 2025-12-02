class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int m = points.size();
        unordered_map<int, int> freq;

        freq.reserve(m);

        for (int i = 0; i < m; i++) {
            int y = points[i][1];
            if (freq.find(y) == freq.end()) freq[y] = 1;
            else freq[y] = freq[y] + 1;
        }
        
        if (freq.size() == 1) return 0;

        long long sum = 0, sumSq = 0;

        for (auto& [y, f] : freq) {
            long long n = (f * (f - 1LL)) / 2LL;
            sum += n;
            sumSq += n * n;
        }

        long long res = (sum * sum - sumSq) / 2;

        return res % 1000000007;
    }
};