class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int perm=0;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                int neigh=0;

                for(int k=0;k<4;k++){
                int nr=i+delrow[k];
                int nc=j+delcol[k];

                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                    neigh++;
                }
                }
                perm+=(4-neigh);
            }
         }
         }
         return perm;
    }
};