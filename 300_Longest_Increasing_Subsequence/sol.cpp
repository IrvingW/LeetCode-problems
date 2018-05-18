class Solution {
public:
    // dp[i] = max{dp[j] + 1, 0 <= j < i}
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if(size == 0)   return 0;
        int dp [size];
        
        dp[0] = 1;
        for(int i = 1; i < size; i++){
            int max = 0;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i] && dp[j] > max){
                    max = dp[j];
                }
            }
            dp[i] = max + 1;
        }
        int result = 0;
        for(int i = 0; i< size; i++){
            result = max(result, dp[i]);
        }
        return result;
    }
};
