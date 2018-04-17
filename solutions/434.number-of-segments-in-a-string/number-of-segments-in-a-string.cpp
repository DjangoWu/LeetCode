class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        int i = 0;
        bool flag = false;
        for(; i < s.length(); i++){
            if(s[i] != ' ' && flag == false){
                res++;
                flag = true;
            }
            if(s[i] == ' ')
                flag = false;
        }
        
        return res;
    }
};