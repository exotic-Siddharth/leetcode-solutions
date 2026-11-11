class Solution {
public:

    bool solve(int i,vector<int>& arr, vector<int>& vis){

        int n = arr.size();

        if(i < 0 || i >= n)
            return false;

        if(arr[i] == 0)
            return true;

        if(vis[i])
            return false;

        vis[i] = 1;

        bool right =solve(i + arr[i], arr, vis);

        bool left =solve(i - arr[i], arr, vis);

        return right || left;
    }

    bool canReach(vector<int>& arr,int start) {

        int n = arr.size();

        vector<int> vis(n,0);

        return solve(start, arr, vis);
    }
};