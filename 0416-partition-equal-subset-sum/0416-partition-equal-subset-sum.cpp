class Solution {
public:
    int solve(int i, vector<int>& nums, int sum, int target,
              vector<vector<int>>& dp) {

        if (sum == target)
            return true;

        if (i == nums.size() || sum > target)
            return false;

        if (dp[i][sum] != -1)
            return dp[i][sum];

        int pick = solve(i + 1, nums, sum + nums[i], target, dp);

        int nonpick = solve(i + 1, nums, sum, target, dp);

        return dp[i][sum] = pick || nonpick;
    }

    bool canPartition(vector<int>& nums) {

        int totalSum = 0;
        for (int x : nums)
            totalSum += x;

        if (totalSum % 2)
            return false;

        int target = totalSum / 2;

        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));

        return solve(0, nums, 0, target, dp);
    }
};