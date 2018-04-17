class Solution {
public:
    int mySqrt(int x) {
        double pre = 0;
        double cur = x;
        while(abs(cur - pre) > 0.0000001){
            pre = cur;
            cur = (pre/2 + x/(2*pre));
        }
        
        return int(cur);
    }
};