class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
    
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bool ans=true;
                for(int k=0;k<4;k++){
                    int nr=i+delrow[k];
                    int nc=j+delcol[k];

                    if(nr>=0 && nr<n && nc>=0 && nc<m && mat[i][j]<=mat[nr][nc]){
                         ans=false;
                         break;
                    }
                }
                if(ans) return {i,j};
            }
        }
        return {};
    }
};