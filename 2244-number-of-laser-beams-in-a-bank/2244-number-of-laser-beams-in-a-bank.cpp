class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank.size();
        int n = bank[0].size();
        int ans = 0;
        vector<int> tots;
        for (int i = 0; i < m; i++) tots.push_back(totalDevices(bank, i, n));

        int i = 0;
        int j = 1;
        while (j < m) {
            int tot = tots[j];
            if (tot == 0) {
                j++;
                continue;
            }
            else {
                ans += tot * tots[i];
                i = j;
                j = j + 1;
            }
        }

        return ans;
    }

    int totalDevices(vector<string>& bank, int row, int n) {
        int devices = 0;
        for (int i = 0; i < n; i++) {
            if (bank[row][i] == '1') devices++;
        }
        return devices;
    }
};