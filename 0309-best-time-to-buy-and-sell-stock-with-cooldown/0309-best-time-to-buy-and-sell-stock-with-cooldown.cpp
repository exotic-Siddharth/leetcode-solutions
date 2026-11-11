class Solution {
public:
long solve(int i,int buy,vector<int>& prices,vector<vector<long>> &dp){
    int n=prices.size();
    if(i>=n) return 0;
   if(dp[i][buy]!=-1) return dp[i][buy];
  if(buy==1) return dp[i][buy]=max(-prices[i]+solve(i+1,0,prices,dp),solve(i+1,1,prices,dp));
  return dp[i][buy]=max(prices[i]+solve(i+2,1,prices,dp),solve(i+1,0,prices,dp));
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
       vector<vector<long>>dp(n,vector<long>(2,-1));
        return solve(0,1,prices,dp);
    }
};