class Solution {
    bool check(string &s1, string &s2) {
        if (s1.size() != s2.size() + 1)
            return false;

        int i = 0, j = 0;

        while (i < s1.size()) {
            if (j < s2.size() && s1[i] == s2[j]) {
                i++;
                j++;
            }
            else {
                i++;
            }
        }

        return j == s2.size();
    }

    static bool comp(string &s1, string &s2) {
        return s1.size() < s2.size();
    }

public:
    int longestStrChain(vector<string>& words) {

        sort(words.begin(), words.end(), comp);

        int n = words.size();
        vector<int> dp(n, 1);

        int mx = 1;

        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {

                if (check(words[i], words[prev]) &&
                    1 + dp[prev] > dp[i]) {

                    dp[i] = 1 + dp[prev];
                }
            }

            mx = max(mx, dp[i]);
        }

        return mx;
    }
};