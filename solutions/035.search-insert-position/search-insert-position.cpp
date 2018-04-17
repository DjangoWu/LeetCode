class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 0)
            return 0;
        
        int left = 0, right = size - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] > target)
                right = mid - 1;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                return mid;
        }
        return left;
    }
};