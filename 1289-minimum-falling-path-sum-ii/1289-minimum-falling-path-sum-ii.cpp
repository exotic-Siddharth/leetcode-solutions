class Solution {
public:
int solve (int day,int last,vector<vector<int>>& grid, vector<vector<int>> &dp){
     int n=grid.size();
        int m=grid[0].size();
    if(day==0){
        int mn=INT_MAX;
        for(int i=0;i<m;i++){
            if(i!=last) mn=min(mn,grid[day][i]);
        }
        return mn;
    }
    if(dp[day][last]!=-1) return dp[day][last];
    int mn=INT_MAX;
    for(int i=0;i<m;i++){
         if(i!=last){
            int cur=grid[day][i]+solve(day-1,i,grid,dp);
            mn=min(mn,cur);
         }   
    }
     return dp[day][last]=mn;
}
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m+1,-1));
      return  solve(n-1,m,grid,dp);
    }
};