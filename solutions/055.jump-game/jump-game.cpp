class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach=0;
        int i=0;
        while(i<nums.size() && i<=reach){
            reach=max(reach,i+nums[i]);
            i++;
        }
        return reach>=nums.size()-1;
    }
};