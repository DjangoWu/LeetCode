class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len <= 1)
            return 0;
        
        vector<int> profits;
        profits.resize(len);
        
        // 首先我们正向遍历得到每天一次交易的最大收益
        // 并保存到profits中
        int minP = prices[0];
        int sum = numeric_limits<int>::min();
        for (int i = 1; i < len; ++i) {
            minP = min(minP, prices[i]);
            profits[i] = max(sum, prices[i] - minP);
            sum = profits[i];
        }
        
        int maxP = prices[len-1];
        int sum2 = numeric_limits<int>::min();
        
        // 逆向遍历
        for (int i = len-2; i >= 0; --i) {
            maxP = max(maxP, prices[i+1]);
            sum2 = max(sum2, maxP - prices[i]);
            if (sum2 > 0) {
                // 直接将其加入到profit中
                profits[i] += sum2;
                sum = max(sum, profits[i]);
            }
        }
        return sum > 0 ? sum : 0;
    }
};