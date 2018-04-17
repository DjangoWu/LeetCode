class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int size = nums.size();
        
        int flag = 0;
        int i = size - 1;
        while(i > 0){
            if(nums[i] > nums[i-1]){
                flag = i-1;
                break;
            }
            i--;
        }
        printf("i = %d, flag = %d\n", i, flag);
        
        if (flag == 0 && i == 0){
            sort(nums.begin(), nums.end());
            return;
        }
        
        int temp = flag + 1;
        for (int j = temp + 1; j < size; j++){
            if (nums[j] > nums[flag] && nums[j] < nums[temp])
                temp = j;
        }
        swap (nums[flag], nums[temp]);
        
        sort(nums.begin()+flag + 1, nums.end());
        
    }
};