class Solution {
private:

    bool dfs(int row, int col,
             int parentRow, int parentCol,
             vector<vector<char>>& grid,
             vector<vector<int>>& vis){

        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        for(int i=0;i<4;i++){

            int nr = row + delrow[i];
            int nc = col + delcol[i];

            if(nr>=0 && nr<n &&
               nc>=0 && nc<m &&
               grid[nr][nc] == grid[row][col]){

                if(!vis[nr][nc]){

                    if(dfs(nr,nc,row,col,grid,vis))
                        return true;
                }

                else if(nr != parentRow ||
                        nc != parentCol){

                    return true;
                }
            }
        }

        return false;
    }

public:

    bool containsCycle(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                if(!vis[i][j]){

                    if(dfs(i,j,-1,-1,grid,vis))
                        return true;
                }
            }
        }

        return false;
    }
};