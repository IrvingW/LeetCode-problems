class Solution {
public:
    int numSquares(int n) {
        int dp[n+1];
        dp[0] = 0;
        for(int i = 1; i < n+1; i++){
            dp[i] = INT_MAX;
        }
        for(int i = 1; i*i <= n; i++){
            for(int j = 0; j < n; j++){
                if(j + i*i <= n){
                    dp[i*i + j] = min(dp[i*i+j], dp[j] + 1);
                }
            }
        }
        return dp[n];
    }
};
