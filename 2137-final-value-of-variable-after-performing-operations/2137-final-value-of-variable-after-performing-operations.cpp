class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int n = operations.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            auto op = operations[i];
            if (op == "++X" || op == "X++") ans++;
            if (op == "--X" || op == "X--") ans--;
        }

        return ans;
    }
};