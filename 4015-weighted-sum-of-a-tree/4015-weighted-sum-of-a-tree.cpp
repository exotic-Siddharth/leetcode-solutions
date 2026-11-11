class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n=parent.size();
        
        vector<vector<int>> adj(n);
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
        vector<int> depth(n);
        depth[0]=1;
        int h=1;
       function<void(int,int)> dfs=[&](int node,int d){
           depth[node]=d;
           h=max(h,d);

           for(int child:adj[node]) dfs(child,d+1);
       };
        dfs(0,1);
        long long ans=0;
        for(int i=0;i<n;i++){
            long long weight=1LL*nums[i]*(h-depth[i]+1);
            ans+=weight;
        }
        return ans;
    }
};