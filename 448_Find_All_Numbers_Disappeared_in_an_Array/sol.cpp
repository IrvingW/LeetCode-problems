class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int max_num = 0;
        int n = nums.size();
        vector<int> result;
        for(auto num : nums){
            max_num = max(num, max_num);  
        } 
        vector<bool> exist(n+1, false);
        for(auto num : nums){
            exist[num] = true;
        }
        for(int i = 1; i < n+1; i++){
            if(!exist[i])
                result.push_back(i);
        }
        return result;
    }
};
