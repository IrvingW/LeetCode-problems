class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        assert(nums.size() >= 2);
        for(int i = 0; i < nums.size() - 1; i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[j] == nums[i])
                    return nums[i];
            }
        }
    }
};
