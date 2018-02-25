class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int size = nums.size();
        for(int i = 0; i < size-2; i++){
            if(nums[i] > 0) 
                break;
            if(nums[i] == nums[i-1] && i!=0)
                continue;
            int target = 0 - nums[i];
            int j = i + 1;
            int k = size - 1;
            while(j < k){
                int sum = nums[k] + nums[j];
                if(sum == target){
                    result.push_back({nums[i], nums[j], nums[k]});
                    while(j<k && nums[j]==nums[j+1]) j++;
                    while(j<k && nums[k]==nums[k-1]) k--;
                    j++;
                    k--;
                }else{
                    if(sum > target) k--;
                    else j++;
                }
            }
        }
        return result;
    }
};
