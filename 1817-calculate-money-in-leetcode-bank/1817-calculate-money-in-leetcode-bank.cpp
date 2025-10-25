class Solution {
public:
    int totalMoney(int n) {
        int res = n / 7;
        int rem = n % 7;
        int ans = 0;

        int i = 1;
        while (i <= res) {
            ans += (7 * 8) / 2;
            ans += (i - 1) * 7;
            i++;
        }
        for (int j = 1; j <= rem; j++) ans += i - 1 + j;

        return ans;
    }
};