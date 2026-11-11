class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        if(start == goal)
            return 0;
        vector<int> vis(1001,0);
        queue<pair<int,int>> q;
        q.push({0,start});
        vis[start] = 1;
        while(!q.empty()){
        int steps=q.front().first;
        int u=q.front().second;
        q.pop();

      for(int i=0;i<nums.size();i++){
        int add=u+nums[i];
        int sub=u-nums[i];
        int xr  = u ^ nums[i];

        if(add==goal || sub==goal || xr==goal) return steps+1;

        if(add>=0 && add<=1000 && !vis[add]){
            vis[add]=1;
            q.push({steps+1,add});
        }
          if(sub>=0 && sub<=1000 && !vis[sub]){
            vis[sub]=1;
            q.push({steps+1,sub});
        }
          if(xr>=0 && xr<=1000 && !vis[xr]){
            vis[xr]=1;
            q.push({steps+1,xr});
        }
      }
        }
        return -1;
    }
};