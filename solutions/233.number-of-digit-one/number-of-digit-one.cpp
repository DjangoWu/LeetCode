class Solution {
public:
    int countDigitOne(int n) {
        int one = 0;
        for(long m = 1; m <= n; m *= 10){
            long a = n / m;
            long b = n % m;
            one += (a + 8) / 10 * m;
            if(a % 10 == 1)
                one += b + 1;
        }
        return one;
        
    }
    
};