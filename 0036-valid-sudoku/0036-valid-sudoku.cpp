class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col) {

        char c = board[row][col];
        board[row][col] = '.';

        for (int i = 0; i < 9; i++) {
            if (board[row][i] == c ||
                board[i][col] == c ||
                board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) {

                board[row][col] = c;
                return false;
            }
        }

        board[row][col] = c;
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (board[i][j] != '.') {
                    if (!isSafe(board, i, j))
                        return false;
                }
            }
        }

        return true;
    }
};