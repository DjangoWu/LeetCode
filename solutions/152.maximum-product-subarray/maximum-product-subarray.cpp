class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxLocal = nums[0];
        int minLocal = nums[0];
        int global = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int temp = maxLocal;
            maxLocal = max(max(maxLocal*nums[i], nums[i]), minLocal*nums[i]);
            minLocal = min(min(temp*nums[i], nums[i]), minLocal*nums[i]);
            global = max(global, maxLocal);
        }
        return global;
    }
};