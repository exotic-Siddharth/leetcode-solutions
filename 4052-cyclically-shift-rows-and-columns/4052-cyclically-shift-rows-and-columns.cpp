class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        vector<vector<int>> ans(n,vector<int>(n));
         vector<vector<int>> temp(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int nc=(j-rowShift[i]+n)%n;
                temp[i][nc]=grid[i][j];
            }
        }
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int nr=(i-colShift[j]+n)%n;
                ans[nr][j]=temp[i][j];
            }
        }
        return ans;
    }
};