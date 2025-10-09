class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<int> visited;
        int n = arr.size();
        return explore(start, arr, visited, n);
    }

    bool explore(int i, vector<int>& arr, vector<int>& visited, int& n) {
        bool res = false;
        cout << "Exploring " << i << ": " << arr[i] << endl;
        if (arr[i] == 0) return true;
        if (i + arr[i] < n && find(visited.begin(), visited.end(), i + arr[i]) == visited.end()) {
            visited.push_back(i + arr[i]);
            if (explore(i + arr[i], arr, visited, n)) res = true;
        }
        if (i - arr[i] >= 0 && find(visited.begin(), visited.end(), i - arr[i]) == visited.end()) {
            visited.push_back(i - arr[i]);
            if(explore(i - arr[i], arr, visited, n)) res = true;
        }
        cout << res << endl;

        return res;
    }
};