// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n < 1) return -1;
        int left = 1;
        int right = n;
        while(left < right){
            int m = left + (right - left)/2;
            if(!isBadVersion(m))
                left = m + 1;
            else
                right = m;
        }
        return left;
    }
};
