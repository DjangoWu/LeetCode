class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int size = nums.size();
        if (size == 0)
            return 0;
        int minSize = INT_MAX;
        int sum = 0;
        
        int left = 0; 
        int right = -1;
        while(right < size){
            while(sum < s && right < size)
                sum += nums[++right];
            if (sum >= s){
                minSize = minSize < right-left+1 ? minSize : right-left+1;
                sum -= nums[left++];
            }
        }
        return minSize > size ? 0 : minSize;
    }
};