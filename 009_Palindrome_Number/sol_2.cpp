class Solution {
public:
    bool isPalindrome(int x) {
        if(x == 0)   return true;
        if(x % 10 == 0) return false;
        int right = 0; 
        while(x > right){
            right = right * 10 + x % 10;
            x = x / 10;
        }
        // x <= right
        return (x == right || x == right / 10);
    }
};
