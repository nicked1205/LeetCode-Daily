class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt = 0;
        int maxx = 0;
        for (int g : gain) {
            alt += g;
            maxx = max(maxx, alt);
        }

        return maxx;
    }
};