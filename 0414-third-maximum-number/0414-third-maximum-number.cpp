class Solution {
public:

    int thirdMax(vector<int>& nums) {

        long long max1 = LLONG_MIN;
        long long max2 = LLONG_MIN;
        long long max3 = LLONG_MIN;

        for(int i = 0; i < nums.size(); i++) {

            int num = nums[i];

            // skip duplicates
            if(num == max1 ||
               num == max2 ||
               num == max3) {

                continue;
            }

            // update max1
            if(num > max1) {

                max3 = max2;
                max2 = max1;
                max1 = num;
            }

            // update max2
            else if(num > max2) {

                max3 = max2;
                max2 = num;
            }

            // update max3
            else if(num > max3) {

                max3 = num;
            }
        }

        // if third maximum doesn't exist
        if(max3 == LLONG_MIN) {
            return max1;
        }

        return max3;
    }
};