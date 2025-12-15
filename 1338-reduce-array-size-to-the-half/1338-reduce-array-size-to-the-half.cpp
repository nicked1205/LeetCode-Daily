class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        vector<int> freq;
        int i = 1;
        int prev = 0;
        sort(arr.begin(), arr.end());
        while (i < n) {
            if (arr[i] != arr[prev]) {
                freq.push_back(i - prev);
                prev = i;
            }
            i++;
        }
        freq.push_back(i - prev);

        int m = freq.size();
        if (m == 1) return 1;
        sort(freq.begin(), freq.end(), greater<int>());

        int sum = 0;
        for (int i = 0; i < m; i++) {
            // cout << freq[i] << " ";
            sum += freq[i];
            // cout << i << ", " << sum << endl;
            if (sum >= n / 2) return i + 1;
        }

        return 0;
    }
};