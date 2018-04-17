class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return divide(nums, 0, nums.size()-1, INT_MIN);
    }
    
    int divide(vector<int>& nums, int left, int right, int tmax) {
        if (left > right)
            return INT_MIN;
        
        int mid = left + (right - left)/2;
        // 得到子区间[left, mid-1]最大值
        int lmax = divide(nums, left, mid-1, tmax);
        // 得到子区间[mid+1, right]最大值
        int rmax = divide(nums, mid+1, right, tmax);
        
        tmax = max(tmax, lmax);
        tmax = max(tmax, rmax);
        
        int sum = 0;
        int mlmax = 0;
        // 得到[left, mid-1]最大值
        for (int i = mid-1; i >= left; --i) {
            sum += nums[i];
            mlmax = max(mlmax, sum);
        }
        
        sum = 0;
        int mrmax = 0;
        // 得到[mid+1, right]最大值
        for (int i = mid+1; i <= right; ++i) {
            sum += nums[i];
            mrmax = max(mrmax, sum);
        }
        
        tmax = max(tmax, nums[mid]+mlmax+mrmax);
        return tmax;
    }
};