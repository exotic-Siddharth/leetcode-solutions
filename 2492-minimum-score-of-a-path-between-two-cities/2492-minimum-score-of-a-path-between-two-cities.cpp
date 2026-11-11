class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUPar(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    bool unionBySize(int u, int v) {

        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv)
            return false;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }

        return true;
    }
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {

        DisjointSet ds(n);

        // Build DSU
        for (auto &it : roads) {
            ds.unionBySize(it[0], it[1]);
        }

        int par = ds.findUPar(1);

        int ans = INT_MAX;

        // Find minimum edge in the component containing city 1
        for (auto &it : roads) {

            if (ds.findUPar(it[0]) == par) {
                ans = min(ans, it[2]);
            }
        }

        return ans;
    }
};