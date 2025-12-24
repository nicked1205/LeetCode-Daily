class Solution {
public:
    vector<int> disc, low;
    vector<vector<int>> res;
    int time = 0;

    void dfs(int u, int parent, const vector<vector<int>>& adj) {
        disc[u] = low[u] = ++time;

        for (int v : adj[u]) {
            if (v == parent) continue;

            if (disc[v] == 0) {
                dfs(v, u, adj);
                low[u] = min(low[u], low[v]);

                if (low[v] > disc[u]) {
                    res.push_back({u, v});
                }
            } else {
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        disc.assign(n, 0);
        low.assign(n, 0);

        for (auto& c : connections) {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }

        for (int i = 0; i < n; i++) {
            if (disc[i] == 0) {
                dfs(i, -1, adj);
            }
        }

        return res;
    }
};
