class Solution {
private:
    int len;
public:
    void sum(vector<vector<int>> & result, int index, vector<int> & nums, int target, vector<int> prefix){
        if(target == 0 && prefix.size() == len){
            result.push_back(prefix);
            return;
        } 
        if(target < 0)
            return; // failed
        for(int i = index; i < 9; i++){
            prefix.push_back(nums[i]);
            sum(result, i+1, nums, target-nums[i], prefix);
            prefix.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        for(int i = 1; i < 10; i++){
            nums.push_back(i);
        }
        vector<vector<int>> result;
        vector<int> pre;
        if(k > 9)   return result;  // can not reach
        len = k;
        sum(result, 0, nums, n, pre);
        return result;
    }
};
