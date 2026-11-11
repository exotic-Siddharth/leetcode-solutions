class Solution {
public:
    vector<vector<int>> ans;

    void permuteHelper(int ind, vector<int>& nums) {
        if (ind == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = ind; i < nums.size(); i++) {
            swap(nums[ind], nums[i]);
            permuteHelper(ind + 1, nums);
            swap(nums[ind], nums[i]);  // backtrack
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        permuteHelper(0, nums);
        return ans;
    }
};

    