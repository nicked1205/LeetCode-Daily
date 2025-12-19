class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        if (n == 2) return max(arr[0], arr[1]);
        int winner = 0;
        int matches = 0;
        int cons = 0;
        while (matches + 1 < n) {
            // cout << winner << ": " << arr[winner] << ", " << matches + 1 << ": " << arr[matches + 1] << endl;
            if (arr[winner] > arr[matches + 1]) {
                cons++;
            } else {
                winner = matches + 1;
                cons = 1;
            }
            if (cons >= k) return arr[winner];
            matches++;
        }
        return arr[winner];
    }
};