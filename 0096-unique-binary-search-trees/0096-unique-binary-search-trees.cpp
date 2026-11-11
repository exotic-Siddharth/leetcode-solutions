class Solution {
public:

    int solve(int n,vector<int>& dp) {

        if (n <= 1)
            return 1;
         int ans = 0;
         if(dp[n]!=-1) return dp[n];
        for (int root = 1; root <= n; root++) {

            int left = solve(root - 1,dp);
            int right = solve(n - root,dp);

            ans += left * right;
        }

        return dp[n]=ans;
    }

    int numTrees(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};