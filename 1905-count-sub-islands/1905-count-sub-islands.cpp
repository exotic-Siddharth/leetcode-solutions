class Solution {
public:

    bool dfs(int row, int col,
             vector<vector<int>>& grid1,
             vector<vector<int>>& grid2) {

        int n = grid2.size();
        int m = grid2[0].size();

        grid2[row][col] = 0;

        bool valid = true;

        if(grid1[row][col] == 0)
            valid = false;

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        for(int i=0;i<4;i++){

            int nr = row + delrow[i];
            int nc = col + delcol[i];

            if(nr>=0 && nr<n &&
               nc>=0 && nc<m &&
               grid2[nr][nc] == 1){

                valid = dfs(nr,nc,grid1,grid2) && valid;
            }
        }

        return valid;
    }

    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {

        int n = grid2.size();
        int m = grid2[0].size();

        int cnt = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid2[i][j] == 1){

                    if(dfs(i,j,grid1,grid2))
                        cnt++;
                }
            }
        }

        return cnt;
    }
};