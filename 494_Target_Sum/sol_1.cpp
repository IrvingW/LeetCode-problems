class Solution {
private:
    int target;
    int result;
public:
    void backtracking(vector<int> & nums, int index, int prefix){
        if(index == nums.size()){
            if(prefix == target)
                result++;
            return;
        }
        prefix +=nums[index];
        backtracking(nums, index + 1, prefix);
        prefix -= 2*nums[index];
        backtracking(nums, index + 1, prefix);
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        target = S;
        result = 0;
        backtracking(nums, 0, 0);
        return result;
    }
};
