class Solution {
public:
    int dr[8] = {-1,-1,-1,0,0,1,1,1};
    int dc[8] = {-1,0,1,-1,1,-1,0,1};

    void dfs(vector<vector<char>>& board, int r, int c) {

        int n = board.size();
        int m = board[0].size();

        if (r < 0 || c < 0 || r >= n || c >= m)
            return;

        if (board[r][c] != 'E')
            return;

        int mines = 0;

        for (int k = 0; k < 8; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                board[nr][nc] == 'M')
                mines++;
        }

        if (mines > 0) {
            board[r][c] = mines + '0';
            return;
        }

        board[r][c] = 'B';

        for (int k = 0; k < 8; k++) {
            dfs(board, r + dr[k], c + dc[k]);
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board,
                                     vector<int>& click) {

        int r = click[0];
        int c = click[1];

        if (board[r][c] == 'M') {
            board[r][c] = 'X';
            return board;
        }

        dfs(board, r, c);

        return board;
    }
};