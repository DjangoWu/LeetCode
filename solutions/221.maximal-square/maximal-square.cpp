class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0)
            return 0;
        int row = matrix.size();
        int col = matrix[0].size();
        int maxSqu = 0;
        vector<vector<int>> dp(row, vector<int>(col, 0));
        // 第一行赋值
        for (int i = 0; i < col; i++){
            dp[0][i] = matrix[0][i] - '0';
            maxSqu = max(maxSqu, dp[0][i]);
        }
        // 第一列赋值
        for (int i = 0; i < row; i++){
            dp[i][0] = matrix[i][0] - '0';
            maxSqu = max (maxSqu, dp[i][0]);
        }
        // 递推
        for (int i = 1; i < row; i++){
            for (int j = 1; j < col; j++){
                if (matrix[i][j] == '1')
                    dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1])+1;
                else 
                    dp[i][j] = 0;
                maxSqu = max(maxSqu, dp[i][j]);
            }
        }
        
        return maxSqu * maxSqu;
    }
};