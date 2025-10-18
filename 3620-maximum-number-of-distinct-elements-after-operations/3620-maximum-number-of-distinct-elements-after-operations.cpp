#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        long long current = LLONG_MIN;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long left = (long long)nums[i] - k;
            long long right = (long long)nums[i] + k;


            if (current < left) {
                current = left;
            }

            if (current <= right) {
                ans++;
                current++;
            }
        }

        return ans;
    }
};
