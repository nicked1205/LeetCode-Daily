class Solution {
public:
    int findLucky(vector<int>& arr) {
        sort(arr.begin(), arr.end(), greater<int>());
        if (arr.size() == 1) return arr[0] == 1 ? arr[0] : -1;

        int prev = arr[0];
        int count = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] != prev) {
                if (count == arr[i - 1]) return count;
                prev = arr[i];
                count = 1;
            } else {
                count++;
            }
        }
        if (count == arr[arr.size() - 1]) return count;

        return -1;
    }
};