class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();

        unordered_map<int, unordered_set<int>> dp;

    
        for (int s : stones) {
            dp[s] = unordered_set<int>();
        }

        dp[0].insert(1);  
        for (int s : stones) {
            for (int k : dp[s]) {
                int reach = s + k;

                if (reach == stones.back()) return true;

                if (dp.find(reach) != dp.end()) {
                    if (k - 1 > 0) dp[reach].insert(k - 1);
                    dp[reach].insert(k);
                    dp[reach].insert(k + 1);
                }
            }
        }

        return false;
    }
};