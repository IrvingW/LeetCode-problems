class Solution {
public:
    int minSteps(int n) {
        if(n == 1)  return 0;
        int result = n;
        for(int i = n-1; i > 1; i--){
            if(n % i == 0){
                result = min(result, minSteps(n/i) + i);
            }
        }
        return result;
    }
};
