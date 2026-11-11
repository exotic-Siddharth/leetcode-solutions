class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        long long first = INT_MIN;
        long long second = INT_MIN;
        long long third = INT_MIN;

        long long min1 = INT_MAX;
        long long min2 = INT_MAX;

        for (int num : nums) {

            if (num >= first) {
                third = second;
                second = first;
                first = num;
            }
            else if (num >= second) {
                third = second;
                second = num;
            }
            else if (num > third) {
                third = num;
            }

            if (num <= min1) {
                min2 = min1;
                min1 = num;
            }
            else if (num < min2) {
                min2 = num;
            }
        }

        return max(first * second * third,
                   first * min1 * min2);
    }
};