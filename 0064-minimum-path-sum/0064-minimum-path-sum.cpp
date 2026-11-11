class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid,
            vector<vector<int>>& dp) {

        int n = grid.size();
        int m = grid[0].size();

        if (i >= n || j >= m)
            return INT_MAX;

        if (i == n - 1 && j == m - 1)
            return grid[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int right = dfs(i, j + 1, grid, dp);
        int down = dfs(i + 1, j, grid, dp);

        return dp[i][j] = grid[i][j] + min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return dfs(0, 0, grid, dp);
    }
};