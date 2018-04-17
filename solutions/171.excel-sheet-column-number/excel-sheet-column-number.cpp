class Solution {
public:
    int titleToNumber(string s) {
        int len = s.length();
        int ans = 0;
        int step = 1;
        for (int i = len - 1; i >= 0; --i){
            int tmp = s[i] - 'A' + 1;
            ans = ans + tmp * step;
            step *= 26;
        }
        return ans;
    }
};