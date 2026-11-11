class Solution {
public:

    int solve(int i,int sum,vector<int>& nums,int target){

        if(i==nums.size())
            return sum==target;

        int plus=solve(i+1,sum+nums[i],nums,target);

        int minus=solve(i+1,sum-nums[i],nums,target);

        return plus+minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        return solve(0,0,nums,target);
    }
};