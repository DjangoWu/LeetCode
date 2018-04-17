class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string path;
        helper(n, n, path, res);
        return res;
    }
    
    void helper(int left, int right, string path, vector<string>& result){
        //std::cout << left << " " << right << " " << path << std::endl;
        if(left == 0 && right == 0){
            result.push_back(path);
            return;
        }
        if(left != 0)
            helper(left-1, right, path + '(', result);
        if(right != 0 && right > left)
            helper(left, right-1, path + ')', result);
    }
};