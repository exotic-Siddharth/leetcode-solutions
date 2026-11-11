class Solution {
public:
    bool solve(int i, int sum, int target, int k,
               vector<int>& nums, vector<bool>& vis) {

        if (k == 1)
            return true;

        if (sum == target)
            return solve(0, 0, target, k - 1, nums, vis);

        for (int j = i; j < nums.size(); j++) {

            if (vis[j]) continue;

            if (sum + nums[j] > target)   continue;

            vis[j] = true;

            if (solve(j + 1, sum + nums[j], target, k, nums, vis))
                return true;

            vis[j] = false;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {

        int total = 0;
        for (int x : nums)
            total += x;

        if (total % k != 0)
            return false;

        int target = total / k;

        sort(nums.rbegin(), nums.rend());

        vector<bool> vis(nums.size(), false);

        return solve(0, 0, target, k, nums, vis);
    }
};