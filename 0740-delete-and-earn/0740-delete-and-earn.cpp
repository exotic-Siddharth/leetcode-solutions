class Solution {
public:
int solve(int ind,vector<int>& points,vector<int>& dp){
    if(ind==0) return points[0];
    if(ind<0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int pick=points[ind]+solve(ind-2,points,dp);
    int nonpick=solve(ind-1,points,dp);
    return dp[ind]=max(pick,nonpick);

}
    int deleteAndEarn(vector<int>& nums) {
       int mx = *max_element(nums.begin(), nums.end());
       vector<int> points(mx+1,0);
       for(auto x:nums) points[x]+=x;
       vector<int> dp(mx+2,-1);
       return solve(mx,points,dp);
    }
};