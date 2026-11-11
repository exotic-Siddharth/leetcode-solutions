class Solution {

     private: 
     bool isSafe(long long row,long long col,vector<string>& board,int n){
        long long duprow=row,dupcol=col;
         //check for upper diagonal
         while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            row--,col--;
         }
        // check for same row
        row=duprow,col=dupcol;
             while(col>=0){
                  if(board[row][col]=='Q') return false;
                  col--;
             }
      //check for lower diagonal
         row=duprow,col=dupcol;
      while(row<n && col>=0){
            if(board[row][col]=='Q') return false;
            row++,col--;
         }

      return true;
     }



    private:  void solve(long long col,vector<string>& board, vector<vector<string>> &ans,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(long long row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,board,ans,n);
                board[row][col]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(long long i=0;i<n;i++) board[i]=s;
        solve(0,board,ans,n); //col,board,ans,n
        return ans;
    }
};