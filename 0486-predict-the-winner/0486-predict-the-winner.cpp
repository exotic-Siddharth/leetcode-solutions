class Solution {
public:

    int solve(int i, int j, bool player1, vector<int>& nums) {

        if(i > j) return 0;

        if(player1) {
            return max(
                nums[i] + solve(i + 1, j, false, nums),
                nums[j] + solve(i, j - 1, false, nums)
            );
        }
        else {
            // Player 2 tries to minimize Player 1's final score
            return min(
                solve(i + 1, j, true, nums),
                solve(i, j - 1, true, nums)
            );
        }
    }

      bool predictTheWinner(vector<int>& nums)  {

        int total = 0;
        for(int x : nums)
            total += x;

        int p1 = solve(0, nums.size() - 1, true, nums);

        int p2 = total - p1;

        return p1 >= p2;
    }
};