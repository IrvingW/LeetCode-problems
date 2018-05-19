class Solution {
public:
    int trailingZeroes(int n) {
        // 0 is caused by 2 x 5
        return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
    }
};
