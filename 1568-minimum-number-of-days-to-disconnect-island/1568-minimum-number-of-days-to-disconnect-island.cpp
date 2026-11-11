class Solution {
public:
 void dfs(int row,int col,vector<vector<int>>& grid, vector<vector<int>> &vis){
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr=row+delrow[i];
            int nc=col+delcol[i];

            if(nr>=0&&nr<n&&nc>=0&&nc<m && !vis[nr][nc] && grid[nr][nc]==1){
                dfs(nr,nc,grid,vis);
            }
        }

 }
    int minDays(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
          int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    count++;
                    dfs(i,j,grid,vis);
                }
            }
        }
       if(count != 1)
    return 0;

// Try removing every land cell
for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {

        if(grid[i][j] == 1) {

            grid[i][j] = 0;   // Remove land

            vector<vector<int>> vis(n, vector<int>(m, 0));
            int islands = 0;

            // Count islands again
            for(int r = 0; r < n; r++) {
                for(int c = 0; c < m; c++) {

                    if(grid[r][c] == 1 && !vis[r][c]) {
                        islands++;
                        dfs(r, c, grid, vis);
                    }
                }
            }

            // Restore the land
            grid[i][j] = 1;

            // If disconnected
            if(islands != 1)
                return 1;
        }
    }
}

return 2;
    }
};