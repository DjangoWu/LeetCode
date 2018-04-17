class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0)
            return 0;
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        dp[0][0] = 1 - obstacleGrid[0][0];
        for (int row = 1; row < rows; ++row) {
            if (obstacleGrid[row][0] != 1)
                dp[row][0] = dp[row-1][0];
        }
        for (int col = 1; col < cols; ++col) {
            if (obstacleGrid[0][col] != 1)
                dp[0][col] = dp[0][col-1];
        }
        
        for (int row = 1; row < rows; ++ row) {
            for (int col = 1; col < cols; ++col) {
                if (obstacleGrid[row][col] != 1) 
                    dp[row][col] = dp[row-1][col] + dp[row][col-1];
            }
        }
        return dp[rows-1][cols-1];
    }
};