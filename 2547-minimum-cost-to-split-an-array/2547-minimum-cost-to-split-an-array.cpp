static int dp[1001];
static constexpr int INF = 1e9;
class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        const int n = nums.size();
        dp[0] = 0;
        for(int i = 0; i < n; ++i){
            int freq[1001] = {0}, length = 0;
            int best = INT_MAX;
            for(int j = i; j >= 0; --j){
                int& f = freq[nums[j]];
                if(f == 1) length += 2;
                else if(f > 1) ++length;
                ++f;
                best = min(best , dp[j] + k + length);
            }
            dp[i + 1] = best;
        }
        return dp[n];
    }
};