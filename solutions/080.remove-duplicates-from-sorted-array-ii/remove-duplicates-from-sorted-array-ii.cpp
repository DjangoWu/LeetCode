class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums.size();
        int j = 0, count = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[j] == nums[i]) {
                count++;
                if (count < 2)
                    nums[++j] = nums[i];
            } else {
                nums[++j] = nums[i];
                count = 0;
            }
        }
        return j+1;
    }
};