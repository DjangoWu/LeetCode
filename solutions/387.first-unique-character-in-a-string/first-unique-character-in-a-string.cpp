class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> flag(255, 0);
        
        for(int i = 0; i < s.length(); i++)
            flag[s[i]]++;
        
        for(int i = 0; i < s.length(); i++){
            if(flag[s[i]] == 1)
                return i;
        }
        return -1;
    }
};