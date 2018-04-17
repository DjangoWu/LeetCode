class Solution {
public:
    int calculate(string s) {
        if (s.length() == 0)
            return 0;
        int num = 0, res = 0;
        stack<int> st;
        char op = '+';
        for (int i = 0; i < s.length(); i++){
            char c = s[i];
            if (isdigit(c))
                num = num * 10 + c - '0';
            if (i == s.length() - 1 || (!isdigit(c) && c != ' ')){
                if (op == '+')
                    st.push(num);
                else if (op == '-')
                    st.push(-num);
                else if (op == '*')
                    st.top() *= num;
                else if (op == '/')
                    st.top() /= num;
                num = 0;
                op = c;
            }
        }
        while (!st.empty()){
            res += st.top();
            st.pop();
        }
        return res;
    }
};