class Solution {
public:

    void dfs(int row, int col,
             vector<vector<int>>& image,
             int oldColor,
             int newColor,
             int delRow[],
             int delCol[]) {

        image[row][col] = newColor;

        int n = image.size();
        int m = image[0].size();

        for(int i = 0; i < 4; i++) {

            int nr = row + delRow[i];
            int nc = col + delCol[i];

            if(nr >= 0 && nr < n &&
               nc >= 0 && nc < m &&
               image[nr][nc] == oldColor) {

                dfs(nr, nc, image,
                    oldColor, newColor,
                    delRow, delCol);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr,
                                  int sc,
                                  int color) {

        int oldColor = image[sr][sc];

        if(oldColor == color)
            return image;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        dfs(sr, sc, image,
            oldColor, color,
            delRow, delCol);

        return image;
    }
};