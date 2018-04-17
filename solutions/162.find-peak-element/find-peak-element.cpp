class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int front = 0, back = nums.size() - 1;
        int center;
        while(front < back){
            center = (front + back) / 2;
            if(nums[center] < nums[center + 1])
                front = center + 1;
            else 
                back = center;
        }
        return front;
    }
};