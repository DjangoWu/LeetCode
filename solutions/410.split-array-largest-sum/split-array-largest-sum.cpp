class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long high = 0, low = 0;
        for(int num : nums){
            if(num > low) 
                low = num;
            high += num;
        }
        return BinarySearch(nums, m, high, low);;
    }
    
    int BinarySearch(vector<int>& nums, int m, long high, long low){
        long mid = 0;
        while(low < high){
            mid = (high + low) / 2;
            // 验证
            if(valid(nums, m, mid))
                high = mid;
            else
                low = mid + 1;
        }
        return (int)high;
    }
    
    bool valid(vector<int>& nums, int m, int max){
        int cur = 0;
        int count = 1;
        for(int num : nums){
            cur += num;
            if(cur > max){
                cur = num;
                count++;
                if(count > m)
                    return false;
            }
        }
        return true;
    }
};