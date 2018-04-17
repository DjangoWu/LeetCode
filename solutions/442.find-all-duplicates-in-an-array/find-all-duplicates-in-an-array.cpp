class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int len = nums.size(), n;
        vector<int> ans;
        for(int i = 0; i < len; ){
            if(nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
            else 
                i++;
        }
        
        for(int i = 0; i < len; i++)
            if(nums[i] != i+1)
                ans.push_back(nums[i]);
        return ans;
    }
};