class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        if(amount == 0) return 0;
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(auto coin : coins){
                if(i - coin >= 0){
                    dp[i] = min(dp[i], dp[i-coin] + 1);
                }
            }
        }
        if(dp[amount] > amount)   return -1;
        else
            return dp[amount];
        
    }
};
