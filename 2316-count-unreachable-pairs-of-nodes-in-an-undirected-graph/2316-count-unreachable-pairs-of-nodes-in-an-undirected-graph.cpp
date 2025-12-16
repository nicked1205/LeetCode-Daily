class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        vector<long long> sizes;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                long long sz = 0;
                dfs(i, adj, visited, sz);
                sizes.push_back(sz);
            }
        }

        long long res = 0;
        long long sum = 0;
        for (long long s : sizes) {
            res += s * sum;
            sum += s;
        }

        return res;
    }

    void dfs(int u, vector<vector<int>>& adj,
             vector<bool>& visited, long long& sz) {
        visited[u] = true;
        sz++;
        for (int v : adj[u]) {
            if (!visited[v])
                dfs(v, adj, visited, sz);
        }
    }
};
