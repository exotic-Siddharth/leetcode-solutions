class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int sr=source[0]-1;
        int sc=source[1]-1;
        int tr=target[0]-1;
        int tc=target[1]-1;
        vector<vector<int>>vis(8,vector<int>(8,0));
        queue<pair<pair<int,int>,int>>q;
        q.push({{sr,sc},0});
        vis[sr][sc]=1;
        int dr[]={1,1,-1,-1};
        int dc[]={1,-1,1,-1};

        while(!q.empty()){
            auto cur=q.front();
            q.pop();
            int r=cur.first.first;
            int c=cur.first.second;
            int move=cur.second;

            if(r==tr && c==tc) return move;

            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                while(nr>=0 && nr<8 && nc>=0 && nc<8){
                    if(!vis[nr][nc]){
                        vis[nr][nc]=1;
                        q.push({{nr,nc},move+1});
                    }
                    nr+=dr[i];
                    nc+=dc[i];
                }
            }
        }
        return -1;
    }
};