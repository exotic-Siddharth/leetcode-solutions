class DisjointSet{
    public:
    vector<int>parent,size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<n;i++) parent[i]=i;
    }
         int findUpar(int node){
            if(node==parent[node]) return node;
            return parent[node]=findUpar(parent[node]);
         }

         void unionBySize(int u,int v){
            int ulp_u=findUpar(u);
            int ulp_v=findUpar(v);

            if( ulp_u== ulp_v) return;

            if(size[ulp_u]<size[ulp_v]){
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }
            else {
                 parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extraedge=0;
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            if(ds.findUpar(u)==ds.findUpar(v)) extraedge++;
           ds.unionBySize(u,v);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(ds.findUpar(i)==i) cnt++;
        }
        if(extraedge>=cnt-1) return cnt-1;
        return -1;
    }
};