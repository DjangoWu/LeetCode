class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if(matrix.size() == 0)
            return 0;
        int row = matrix.size();
        int col = matrix[0].size();
        int ans = INT_MIN;
        for(int i = 0; i < col; i++){
            vector<int> sum(row, 0);
            for(int j = i; j < col; j++){
                set<int> st{0};
                int curSum = 0;
                int curMax = INT_MIN;
                for(int x = 0; x < row; x++){
                    sum[x] += matrix[x][j];
                    curSum += sum[x];
                    auto it = st.lower_bound(curSum - k);
                    if(it != st.end())
                        curMax = max(curSum - *it, curMax);
                    st.insert(curSum);
                }
                ans = max(curMax, ans);
            }
        }
        return ans;
    }
};