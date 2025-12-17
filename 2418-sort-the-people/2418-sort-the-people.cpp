class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<tuple<int, string>> pairs;
        for (int i = 0; i < n; i++) {
            pairs.push_back(make_tuple(heights[i], names[i]));
        }

        sort(pairs.begin(), pairs.end(), [](tuple<int, string>& a, tuple<int, string>& b) {return get<0>(a) > get<0>(b);});
        
        vector<string> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = get<1>(pairs[i]);
        }
        return res;
    }
};