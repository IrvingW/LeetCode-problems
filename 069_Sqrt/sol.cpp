class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1)  return x;
        int left = 1;
        int right = x;
        while(left <= right){
            int m = (left + right)/2;
            int m2 = x / m;
            if(m2 == m)
                return m;
            if(m2 > m)
                left = m + 1;
            else
                right = m - 1;
        }
        return right;
    }
};
