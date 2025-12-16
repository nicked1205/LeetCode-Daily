class Solution {
public:
    vector<int> parent, size;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;

        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        size.assign(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (auto& e : edges)
            unite(e[0], e[1]);

        long long res = 0, seen = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
                res += (long long)size[i] * seen;
                seen += size[i];
            }
        }
        return res;
    }
};
