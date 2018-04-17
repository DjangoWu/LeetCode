// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int startNum = 1;
        int endNum = n;
        while(1){
            //int temp = (startNum + endNum) / 2;
            int temp = (endNum - startNum) / 2 + startNum;
            int flag = guess(temp);
            
            if(flag == -1)
                endNum = temp - 1;
            else if(flag == 1)
                startNum = temp + 1;
            else
                return temp;
        }
    }
};