class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 边界问题，我们要考虑边界问题的处理
        vector<int> res;
        if (nums.size() <= 1)
            return res;
        // 新建一个map<key, value>模式的来存储nums中的元素和index
        // 这里de unordered_map相当于hash_map
        unordered_map<int, int> myMap;
        for (int i = 0; i < nums.size(); ++i)
            myMap[nums[i]] = i;
        for (int i = 0; i < nums.size(); ++i)
        {
            int rest_val = target - nums[i];
            if (myMap.find(rest_val) != myMap.end())
            {
                int index = myMap[rest_val];
                if (index == i)
                    continue;
                if (index < i)
                {
                    res.push_back(index);
                    res.push_back(i);
                    return res;
                }
                else
                {
                    res.push_back(i);
                    res.push_back(index);
                    return res;
                }
            }
        }
    }
};