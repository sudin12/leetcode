class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < n; ++j) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }

        for (int j = 1; j < n; ++j) {
            int countOnes = 0;
            for (int i = 0; i < m; ++i) {
                countOnes += grid[i][j];
            }
            if (countOnes * 2 < m) {
                for (int i = 0; i < m; ++i) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }

        int score = 0;
        for (int i = 0; i < m; ++i) {
            int rowScore = 0;
            for (int j = 0; j < n; ++j) {
                rowScore = rowScore * 2 + grid[i][j];
            }
            score += rowScore;
        }

        return score;
    }
};