class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // buy[i]  = max(buy[i-1], rest[i-1] - prices[i])
        // sell[i] = max(sell[i-1], buy[i-1] + prices[i])
        // rest[i] = max(rest[i-1], sell[i-1])
        // and we can be sure that rest[i] = sell[i-1]
        // so
        // buy[i]  = max(buy[i-1], sell[i-2] - prices[i])
        // sell[i] = max(sell[i-1], buy[i-1] + prices[i])
        
        int n = prices.size();
        if(n == 0 || n == 1)   return 0;
        int buy[n], sell[n];
        buy[0] = 0 - prices[0];
        sell[0] = 0;
        buy[1] = max(buy[0], 0 - prices[1]);
        sell[1] = max(prices[1] - prices[0], 0);
        for(int i = 2; i < n; i++){
            buy[i]  = max(buy[i-1], sell[i-2] - prices[i]);
            sell[i] = max(sell[i-1], buy[i-1] + prices[i]);
        }
        return sell[n-1];
        
    }
};
