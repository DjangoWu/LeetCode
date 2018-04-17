class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret(2, -1);
        int size = nums.size();
        if (size == 0)
            return ret;
        
        int left = 0, right = size - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] >= target)
                right = mid - 1;
            else 
                left = mid + 1;
        }
        
        if (left < size && nums[left] == target)
            ret[0] = left;
        else
            return ret;
        
        right = size - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] <= target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        ret[1] = right;
        return ret;
    }
};