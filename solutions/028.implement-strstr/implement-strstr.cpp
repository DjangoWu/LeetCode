class Solution {
public:
    int strStr(string haystack, string needle) {
        int flag1 = 0, flag2 = 0;
        int len2 = needle.size();
        
        if(haystack.size() == len2){
            if(haystack == needle)
                return 0;
            else
                return -1;
        }
        
        for(int i = 0; i <= haystack.size(); i++){
            string temp = string(haystack, i, len2);
            if(temp == needle)
                return i;
        }
        return -1;
    }
};