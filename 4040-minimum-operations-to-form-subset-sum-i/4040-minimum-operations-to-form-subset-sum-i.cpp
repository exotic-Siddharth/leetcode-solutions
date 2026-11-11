class Solution {
public:
   
    int solve(int ind,int target,int cost,vector<int>& nums,  vector<vector<int>>& dp){
        if(target==0) return cost;
        
        if(ind==nums.size()|| target<0) return 1e9;
      
       
        if(dp[ind][target]!=-1) return cost+dp[ind][target];
        int best=1e9;
        
       best= solve(ind+1,target,cost,nums,dp);
        int x=nums[ind];
        int val=x;
        int op=0;
        while(val<=target){
           best=min(best, solve(ind+1,target-val,cost+op,nums,dp));
            if(val>target/2) break;
            val*=2;
            op++;
        }
        val=x;
        op=0;
        while(val>0){
            val/=2;
            op++;
            if(val==0) break;
          if(val<=target)  best=min(best,solve(ind+1,target-val,cost+op,nums,dp));
        }
        dp[ind][target]=best-cost;
        return best;
        
    }
    int minOperations(vector<int>& nums, int sum) {
        int n=nums.size();
        
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
       int ans= solve(0,sum,0,nums,dp);
        return ans>=1e9?-1:ans;
    }
};