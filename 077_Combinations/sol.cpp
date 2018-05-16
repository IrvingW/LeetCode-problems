class Solution {
private:
    int len;
public:
    void f(vector<vector<int>> & result, vector<int> prefix, vector<int> nums){
        if(prefix.size() == len){
            result.push_back(prefix);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            prefix.push_back(nums[i]);
            vector<int> remain;
            remain.assign(nums.begin()+i+1, nums.end());
            f(result, prefix, remain);
            prefix.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        len = k;
        for(int i = 1; i <= n; i++){
            nums.push_back(i);    
        }
        vector<vector<int>> result;
        if(k > n)   return result;
        
        vector<int> pre;
        f(result, pre, nums);
        return result;
    }
};
