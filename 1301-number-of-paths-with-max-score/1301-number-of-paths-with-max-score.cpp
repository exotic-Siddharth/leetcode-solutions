class Solution {
public:
    const int MOD = 1e9 + 7;
    const int NEG = -1e9;

    pair<int,int> solve(int row, int col,vector<string>& board, vector<vector<pair<int,int>>>& dp, vector<vector<int>>& vis) {

        if (row < 0 || col < 0)
            return {NEG, 0};

        if (board[row][col] == 'X')
            return {NEG, 0};

        if (row == 0 && col == 0)
            return {0, 1};

        if (vis[row][col])
            return dp[row][col];

        vis[row][col] = 1;

        pair<int,int> left = solve(row, col-1, board, dp, vis);
        pair<int,int> up = solve(row-1, col, board, dp, vis);
        pair<int,int> diag = solve(row-1, col-1, board, dp, vis);

        int best = max({left.first, up.first, diag.first});

        if (best == NEG)
            return dp[row][col] = {NEG, 0};

        long long ways = 0;

        if (left.first == best) ways += left.second;
        if (up.first == best) ways += up.second;
        if (diag.first == best) ways += diag.second;

        ways %= MOD;

        int val = 0;
        if (board[row][col] != 'S' && board[row][col] != 'E')
            val = board[row][col] - '0';

        return dp[row][col] = {best+val, (int)ways};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {

        int n = board.size();

        vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>>(n));

        vector<vector<int>> vis(n,vector<int>(n, 0));

        pair<int,int> ans = solve(n-1, n-1, board, dp, vis);

        if (ans.first < 0)
            return {0, 0};

        return {ans.first, ans.second};
    }
};