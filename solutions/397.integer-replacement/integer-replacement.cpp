class Solution {
public:
    int integerReplacement(int n) {
        return (int)longReplacement(n);
    }
    
    long longReplacement(long n) {
        if (n < 3)
            return n - 1;
        if (n % 2 == 0)
            return longReplacement(n/2) + 1;
        else
            return min(longReplacement((n-1)/2), longReplacement((n+1)/2)) + 2;
    }
};