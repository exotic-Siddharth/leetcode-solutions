class Solution {
public:
    int bfs(int row, int col, vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        q.push({row,col});

        grid[row][col] = 0;   // mark visited

        int area = 1;

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        while(!q.empty()) {

            auto [r,c] = q.front();
            q.pop();

            for(int i=0;i<4;i++) {

                int nr = r + delrow[i];
                int nc = c + delcol[i];

                if(nr>=0 && nr<n &&
                   nc>=0 && nc<m &&
                   grid[nr][nc]==1) {

                    grid[nr][nc] = 0;
                    area++;

                    q.push({nr,nc});
                }
            }
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int mx = 0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {

                if(grid[i][j]==1) {

                    int area = bfs(i,j,grid);
                    mx = max(mx,area);
                }
            }
        }

        return mx;
    }
};