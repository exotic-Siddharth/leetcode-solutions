class Solution {
public:

    int solve(int ind,int k, vector<int>& arr, vector<vector<int>>& dp){

        if(k==0)
            return 0;

        if(ind>=arr.size())
            return -1e9;

        if(dp[ind][k]!=-1)
            return dp[ind][k];

        int pick =arr[ind]  + solve(ind+2,k-1,arr,dp);

        int nonpick =solve(ind+1, k, arr, dp);

        return dp[ind][k]= max(pick, nonpick);
    }

    int helper(vector<int>& arr,int k){

        int m = arr.size();

        vector<vector<int>> dp( m+2, vector<int>(k+1,-1));

        return solve(0,k,arr,dp);
    }

    int maxSizeSlices(vector<int>& slices) {

        int n = slices.size();
        int k = n/3;

        vector<int> temp1;
        vector<int> temp2;

        for(int i=0;i<n-1;i++)
            temp1.push_back(slices[i]);

        for(int i=1;i<n;i++)
            temp2.push_back(slices[i]);

        return max(helper(temp1,k), helper(temp2,k));
    }
};