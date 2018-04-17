class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        int left = 0, right = nums.size() - 1;
        while (left < right - 1) {
            if (nums[left] < nums[right])
                return nums[left];
            
            int mid = (left + right) >> 1;
            
            if (nums[mid] > nums[left]) 
                left = mid;
            else if (nums[mid] < nums[left])
                right = mid;
        }
        return min(nums[right], nums[left]);
    }
};