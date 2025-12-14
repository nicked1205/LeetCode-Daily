class Solution {
public:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    int lcm(int a, int b) {
        return a / gcd(a, b) * b;
    }

    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;

        for (int i = 0; i < n; i++) {
            int curLCM = 1;
            for (int j = i; j < n; j++) {
                curLCM = lcm(curLCM, nums[j]);

                if (curLCM == k) res++;
                if (curLCM > k || k % curLCM != 0) break;
            }
        }

        return res;
    }
};