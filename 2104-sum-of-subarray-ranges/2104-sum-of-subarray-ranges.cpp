class Solution {
public:

    long long subArrayRanges(vector<int>& nums) {

        int n = nums.size();

        long long minSum = 0;
        long long maxSum = 0;

        stack<int> st;

        //  MINIMUM CONTRIBUTION

        vector<int> leftMin(n), rightMin(n);

        // Previous Smaller
        for(int i = 0; i < n; i++) {

            while(!st.empty() &&
                  nums[st.top()] > nums[i]) {

                st.pop();
            }

            leftMin[i] = st.empty() ?
                         i + 1 :
                         i - st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();

        // Next Smaller
        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() &&
                  nums[st.top()] >= nums[i]) {

                st.pop();
            }

            rightMin[i] = st.empty() ?
                          n - i :
                          st.top() - i;

            st.push(i);
        }

        while(!st.empty()) st.pop();

        //  MAXIMUM CONTRIBUTION

        vector<int> leftMax(n), rightMax(n);

        // Previous Greater
        for(int i = 0; i < n; i++) {

            while(!st.empty() &&
                  nums[st.top()] < nums[i]) {

                st.pop();
            }

            leftMax[i] = st.empty() ?
                         i + 1 :
                         i - st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();

        // Next Greater
        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() &&
                  nums[st.top()] <= nums[i]) {

                st.pop();
            }

            rightMax[i] = st.empty() ?
                          n - i :
                          st.top() - i;

            st.push(i);
        }

       

        for(int i = 0; i < n; i++) {

            minSum += 1LL *
                      nums[i] *
                      leftMin[i] *
                      rightMin[i];

            maxSum += 1LL *
                      nums[i] *
                      leftMax[i] *
                      rightMax[i];
        }

        return maxSum - minSum;
    }
};