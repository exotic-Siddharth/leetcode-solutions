class Solution {
public:
    vector<vector<vector<long long>>> dp;

    long long solve(int ind, int state, int k, vector<int>& prices) {

        int n = prices.size();

        if (ind == n) {
            if (state == 0) return 0;
            return -(long long)1e18;
        }

        if (dp[ind][state][k] != -1)
            return dp[ind][state][k];

        long long ans = 0;

        if (state == 0) {

            ans = solve(ind + 1, 0, k, prices);

            if (k > 0) {
                ans = max(ans,
                          -1LL * prices[ind] +
                              solve(ind + 1, 1, k, prices));

                ans = max(ans,
                          1LL * prices[ind] +
                              solve(ind + 1, 2, k, prices));
            }
        }

        else if (state == 1) {

            ans = max(
                solve(ind + 1, 1, k, prices),
                1LL * prices[ind] +
                    solve(ind + 1, 0, k - 1, prices)
            );
        }

        else {

            ans = max(
                solve(ind + 1, 2, k, prices),
                -1LL * prices[ind] +
                    solve(ind + 1, 0, k - 1, prices)
            );
        }

        return dp[ind][state][k] = ans;
    }

    long long maximumProfit(vector<int>& prices, int k) {

        int n = prices.size();

        dp.assign(n,
                  vector<vector<long long>>(3,
                  vector<long long>(k + 1, -1)));

        return solve(0, 0, k, prices);
    }
};