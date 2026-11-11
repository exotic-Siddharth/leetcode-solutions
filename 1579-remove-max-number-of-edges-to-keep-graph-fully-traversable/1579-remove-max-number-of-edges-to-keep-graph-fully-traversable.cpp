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
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    bool unionBySize(int u, int v) {
        u = findUPar(u);
        v = findUPar(v);

        if (u == v)
            return false;

        if (size[u] < size[v])
            swap(u, v);

        parent[v] = u;
        size[u] += size[v];

        return true;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {

        DisjointSet alice(n), bob(n);

        int usedEdges = 0;

        // Process type 3 edges first
        for (auto &it : edges) {

            int type = it[0];
            int u = it[1];
            int v = it[2];

            if (type == 3) {

                bool a = alice.unionBySize(u, v);
                bool b = bob.unionBySize(u, v);

                if (a || b)
                    usedEdges++;
            }
        }

        // Process type 1 edges (Alice)
        for (auto &it : edges) {

            int type = it[0];
            int u = it[1];
            int v = it[2];

            if (type == 1) {

                if (alice.unionBySize(u, v))
                    usedEdges++;
            }
        }

        // Process type 2 edges (Bob)
        for (auto &it : edges) {

            int type = it[0];
            int u = it[1];
            int v = it[2];

            if (type == 2) {

                if (bob.unionBySize(u, v))
                    usedEdges++;
            }
        }

        // Check if Alice's graph is fully connected
        int rootAlice = alice.findUPar(1);
        for (int i = 2; i <= n; i++) {
            if (alice.findUPar(i) != rootAlice)
                return -1;
        }

        // Check if Bob's graph is fully connected
        int rootBob = bob.findUPar(1);
        for (int i = 2; i <= n; i++) {
            if (bob.findUPar(i) != rootBob)
                return -1;
        }

        return edges.size() - usedEdges;
    }
};