class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() <= 3)
            return res;
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; ++i) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            for (int j = i+1; j < nums.size() - 2; ++j) {
                if (j > i+1 && nums[j] == nums[j-1])
                    continue;
                
                int m = j+1;
                int n = nums.size() - 1;
                while (m < n) {
                    int tmp_val = nums[i] + nums[j] + nums[m] + nums[n];
                    if (tmp_val == target) {
                        res.push_back({nums[i], nums[j], nums[m], nums[n]});
                        ++m;
                        --n;
                        while (m < n && nums[m] == nums[m-1])
                            ++m;
                        while (m < n && nums[n] == nums[n+1])
                            --n;
                    }
                    else if (tmp_val < target)
                        ++m;
                    else 
                        --n;
                }
            }
            
        }
        return res;
    }
};