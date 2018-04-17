class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        int maxProfit = 0;
        int minNum = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < minNum)
                minNum = prices[i];
            if (prices[i] - minNum > maxProfit)
                maxProfit = prices[i] - minNum;
        }
        return maxProfit;
    }
};