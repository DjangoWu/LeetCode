class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        else if (x == 0)
            return true;
        
        int tmp = x;
        int y = 0;
        while (x != 0) {
            y = y*10 + x%10;
            x /= 10;
        }
        if (tmp == y)
            return true;
        else 
            return false;
        
        
    }
};