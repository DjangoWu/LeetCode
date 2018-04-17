class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size() < 2) 
            return vector<int>();
        else if(nums.size() == 2)
            return nums;
        int all = 0;
        for(auto num : nums)
            all ^= num;
        
        int flag = 0x01;
        while(true)
        {
            if(flag & all)
                break;
            flag <<= 1;
        }
        
        int res1 = 0, res2 = 0;
        for(auto num : nums)
        {
            if(num & flag)
                res1 ^= num;
            else 
                res2 ^= num;
        }
        
        vector<int> res;
        res.push_back(res1);
        res.push_back(res2);
        return res;
    }
};