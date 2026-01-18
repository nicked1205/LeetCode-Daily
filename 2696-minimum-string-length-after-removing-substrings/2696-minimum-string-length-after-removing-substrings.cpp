class Solution {
public:
    int minLength(string s) {
        vector<char> st;

        for (char c : s) {
            if (st.size() > 0 && c == 'B' && st.back() == 'A') st.pop_back();
            else if (st.size() > 0 && c == 'D' && st.back() == 'C') st.pop_back();
            else st.push_back(c);
        }

        return st.size();
    }
};