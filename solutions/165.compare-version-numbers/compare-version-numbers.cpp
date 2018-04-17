class Solution {
public:
    int compareVersion(string version1, string version2) {
        // flag1 代表 version1的.的位置 flag2同
        vector<int> flag1, flag2;
        int i;
        flag1.push_back(-1);
        for(i = 0; i < version1.length(); i++){
            if(version1[i] == '.')
                flag1.push_back(i);
        }
        flag1.push_back(version1.length());
        
        flag2.push_back(-1);
        for(i = 0; i < version2.length(); i++){
            if(version2[i] == '.')
                flag2.push_back(i);
        }
        flag2.push_back(version2.length());
        
        for(i = 0; i < flag1.size() - 1 && i < flag2.size() - 1; i++){
            int ver1 = stoi(string(version1, flag1[i] + 1, flag1[i+1] - flag1[i] - 1));
            int ver2 = stoi(string(version2, flag2[i] + 1, flag2[i+1] - flag2[i] - 1));
            if(ver1 > ver2)
                return 1;
            else if(ver1 < ver2)
                return -1;
        }
        
        if(flag1.size() == flag2.size())
            return 0;
        if(flag1.size() > flag2.size()){
            for(i = flag2.size() - 1; i < flag1.size() - 1; i++){
                if(stoi(string(version1, flag1[i] + 1, flag1[i+1] - flag1[i] - 1)) > 0)
                    return 1;
            }
            return 0;
        } 
        else{
            for(i = flag1.size() - 1; i < flag2.size() - 1; i++){
                if(stoi(string(version2, flag2[i] + 1, flag2[i+1] - flag2[i] - 1)) > 0)
                    return -1;
            }
            return 0;
        }
        
        
    }
};