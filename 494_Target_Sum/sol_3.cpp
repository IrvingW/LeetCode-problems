class Solution {
public:
    // P: the subset that numbers are positive
    // N: the subset that numbers are negative
    // sum(P) + sum(N) = S
    // sum(P) - sum(N) = sum
    // 2*sum(P) = S + sum
    // sum(P) = (S + sum)/2
    int findTargetSumWays(vector<int>& nums, int S) {
        // transfer to subset sum problem
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum < S) return 0;
        int ss = sum + S;
        if(ss % 2 != 0) return 0;
        int target = ss / 2;
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            for(int j = target; j >= 0; j--){
                if(j - nums[i] >= 0){
                    dp[j] = dp[j] + dp[j - nums[i]];
                }
            }
        }
        return dp[target];
    }
};
