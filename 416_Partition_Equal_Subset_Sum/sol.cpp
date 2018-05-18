class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0)    return false;   // odd
        int target = sum / 2;
        // transfer to 0/1 package problem
        int n = nums.size();
        vector<bool> reach (target + 1, false);
        reach[0] = true;
        for(int i = 0; i < n; i++){
            int num = nums[i];
            for(int j = target; j >= num; j--){
                reach[j] = reach[j] || reach[j - num];
            }
        }
        return reach[target];
    }
};
