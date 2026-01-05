class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        for (int i : nums) {
            if (i == 1) continue;
            int sqr = sqrt(i);
            // cout << "sqr = " << sqr << endl;
            if (sqr * sqr == i) continue;
            int sum = 0;
            bool valid = true;
            for (int j = sqr; j > 1; j--) {
                if (i % j == 0) {
                    if (sum == 0) sum += j + i / j;
                    else {
                        valid = false;
                        break;
                    }
                }
            }

            if (valid && sum > 0) res += sum + i + 1;
            // cout << res << endl;
        }

        return res;
    }
};