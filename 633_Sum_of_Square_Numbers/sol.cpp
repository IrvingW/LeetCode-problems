class Solution {
public:
    bool judgeSquareSum(int c) {
        int left = 0;
        int right = sqrt(c);
        while(left <= right){
            int powSum = left * left + right * right;
            if(powSum == c)
                return true;
            if(powSum > c)
                right --;
            else
                left ++;
        }
        return false;
    }
};
