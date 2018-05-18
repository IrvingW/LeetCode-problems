class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        vector<map<int, int>> dp (n+1);
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++){
            for(auto & p : dp[i-1]){
                dp[i][p.first + nums[i-1]] += p.second;
                dp[i][p.first - nums[i-1]] += p.second;
            }
        }
        return dp[n][S];
    }
};
