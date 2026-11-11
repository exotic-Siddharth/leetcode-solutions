class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0);

        unordered_map<int, vector<int>> mp;

        // Store indices of each value
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        // Process each value separately
        for (auto &it : mp) {
            vector<int> &idx = it.second;
            int m = idx.size();

            // Compute total sum of indices
            long long totalSum = 0;
            for (int i = 0; i < m; i++) {
                totalSum += idx[i];
            }

            long long leftSum = 0;
            long long rightSum = totalSum;

            // Calculate answer for each occurrence
            for (int i = 0; i < m; i++) {

                rightSum -= idx[i];

                long long leftContribution =
                    1LL * idx[i] * i - leftSum;

                long long rightContribution =
                    rightSum - 1LL * (m - i - 1) * idx[i];

                ans[idx[i]] = leftContribution + rightContribution;

                leftSum += idx[i];
            }
        }

        return ans;
    }
};