class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        int n = mountain.size();
        vector<int> peaks;
        int i = 1;
        while (i < n - 1) {
            if (mountain[i] > mountain[i - 1] && mountain[i] > mountain[i + 1]) {
                peaks.push_back(i);
                i += 2;
            } else {
                i++;
            }
        }

        return peaks;
    }
};