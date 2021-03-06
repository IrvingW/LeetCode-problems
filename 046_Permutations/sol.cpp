class Solution {
public:
    void f(vector<vector<int>> &result, vector<int> prefix, vector<int> remain_nums){
        int size = remain_nums.size();
        if(size == 0){
            result.push_back(prefix);
            return;
        }
        for(int i = 0; i < size; i++){
            prefix.push_back(remain_nums[i]);
            vector<int> sub;
            for(int j = 0; j < size; j++){
                if(j == i)  continue;
                sub.push_back(remain_nums[j]);
            }
            f(result, prefix, sub);
            prefix.pop_back();
        }      
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> prefix;
        f(result, prefix, nums);
        return result;
    }
};
