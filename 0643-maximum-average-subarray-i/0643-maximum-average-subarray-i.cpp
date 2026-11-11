class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int i = 0, j = 0;
        long long sum = 0;
        long long maxSum = LLONG_MIN;

        while (j < nums.size()) {

            
            sum += nums[j];
            if (j - i + 1 == k) {
                maxSum = max(maxSum, sum);

                
                sum -= nums[i];
                i++;
            }

            j++;
        }

        return (double)maxSum / k;
    }
};