class Solution {
public:
  void check(int ind,int arr[],int k,int n,vector<int> &ds,vector<vector<int>>& ans){
    if (n== 0 && ds.size()==k) {
            ans.push_back(ds);
            return;
        }
        if(ind==9 || n<0 || ds.size()>k) return;
         // Pick
        ds.push_back(arr[ind]);
        check(ind + 1, arr, k, n - arr[ind], ds, ans);
        ds.pop_back();

        // Not Pick
        check(ind + 1, arr, k, n, ds, ans);
  }
    vector<vector<int>> combinationSum3(int k, int n) {
        int arr[9]={1,2,3,4,5,6,7,8,9};
        vector<int> ds;
        vector<vector<int>> ans;
        check(0,arr,k,n,ds,ans);
        return ans;
    }
};