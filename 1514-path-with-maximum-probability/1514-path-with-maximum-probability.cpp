class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb,
                          int start_node, int end_node) {

        vector<double> dis(n, 0.0);
        dis[start_node] = 1.0;

        for(int i = 0; i < n - 1; i++) {

            bool updated = false;

            for(int j = 0; j < edges.size(); j++) {

                int u = edges[j][0];
                int v = edges[j][1];
                double prob = succProb[j];

                if(dis[u] > 0 && dis[u] * prob > dis[v]) {
                    dis[v] = dis[u] * prob;
                    updated = true;
                }

                if(dis[v] > 0 && dis[v] * prob > dis[u]) {
                    dis[u] = dis[v] * prob;
                    updated = true;
                }
            }

            if(!updated)
                break;
        }

        return dis[end_node];
    }
};