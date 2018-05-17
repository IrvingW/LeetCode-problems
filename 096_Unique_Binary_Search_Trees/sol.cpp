class Solution {
public:
    int numTrees(int n) {
        if(n == 0)  return 0;
        else if(n == 1) return 1;
        else if(n == 2) return 2;
        else{
            int result = 0;
            for(int i = 0; i < n; i++){ // left nums
                int left = numTrees(i);
                int right = numTrees(n - i - 1); 
                if(left == 0 || right == 0) result += max(left, right);
                else result += (left * right);
            }
            return result;
        }
    }
};
