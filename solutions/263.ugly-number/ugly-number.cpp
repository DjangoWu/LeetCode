class Solution {
public:
    bool isUgly(int num) {
        while(num != 1){
            int temp = num;
            if(num % 2 == 0)
                num /= 2;
            if(num % 3 == 0)
                num /= 3;
            if(num % 5 == 0)
                num /= 5;
            if(num == temp)
                return false;
        }
        return true;
    }
};