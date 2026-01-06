class Solution {
public:
    void bfs(vector<vector<int>>& adj, int i, int& minn) {
        int n = adj.size();
        vector<int> parent(n, -1);
        vector<int> distance(n, -1);
        queue<int> q;
        q.push(i);
        distance[i] = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (distance[v] != -1) {
                    if (parent[u] != v) minn = min(minn, distance[v] + distance[u] - 1);
                    continue;    
                }

                q.push(v);

                distance[v] = distance[u] + 1;
                parent[v] = u;
            }
        }
    }

    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        int minn = 1e9;
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        for (int i = 0; i < n; i++) {
            bfs(adj, i, minn);
        }

        return minn == 1e9 ? -1 : minn;
    }
};