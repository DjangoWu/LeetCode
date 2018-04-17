// compare function 声明比较类
struct {
    bool operator()(string a, string b){
        string c1 = a + b;
        string c2 = b + a;
        return c1 > c2;
    }
} cmp;


class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if(nums.size() == 0)
            return "";
        vector<string> strnums;
        for(int i = 0; i < nums.size(); i++)
            strnums.push_back(to_string(nums[i]));
            
        sort(strnums.begin(), strnums.end(), cmp);

        string res = "";
        for(int i = 0; i < strnums.size(); i++)
            res += strnums[i];
        if(res[0] == '0')
            return "0";
        return res;
            
    }
};