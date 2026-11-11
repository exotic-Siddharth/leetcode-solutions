class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        vector<vector<int>> valmorendi = items; // required variable

        const int MAXF = 1500;

        vector<int> freq(MAXF + 1, 0);
        for (auto &it : items) {
            freq[it[0]]++;
        }

        vector<int> multCnt(MAXF + 1, 0);
        for (int f = 1; f <= MAXF; f++) {
            for (int m = f; m <= MAXF; m += f) {
                multCnt[f] += freq[m];
            }
        }

        vector<vector<int>> buckets(1501);

        for (auto &it : items) {
            int factor = it[0];
            int price = it[1];

            int w = multCnt[factor]; // g_i + 1
            if (price <= budget) {
                buckets[price].push_back(w);
            }
        }

        const int NEG = -1e9;

        vector<int> dpGt(budget + 1, NEG);
        dpGt[0] = 0;

        int ans = 0;

        for (int p = 1500; p >= 1; p--) {
            if (!buckets[p].empty()) {
                vector<int> noInc = dpGt;
                vector<int> inc(budget + 1, NEG);

                for (int w : buckets[p]) {
                    vector<int> nextInc = inc;

                    for (int c = 0; c + p <= budget; c++) {
                        if (inc[c] != NEG) {
                            nextInc[c + p] =
                                max(nextInc[c + p], inc[c] + w);
                        }

                        if (noInc[c] != NEG) {
                            nextInc[c + p] =
                                max(nextInc[c + p], noInc[c] + w);
                        }
                    }

                    inc.swap(nextInc);
                }

                for (int cost = 0; cost <= budget; cost++) {
                    if (inc[cost] != NEG) {
                        ans = max(ans,
                                  inc[cost] + (budget - cost) / p);
                    }
                }
            }

            // Build DP for items with price >= p
            for (int w : buckets[p]) {
                for (int c = budget; c >= p; c--) {
                    if (dpGt[c - p] != NEG) {
                        dpGt[c] = max(dpGt[c], dpGt[c - p] + w);
                    }
                }
            }
        }

        return ans;
    }
};