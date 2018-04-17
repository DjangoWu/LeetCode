class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2)
            return 0;
        int count = 0;
        int * mask = new int[n](); // 直接动态数组初始化
        for(int i = 2; i < n; i++){
            if(mask[i] == 0)
            {
                count++;
                for(int j = 2; i * j < n; j++){
                    mask[i*j] = 1;
                }
            }
        }
        return count;
    }
    
};