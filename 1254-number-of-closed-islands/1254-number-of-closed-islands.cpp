class Solution {
public:
void dfs(int row,int col,vector<vector<int>>& grid, vector<vector<int>>& vis){
    int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr=row+delrow[i];
            int nc=col+delcol[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0 && !vis[nr][nc]){
              dfs(nr,nc,grid,vis);
            }
        }

}
// void dfs2(int row,int col,vector<vector<int>>& grid, vector<vector<int>>& vis){
//      int n=grid.size();
//         int m=grid[0].size();
//         vis[row][col]=1;
//         int delrow[]={-1,0,1,0};
//         int delcol[]={0,1,0,-1};
//         for(int i=0;i<4;i++){
//             int nr=row+delrow[i];
//             int nc=col+delcol[i];

//             if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0 && !vis[nr][nc]){
//               dfs2(nr,nc,grid,vis);
//             }
//         }
// }


    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
  for (int j = 0; j < m; j++) {

    if (grid[0][j] == 0 && !vis[0][j])
        dfs(0, j, grid, vis);

    if (grid[n - 1][j] == 0 && !vis[n - 1][j])
        dfs(n - 1, j, grid, vis);
}

// First and last column
for (int i = 0; i < n; i++) {

    if (grid[i][0] == 0 && !vis[i][0])
        dfs(i, 0, grid, vis);

    if (grid[i][m - 1] == 0 && !vis[i][m - 1])
        dfs(i, m - 1, grid, vis);
}


               int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 && !vis[i][j] ){
                    count++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return count;
    }
};