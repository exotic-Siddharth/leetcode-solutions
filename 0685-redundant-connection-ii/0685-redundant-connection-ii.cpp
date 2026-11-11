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
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        vector<int> parent(n + 1, 0);

        vector<int> candidate1;
        vector<int> candidate2;

        // Find node having two parents
        for (auto &edge : edges) {

            int u = edge[0];
            int v = edge[1];

            if (parent[v] == 0) {
                parent[v] = u;
            }
            else {
                candidate1 = {parent[v], v};
                candidate2 = edge;
            }
        }

        // Case 1 : No node has two parents
        if (candidate1.empty()) {

            DisjointSet ds(n);

            for (auto &edge : edges) {

                if (!ds.unionBySize(edge[0], edge[1]))
                    return edge;
            }
        }

        // Case 2 & 3 : Node has two parents
        DisjointSet ds(n);

        for (auto &edge : edges) {

            // Skip second parent edge
            if (edge == candidate2)
                continue;

            if (!ds.unionBySize(edge[0], edge[1]))
                return candidate1;
        }

        return candidate2;
    }
};