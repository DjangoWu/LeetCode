class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return 1;
        
        int count = 1;
        int flag; // positive is 1, negative is -1, equal is 0
        
        if(nums[1] > nums[0]){
            flag = 1;
            count++;
        }else if(nums[1] < nums[0]){
            flag = -1;
            count++;
        }else {
            flag = 0;
        }
        
        for(int i = 2; i < nums.size(); i++){
            int flag_now;
            if(nums[i] > nums[i - 1])
                flag_now = 1;
            else if(nums[i] < nums[i - 1])
                flag_now = -1;
            else flag_now = 0;
            
            if(flag_now == 0)
                continue;
            if(flag == 0 && flag_now != 0){
                flag = flag_now;
                count++;
            }
            
            if(flag != 0 && flag_now != flag){
                flag = flag_now;
                count++;
            }
        }
        return count;
    }
};