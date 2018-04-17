class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        
        flag.clear();
        rows = matrix.size();
        cols = matrix[0].size();
        for(int i = 0; i < rows; i++)
        {
            vector<int> temp;
            for(int j = 0; j < cols; j++)
                 temp.push_back(0);
            flag.push_back(temp);
        }
            
        
        int ans = 0;
        
        // 遍历
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(flag[i][j] == 0)
                {
                    flag[i][j] == DP(matrix, i, j);
                    if (ans < flag[i][j])
                        ans = flag[i][j];
                }
            }
        }
        
        return ans;
    }
    
    int DP(vector<vector<int>>& matrix, int row, int col)
    {
        if(flag[row][col] != 0)
            return flag[row][col];
        
        int dis = 1;
        
        // left
        if (col - 1 >= 0)
        {
            if (matrix[row][col-1] > matrix[row][col])
            {
                int temp = 1;
                temp += DP(matrix, row, col - 1);
                if (dis < temp)
                    dis = temp;
            }
        }

        // right
        if (col + 1 < cols)
        {
            if (matrix[row][col + 1] > matrix[row][col])
            {
                int temp = 1;
                temp += DP(matrix, row, col + 1);
                if (dis < temp)
                    dis = temp;
            }
        }

        // up
        if (row - 1 >= 0)
        {
            if (matrix[row - 1][col ] > matrix[row][col])
            {
                int temp = 1;
                temp += DP(matrix, row - 1, col);
                if (dis < temp)
                    dis = temp;
            }
        }

        // down
        if (row + 1 < rows)
        {
            if (matrix[row + 1][col] > matrix[row][col])
            {
                int temp = 1;
                temp += DP(matrix, row + 1, col);
                if (dis < temp)
                    dis = temp;
            }
        }

        flag[row][col] = dis;

        return dis;
    }
    
private:
    vector<vector<int>> flag;
    int rows;
    int cols;
};