class Solution {
public:
    int integerBreak(int n) {
        // dp[i] = max(dp[j] * (i-j)), 2 <= j < i
        if(n < 2)   return 0;
        vector<int> dp (n+1, 0);
        dp[2] = 1;
        for(int i = 3; i <= n; i++){
            for(int j = 2; j < i; j++){
                dp[i] = max(dp[i], max(dp[j]*(i-j), j*(i-j)));
            }    
        }
        return dp[n];
    }
};
