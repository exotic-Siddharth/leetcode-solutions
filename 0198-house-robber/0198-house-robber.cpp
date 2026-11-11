class Solution {
public:
int find(int ind, vector<int>& dp,vector<int>& nums){
    if(ind==0) return nums[ind];
    if(ind<0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int pick=nums[ind]+find(ind-2,dp,nums);
    int notpick=find(ind-1,dp,nums);
    return dp[ind]=max(pick,notpick);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return find(n-1,dp,nums);
    }
};