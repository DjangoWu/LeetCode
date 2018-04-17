class Solution {
public:
    int lastRemaining(int n) {
        return helper(n, true);
    }
    
    int helper(int n, bool left)
    {
        if (n == 1)
            return 1;
        if(left == true)
            return 2 * helper(n / 2, false);
        else
            return 2 * helper(n / 2, true) - 1 + n % 2;
    }
};