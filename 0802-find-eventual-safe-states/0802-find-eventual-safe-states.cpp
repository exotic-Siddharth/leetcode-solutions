class Solution {
private:

    bool dfs(int node,
             vector<vector<int>>& graph,
             vector<int>& vis,
             vector<int>& pathVis){

        vis[node] = 1;
        pathVis[node] = 1;

        for(auto adjNode : graph[node]){

            if(!vis[adjNode]){

                if(dfs(adjNode,graph,vis,pathVis))
                    return true;
            }

            else if(pathVis[adjNode]){

                return true;
            }
        }

        pathVis[node] = 0;
        // check[node] = 1;      // safe

        return false;
    }

public:

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int V = graph.size();

        vector<int> vis(V,0);
        vector<int> pathVis(V,0);
        // vector<int> check(V,0);

        for(int i=0;i<V;i++){

            if(!vis[i]){

                dfs(i,graph,vis,pathVis);
            }
        }

        vector<int> ans;

        for(int i=0;i<V;i++){

            if(pathVis[i] == 0)
                ans.push_back(i);
        }

        return ans;
    }
};