class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        
        int left = 0, right = numbers.size() - 1;
        while(numbers[left] + numbers[right] != target){
            if(numbers[left] + numbers[right] > target)
                --right;
            else
                ++left;
        }
        res.push_back(++left);
        res.push_back(++right);
        return res;
    }
};