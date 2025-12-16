class Solution {
public:
    struct Fenwick {
        int n;
        vector<long long> bit;

        Fenwick(int n) : n(n), bit(n + 1, 0) {}

        void add(int i, long long v) {
            for (; i <= n; i += i & -i)
                bit[i] += v;
        }

        void range_add(int l, int r, long long v) {
            add(l, v);
            add(r + 1, -v);
        }

        long long query(int i) {
            long long s = 0;
            for (; i > 0; i -= i & -i)
                s += bit[i];
            return s;
        }
    };

    vector<vector<pair<int,int>>> g;
    vector<int> parent, tin, tout;
    vector<long long> baseDist;
    int timer = 0;

    void dfs(int u, int p, long long d) {
        parent[u] = p;
        baseDist[u] = d;
        tin[u] = ++timer;
        for (auto &[v, w] : g[u]) {
            if (v == p) continue;
            dfs(v, u, d + w);
        }
        tout[u] = timer;
    }

    vector<int> treeQueries(
        int n,
        vector<vector<int>>& edges,
        vector<vector<int>>& queries
    ) {
        g.assign(n, {});
        for (auto &e : edges) {
            int u = e[0] - 1;
            int v = e[1] - 1;
            int w = e[2];
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }

        parent.resize(n);
        tin.resize(n);
        tout.resize(n);
        baseDist.resize(n);

        dfs(0, -1, 0);

        Fenwick fw(n);

        map<pair<int,int>, int> weight;
        for (auto &e : edges) {
            int u = e[0] - 1;
            int v = e[1] - 1;
            int w = e[2];
            if (parent[v] == u) weight[{u, v}] = w;
            else weight[{v, u}] = w;
        }

        vector<int> ans;

        for (auto &q : queries) {
            if (q[0] == 1) {
                int u = q[1] - 1;
                int v = q[2] - 1;
                int nw = q[3];

                if (parent[v] != u) swap(u, v);

                int old = weight[{u, v}];
                long long delta = nw - old;
                weight[{u, v}] = nw;

                fw.range_add(tin[v], tout[v], delta);
            } else {
                int u = q[1] - 1;
                long long res = baseDist[u] + fw.query(tin[u]);
                ans.push_back((int)res);
            }
        }

        return ans;
    }
};
