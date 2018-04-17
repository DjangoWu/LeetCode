class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int area = 0;
        vector<int> heights(cols+1, 0);
        for (int j = 0; j < cols; ++j)
            if (matrix[0][j] == '1')
                heights[j] = 1;
        int sum = largestRectangleArea(heights);
        for (int i = 1; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }
            sum = max(sum, largestRectangleArea(heights));
        }    
        return sum;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        
        int i = 0, sum = 0;
        while (i < heights.size()) {
            if (st.empty() || heights[i] > heights[st.top()]) {
                st.push(i);
                ++i;
            } else {
                int t = st.top();
                st.pop();
                
                sum = max(sum, heights[t] * (st.empty() ? i : i - st.top() - 1));
            }
        }
        return sum;
    }
};