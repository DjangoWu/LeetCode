class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length() <= 1)
            return true;
        int start = 0, end = s.length() - 1;
        while (!testChar(s[start]))
            start++;
        while (!testChar(s[end]))
            end--;
        while (start <= end) {
            
            if (tolower(s[start]) == tolower(s[end])){
                start++;
                end--;
            }
            else
                return false;
            while (!testChar(s[start]))
                start++;
            while (!testChar(s[end]))
                end--;
        }
        return true;
    }
    
    bool testChar(char tmp) {
        if (tmp >= 'A' && tmp <= 'Z')
            return true;
        else if (tmp >= 'a' && tmp <= 'z')
            return true;
        else if (tmp >= '0' && tmp <= '9')
            return true;
        else 
            return false;
    }
};