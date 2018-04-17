class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> str1 = vector<int>(255, 0);
        vector<int> str2 = vector<int>(255, 0);
        
        for (int i = 0; i < s.length(); ++i)
        {
            str1[s[i]]++;
        }
        for (int i = 0; i < t.length(); ++i)
        {
            str2[t[i]]++;
        }
        
        for (int i = 0; i < 255; i++)
        {
            if(str1[i] != str2[i])
                return false;
        }
        
        return true;

    }
};