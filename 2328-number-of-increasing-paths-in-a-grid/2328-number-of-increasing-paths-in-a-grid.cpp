class Solution {
public:
    const int MOD = 1e9 + 7;
    int m, n;

    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (dp[i][j] != -1)
            return dp[i][j];

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        long long paths = 1;

        for (int k = 0; k < 4; k++) {
            int nr = i + dr[k];
            int nc = j + dc[k];

            if (nr >= 0 && nr < m &&
                nc >= 0 && nc < n &&
                grid[nr][nc] > grid[i][j]) {

                paths = (paths + dfs(nr, nc, grid, dp)) % MOD;
            }
        }

        return dp[i][j] = paths;
    }

    int countPaths(vector<vector<int>>&grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        long long ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = (ans + dfs(i, j, grid, dp)) % MOD;
            }
        }

        return ans;
    }
};