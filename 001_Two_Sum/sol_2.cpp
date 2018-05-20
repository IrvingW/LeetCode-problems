class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++){
            if(m.count(target - nums[i])){
                vector<int> r;
                r.push_back(i);
                r.push_back(m[target - nums[i]]);
                return r;
                
            }else{
                m[nums[i]] = i;
            }
        }
        return {};
    }
};
