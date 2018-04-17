class NumArray {
public:
    NumArray(vector<int> nums) {
        arrs.resize(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); i++)
            arrs[i+1] = arrs[i] + nums[i];
    }
    
    int sumRange(int i, int j) {
        return arrs[j+1] - arrs[i];
    }
    
private:
    vector<int> arrs;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */