class Solution {
public:
    vector<vector<int>> ans;

    void combinationSumHelper(int ind, int target, vector<int>& candidates, vector<int>& ds) {
        
        if (ind == candidates.size()) {
            if (target == 0)
                ans.push_back(ds);
            return;
        }

        
        if (candidates[ind] <= target) {
            ds.push_back(candidates[ind]);
            combinationSumHelper(ind, target - candidates[ind], candidates, ds);
            ds.pop_back();
        }

    
        combinationSumHelper(ind + 1, target, candidates, ds);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size(); 
        vector<int> ds;
        combinationSumHelper(0, target, candidates, ds);
        return ans;
    }
};
