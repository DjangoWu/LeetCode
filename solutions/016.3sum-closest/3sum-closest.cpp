class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() <= 2)
            return -1;
        
        int res = 0;
        int min_dis = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-2; ++i){
            int j = i + 1;
            int k = nums.size()-1;
            while(j < k){
                int tmp_val = nums[i] + nums[j] + nums[k];
                int tmp_dis;
                if (tmp_val < target){
                    tmp_dis = target - tmp_val;
                    if (tmp_dis < min_dis){
                        min_dis = tmp_dis;
                        res = tmp_val;
                    }
                    ++j;
                }
                else if (tmp_val > target){
                    tmp_dis = tmp_val - target;
                    if (tmp_dis < min_dis){
                        min_dis = tmp_dis;
                        res = tmp_val;
                    }
                    --k;
                }
                else {
                    res = tmp_val;
                    return res;
                }
                
            }
        }
        return res;
    }
};