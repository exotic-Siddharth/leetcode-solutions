class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
         vector<pair<int,int>> adj[n+1];
         for(auto it: times){
            adj[it[0]].push_back({it[1],it[2]});
            // adj[it[1]].push_back({it[0],it[2]});
         }
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
         vector<int> dis(n+1,1e9);
         dis[k]=0;
         pq.push({0,k});
         while(!pq.empty()){
            int d=pq.top().first;
            int u=pq.top().second;
            pq.pop();
          if(d > dis[u]) continue;
            for(auto it:adj[u]){
                int v=it.first;
                int wt=it.second;
                if(d+wt<dis[v]){
                    dis[v]=d+wt;
                    pq.push({d+wt,v});
                }
            }
         }
        int ans=0;

        for(int i=1;i<=n;i++){

            if(dis[i]==1e9)
                return -1;

            ans=max(ans,dis[i]);
        }

        return ans;
    }
};