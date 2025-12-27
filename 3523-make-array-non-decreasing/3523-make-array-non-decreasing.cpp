class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        vector<int> st;
        for (int n : nums) {
            if (st.size() == 0 || (st.size() > 0 && n >= st.back())) st.push_back(n);
        }

        return st.size();
    }
};