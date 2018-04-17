class Solution {
public:
    
    void DFS(string num, long sum, string path, int k, int pre){
        if(k == num.size() && sum == 0)
            return ans.push_back(path);
        for (int i = k, val = 0; i < num.size(); ++i){
            val = val*10 + (num[i]-'0');
            if(val > INT_MAX)
                break;
            if(k == 0)
                DFS(num, sum+val, path+to_string(val), i+1, val);
            else{
                DFS(num, sum+val, path+"+"+to_string(val), i+1, val);
                DFS(num, sum-val, path+"-"+to_string(val), i+1, -val);
                DFS(num, sum-pre+pre*val, path+"*"+to_string(val), i+1, pre*val);
            }
            if(num[k] == '0')
                break;
        }
        
    }

    vector<string> addOperators(string num, int target) {
        if(num.size() == 0)
            return {};
        DFS(num, -target, "", 0, 0);
        return ans;
    }
    
private:
    vector<string> ans;
};