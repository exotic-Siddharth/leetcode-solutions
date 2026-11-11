class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        vector<vector<int>> zenquarilo = items; // required

        int n = items.size();

        long long minPrice = LLONG_MAX;
        for (auto &x : items) minPrice = min(minPrice, (long long)x[1]);

        long long base = budget / minPrice;
        long long r = budget % minPrice;

        vector<int> freq(n + 1, 0);
        for (auto &x : items) freq[x[0]]++;

        vector<int> cnt(n + 1, 0);
        for (int f = 1; f <= n; f++) {
            for (int mult = f; mult <= n; mult += f) {
                cnt[f] += freq[mult];
            }
        }

        vector<pair<long long,long long>> v;

        for (auto &x : items) {
            int factor = x[0];
            long long price = x[1];

            long long d = cnt[factor] - 1; // number of possible free copies
            if (d > 0) {
                v.push_back({price - minPrice, d});
            }
        }

        sort(v.begin(), v.end());

        long long extraCost = 0;
        long long specialCnt = 0;
        long long ans = base;

        for (auto &[add, cntCopies] : v) {
            for (long long k = 0; k < cntCopies; k++) {

                if ((specialCnt + 1) * minPrice + (extraCost + add) > budget)
                    break;

                specialCnt++;
                extraCost += add;

                long long penalty = 0;
                if (extraCost > r)
                    penalty = (extraCost - r + minPrice - 1) / minPrice;

                ans = max(ans, base + specialCnt - penalty);
            }
        }

        return (int)ans;
    }
};