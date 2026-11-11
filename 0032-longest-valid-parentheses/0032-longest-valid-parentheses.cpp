class Solution {
public:

    int longestValidParentheses(string s) {

        int left = 0, right = 0, mx = 0;

        //left to right
        for(int i = 0; i < s.length(); i++) {

            if(s[i] == '(')
                left++;
            else
                right++;

            if(left == right)
                mx = max(mx, 2 * right);

            else if(right > left) {
                left = 0;
                right = 0;
            }
        }

        // Reset counters
        left = 0;
        right = 0;

        // Right to Left
        for(int i = s.length() - 1; i >= 0; i--) {

            if(s[i] == '(')
                left++;
            else
                right++;

            if(left == right)
                mx = max(mx, 2 * left);

            else if(left > right) {
                left = 0;
                right = 0;
            }
        }

        return mx;
    }
};