// class Solution {
// public:
//     int solve(int i, vector<int>& cost, vector<int>& dp){

//         if(i==0) return cost[0];
//         if(i==1) return cost[1];
//         if(dp[i]!=-1) return dp[i];

//         return dp[i] =cost[i] + min(solve(i-1,cost,dp), solve(i-2,cost,dp));
//     }

//     int minCostClimbingStairs(vector<int>& cost) {

//         int n = cost.size();
//         vector<int> dp(n+1,-1);

//         return min(solve(n-1,cost,dp), solve(n-2,cost,dp));
//     }
// };
class Solution {
public:
int solve(int ind,vector<int>& cost, vector<int>& dp){
    if(ind==0 || ind==1) return cost[ind];
     if(dp[ind]!=-1) return dp[ind];
    int first=cost[ind]+solve(ind-1,cost,dp);
    int second=cost[ind]+ solve(ind-2,cost,dp);
    return dp[ind]=min(first,second);
}
 int minCostClimbingStairs(vector<int>& cost) {
    int n=cost.size();
    vector<int> dp(n+1,-1);
    return  min(solve(n-1,cost,dp),solve(n-2,cost,dp));
 }
};