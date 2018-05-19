class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0;
        int result = INT_MIN;
        for(auto num : nums){
            curSum = max(curSum+num, num);
            result = max(result, curSum);
        }
        return result;
    }
    
};
