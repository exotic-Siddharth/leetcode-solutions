class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = nums[0], mx = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }

        unordered_set<int> st;
        for (int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }

        vector<int> ans;

        for (int x = mn + 1; x < mx; x++) {
            if (st.find(x) == st.end()) {
                ans.push_back(x);
            }
        }

        return ans;
    }
};