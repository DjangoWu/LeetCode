class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1;
        int j = b.length() - 1;
        int c = 0;
        int index;
        int n1, n2;
        vector<int> result(max(a.length(), b.length()) + 1, '0');
        //int result[] = new int[max(a.length(), b.length()) + 1];
        while(i >= 0 || j >= 0){
            n1 = 0;
            n2 = 0;
            if (i >= 0)
                n1 = a[i] - '0';
            if (j >= 0)
                n2 = b[j] - '0';
            result[max(i, j) + 1] = ((n1 + n2 + c) % 2);
            c = (n1 + n2 + c) / 2;
            i--;
            j--;
        }
        result[0] = c;
        if(c == 0)
            index = 1;
        else
            index = 0;
        string ans;
        for (int k = index; k < result.size(); ++k){
            //std::cout << k << " " << result[k] << std::endl;
            ans += (result[k]+ '0');
        }
        return ans;
        
    }
};