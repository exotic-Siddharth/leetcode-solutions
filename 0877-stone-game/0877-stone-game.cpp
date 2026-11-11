class Solution {
public:

    int solve(int i, int j, bool alice, vector<int>& piles,vector<vector<vector<int>>>& dp){

        if(i > j) return 0;

        if(dp[i][j][alice] != -1)
            return dp[i][j][alice];

        if(alice){
             return dp[i][j][alice] = max( piles[i] + solve(i+1,j,false,piles,dp),
                                          piles[j] + solve(i,j-1,false,piles,dp)
            );
        }

        return dp[i][j][alice] = min(
            solve(i+1,j,true,piles,dp),
            solve(i,j-1,true,piles,dp)
        );
    }

    bool stoneGame(vector<int>& piles) {

        int n = piles.size();

        int total = 0;
        for(int x : piles)
            total += x;

        vector<vector<vector<int>>> dp(n,
            vector<vector<int>>(n, vector<int>(2,-1))
        );

        int alice = solve(0,n-1,true,piles,dp);

        int bob = total - alice;

        return alice > bob;
    }
};