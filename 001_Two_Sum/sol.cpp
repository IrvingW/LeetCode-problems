class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> result(0);
        for(int i = 0; i < size; i++){
            for(int j = i+1; j < size; j++){
                int sum = nums[i] + nums[j];
                if(sum == target){
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
};
