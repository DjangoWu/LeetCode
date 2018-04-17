class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";
        long num1 = fabs(numerator), num2 = fabs(denominator);
        bool flag = (numerator>0 ^ denominator>0) ? true : false;
        string ans = (flag ? "-" : "") + to_string(num1 / num2);
        if (num1 % num2 == 0)
            return ans;
        num1 = num1 % num2;
        ans += ".";
        unordered_map<int, int> hash;
        while (!hash.count(num1)) {
            hash[num1] = ans.size();
            num1 *= 10;
            ans += to_string(num1 / num2);
            if (num1 % num2 == 0)
                return ans;
            num1 = num1 % num2;
        }
        ans.insert(hash[num1], 1, '(');
        ans += ")";
        return ans;
    }
};