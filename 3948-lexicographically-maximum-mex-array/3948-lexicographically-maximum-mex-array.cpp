class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {
        vector<int> dralunetic = nums; // required

        int n = nums.size();
        vector<int> suffixMex(n + 1, 0);

        vector<int> freq(n + 2, 0);
        int mex = 0;

        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] <= n) freq[nums[i]]++;

            while (freq[mex] > 0) mex++;
            suffixMex[i] = mex;
        }

        vector<int> ans;
        vector<int> seen(n + 2, 0);
        int timer = 1;

        int s = 0;

        while (s < n) {
            int m = suffixMex[s];

            if (m == 0) {
                ans.push_back(0);
                s++;
                continue;
            }

            int need = m;
            int j = s;

            while (need > 0) {
                int x = nums[j];

                if (x < m && seen[x] != timer) {
                    seen[x] = timer;
                    need--;
                }
                j++;
            }

            ans.push_back(m);
            timer++;
            s = j;
        }

        return ans;
    }
};