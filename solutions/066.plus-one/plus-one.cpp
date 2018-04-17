class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans(digits.size(), 0);
        if (digits.size() == 0)
            return ans;
        int one = 1, sum = 0;
        for (int i = digits.size() - 1; i >= 0; i--) {
            int sum = digits[i] + one;
            ans[i] = sum % 10;
            one = sum / 10;
        }
        if (one > 0)
            ans.insert(ans.begin(), one);
        return ans;
    }
};