class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k >= prices.size()/2){
            // normal
            int result = 0;
            for(int i = 1; i < prices.size(); i++){
                int diff = prices[i] - prices[i-1];
                if(diff > 0)
                    result += diff;
            }
            return result;
        }
        
        // global[i][j] = max(local[i][j], global[i-1][j])
        // local[i][j] = max(local[i-1][j] + diff, global[i-1][j-1]+max(diff, 0))
        vector<int> global(k+1, 0);
        vector<int> local(k+1, 0);
        for(int i = 1; i < prices.size(); i++){
            int diff = prices[i] - prices[i-1];
            for(int j = k; j > 0; j--){
                local[j] = max(local[j] + diff, global[j-1]+max(diff, 0));
                global[j] = max(local[j], global[j]);
            }
        }
        return global[k];
    }
};
