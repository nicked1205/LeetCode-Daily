class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combinations;
        vector<int> path;
        int n = candidates.size();
        dfs(combinations, candidates, target, 0, path);

        return combinations;
    }

    void dfs(vector<vector<int>>& combinations, vector<int>& candidates, int target, int index, vector<int>& path) {
        if (target == 0) {
            combinations.push_back(path);
            return;
        }
        else if (target < 0) return;
        for (int i = index; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            dfs(combinations, candidates, target - candidates[i], i, path);
            path.pop_back();
        }
    }
};