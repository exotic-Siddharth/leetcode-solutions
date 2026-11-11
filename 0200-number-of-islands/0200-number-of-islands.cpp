class Solution {
public:
  void bfs(int row,int col, vector<vector<int>> &vis,vector<vector<char>>& grid){
           vis[row][col]=1;
          queue<pair<int,int>> q;
          q.push({row,col});
          int n=grid.size();
         int m=grid[0].size();

          int rdel[]={-1,0,1,0};
          int cdel[]={0,1,0,-1};

         while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
              q.pop();

              for(int i=0;i<4;i++){
                int nr=row+rdel[i];
                int nc=col+cdel[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]=='1'){
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
              }
           

         }


  }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!vis[row][col] && grid[row][col]=='1'){
                 cnt++;
                 bfs(row,col,vis,grid);
                }
            }
        }
        return cnt;
    }
};