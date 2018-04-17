class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> node;
        if (preorder.length() == 0)
            return true;
        preorder += ',';
        int start = 0, end = 0;
        // spilt string
        for (int i = 0; i < preorder.length(); ++i){
            if (preorder[i] == ','){
                end = i;
                string tmp = string(preorder.begin()+start, preorder.begin()+end);
                node.push_back(tmp);
                start = end + 1;
            }
        }
        
        vector<int> flag(node.size(), 0);
        int nums = 0, sharps = 0;
        
        for (int i = 0; i < node.size(); ++i){
            if(node[i] == "#"){
                flag[i] = 2;
                sharps++;
            }
            else
                nums++;
               
            bool tmpflag = false;
            for (int j = i-1; j >= 0; --j){
                if (flag[j] != 2){
                    flag[j]++;
                    tmpflag = true;
                    break;
                }
            }
            if (!tmpflag && i != 0)
                return false;
        }
        if (nums == 0){
            if (sharps == 1)
                return true;
            else 
                return false;
        }
        else if (sharps / nums > 2)
            return false;
        for (int k = 0; k < node.size(); ++k)
            if (flag[k] != 2)
                return false;
        return true;
    }
};