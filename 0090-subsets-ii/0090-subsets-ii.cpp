class Solution {
public:
    vector<vector<int>> ans;

    void calculateSubset(int ind, vector<int>& nums, vector<int>& ds) {
        ans.push_back(ds);  
        for (int i = ind; i < nums.size(); i++) {
    
            if (i > ind && nums[i] == nums[i - 1])
                continue;

            ds.push_back(nums[i]);
            calculateSubset(i + 1, nums, ds);
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  
        vector<int> ds;
        calculateSubset(0, nums, ds);
        return ans;
    }
};

    