class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> freq;
        for (int& i : deck) freq[i]++;

        int res = 0;
        for (auto& [k, v] : freq) {
            res = gcd(res, v);
        }
        return res > 1;
    }
};