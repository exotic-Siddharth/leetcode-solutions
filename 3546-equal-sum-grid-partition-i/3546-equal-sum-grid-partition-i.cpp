class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        long long totalSum = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                totalSum += grid[i][j];
            }
        }

        // Horizontal cuts
        long long currSum = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m; j++) {
                currSum += grid[i][j];
            }

            if (currSum == totalSum - currSum)
                return true;
        }

        // Vertical cuts
        currSum = 0;
        for (int j = 0; j < m - 1; j++) {
            for (int i = 0; i < n; i++) {
                currSum += grid[i][j];
            }

            if (currSum == totalSum - currSum)
                return true;
        }

        return false;
    }
};