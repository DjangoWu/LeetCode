class NumArray {
private:
    vector<int> elements;
public:
    NumArray(vector<int> nums) {
        this->elements = nums;
    }
    
    void update(int i, int val) {
        elements[i] = val;
    }
    
    int sumRange(int i, int j) {
        int sum = 0;
        for(int k = i; k <= j; k++){
            sum += elements[k];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */