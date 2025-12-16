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

        unordered_map<int, long long> comp;
        for (int i = 0; i < n; i++)
            comp[find(i)]++;

        long long res = 0, seen = 0;
        for (auto& [_, s] : comp) {
            res += s * seen;
            seen += s;
        }

        return res;
    }
};
