class Solution {
public:
    int solve(int target,
              vector<int>& nums,
              vector<int>& dp) {

        if (target == 0)
            return 1;

        if (target < 0)
            return 0;

        if (dp[target] != -1)
            return dp[target];

        long long ways = 0;

        for (int num : nums) {
            ways += solve(target - num, nums, dp);
        }

        return dp[target] = ways;
    }

    int combinationSum4(vector<int>& nums, int target) {

        vector<int> dp(target + 1, -1);

        return solve(target, nums, dp);
    }
};