class Solution {
public:
    void sum(vector<vector<int>> & result, int target, vector<int> & candidates, vector<int> prefix, int index){
        if(target == 0){
            result.push_back(prefix);
            return;
        }
        if(target < candidates[0])  // can not reach 
            return;
        for(int i = index; i < candidates.size(); i++){
            if(i != 0 && candidates[i] == candidates[i-1])
                continue;
            prefix.push_back(candidates[i]);
            sum(result, target - candidates[i], candidates, prefix, i);
            prefix.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        if(target < candidates[0])  // not possible
            return result;
        vector<int> pre;
        sum(result, target, candidates, pre, 0);
        return result;   
    }
};
