class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int div = 1;
        while(x / div >= 10){
            div *= 10;
        }
        while(x != 0){
            int left = x / div;
            int right = x % 10;
            x = (x % div) / 10;
            if(left != right){
                return false;
            }
            div /= 100;
        }
        return true;
    }
};
