class Solution {
public:
int solve(int i,int j,vector<vector<int>>& matrix,vector<vector<int>> &dp){
     int n=matrix.size();
     int m=matrix[0].size();
   if(j<0 || j >= m) return 1e9;
    if(i == 0)  return matrix[0][j];
    if(dp[i][j]!=INT_MIN) return dp[i][j];
    int up=matrix[i][j]+solve(i-1,j,matrix,dp);
    int diagleft=matrix[i][j]+solve(i-1,j-1,matrix,dp);
    int diagright=matrix[i][j]+solve(i-1,j+1,matrix,dp);
    return dp[i][j]=min({up,diagleft,diagright});
   
}


    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=INT_MAX;
        vector<vector<int>> dp(n,vector<int>(m,INT_MIN));
        for(int i=0;i<m;i++){
             ans=min(ans,solve(n-1,i,matrix,dp));
        }
        return ans;
    }
};