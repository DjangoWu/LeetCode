class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        int left = 0, right = len - 1, ans, pos = len - k;
        while ((ans = partition(nums, left, right)) != pos)
            ans<pos?left = ans + 1: right = ans - 1;
        return nums[len - k];
    }
    
    int partition(vector<int>& nums, int left, int right){
        int val = nums[right];
        for (int i = left; i < right; i++)
            if (nums[i] < val)
                swap(nums[left++], nums[i]);
        swap(nums[right], nums[left]);
        return left;
    }
};