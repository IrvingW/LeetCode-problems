class Solution {
public:
    bool isPerfectSquare(int num) {
        // 1, 4, 9, 16, 25
        // sub: 1, 3, 5, 7, 9
        int sub = 1;
        while(num > 0){
            num -= sub;
            sub += 2;
        }
        return num == 0;
    }
};
