class Solution {
public:
    string longestPalindrome(string s) {
        // padding string
        string ps = "$#";
        for (char c : s){
            ps += c;
            ps += '#';
        }
        ps += '\0';
        
        vector<int> dp(ps.size());
        int id = 0, mx = 0;
        int start = 0, maxLen = 0;
        
        for (int i = 1; i < ps.size(); i++){
            dp[i] = mx > i ? min(dp[2*id-i], mx-i) : 1;
            while (ps[i+dp[i]] == ps[i-dp[i]])
                dp[i]++;
            if (i + dp[i] > mx) {
                id = i;
                mx = i + dp[i];
            }
            //record the longest Palindromic substring
            if (dp[i] - 1 > maxLen){
                start = (i - dp[i]) / 2;
                maxLen = dp[i] - 1;
            }
        }
        return s.substr(start, maxLen);
    }
};