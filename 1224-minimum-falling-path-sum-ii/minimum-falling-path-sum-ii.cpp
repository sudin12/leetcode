class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Create a dp array to store the minimum falling path sum
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Copy the first row from the grid to dp
        for (int i = 0; i < n; ++i) {
            dp[0][i] = grid[0][i];
        }
        
        // Iterate through the grid starting from the second row
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // Initialize the minimum path sum for the current cell to maximum integer value
                int minPathSum = INT_MAX;
                
                // Iterate through the previous row to find the minimum path sum
                for (int k = 0; k < n; ++k) {
                    // Skip the current column
                    if (k == j) continue;
                    
                    // Update the minimum path sum
                    minPathSum = min(minPathSum, dp[i - 1][k]);
                }
                
                // Update the dp array with the minimum path sum plus the value of the current cell
                dp[i][j] = minPathSum + grid[i][j];
            }
        }
        
        // Find the minimum falling path sum in the last row
        int minSum = INT_MAX;
        for (int j = 0; j < n; ++j) {
            minSum = min(minSum, dp[n - 1][j]);
        }
        
        return minSum;
    }
};