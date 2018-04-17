class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        if(n == 0)
            return res;
        int count = 0;
        int value = 1;
        while(count < (n / 2)){
            for(int j = count; j < n - count; j++){
                res[count][j] = value;
                value++;
            }
            for(int i = count+1; i < n - count; i++){
                res[i][n-count-1] = value;
                value++;
            }
            for(int j = n-count-2; j >= count; j--){
                res[n-count-1][j] = value;
                value++;
            }
            for(int i = n-count-2; i > count; i--){
                res[i][count] = value;
                value++;
            }
            count++;
        }
        if(n % 2 == 1)
            res[count][count] = value;
        return res;
    }
};