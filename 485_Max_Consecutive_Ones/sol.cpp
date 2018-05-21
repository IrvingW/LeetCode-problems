class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)  return 0;
        // longest 1 sequence end with nums[i]
        int dp[n];
        dp[0] = nums[0] == 1 ? 1 : 0;
        int result = dp[0];
        for(int i = 1; i < n; i++){
            if(nums[i] == 0)
                dp[i] = 0;
            else{
                dp[i] = dp[i-1] + 1;
                result = max(dp[i], result);
            }
        }
        return result;
    }
};
