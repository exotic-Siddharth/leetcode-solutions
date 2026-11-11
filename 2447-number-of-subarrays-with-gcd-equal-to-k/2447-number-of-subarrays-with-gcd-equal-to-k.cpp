class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            int g = 0;

            for (int j = i; j < n; j++) {
                g = gcd(g, nums[j]);

                if (g == k)
                    cnt++;
                else if (g < k)
                    break;
            }
        }

        return cnt;
    }
};