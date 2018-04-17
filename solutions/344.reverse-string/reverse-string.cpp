class Solution {
public:
    string reverseString(string s) {
        string s1 = s;
        int len = s.size();
        for(int i = len-1; i >= 0; i--)
            s1[len-1-i] = s[i];
        return s1;
    }
};