class Solution {
public:
    vector<vector<int>> ans;

    void permuteHelper(int ind, vector<int>& nums) {
        if (ind == nums.size()) {
            ans.push_back(nums);
            return;
        }
unordered_set<int> ds;
        for (int i = ind; i < nums.size(); i++) {
        if(ds.count(nums[i])) continue;
         ds.insert(nums[i]);
            swap(nums[ind], nums[i]);
            permuteHelper(ind + 1, nums);
            swap(nums[ind], nums[i]);  
        }
    }

     vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        permuteHelper(0, nums);
        return ans;
    }
};

    
    