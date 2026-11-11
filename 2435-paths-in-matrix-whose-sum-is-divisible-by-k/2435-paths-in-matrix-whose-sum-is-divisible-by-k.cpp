class Solution {
public:
    const int MOD = 1e9 + 7;

    int dfs(int i, int j, int rem, vector<vector<int>>& grid, int k,
            vector<vector<vector<int>>>& dp) {

        int m = grid.size();
        int n = grid[0].size();

        rem = (rem + grid[i][j]) % k;

        if (i == m - 1 && j == n - 1)
            return rem == 0;

        if (dp[i][j][rem] != -1)
            return dp[i][j][rem];

        long long ans = 0;

        if (i + 1 < m)
            ans = (ans + dfs(i + 1, j, rem, grid, k, dp)) % MOD;

        if (j + 1 < n)
            ans = (ans + dfs(i, j + 1, rem, grid, k, dp)) % MOD;

        return dp[i][j][rem] = ans;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(k, -1)));

        return dfs(0, 0, 0, grid, k, dp);
    }
};