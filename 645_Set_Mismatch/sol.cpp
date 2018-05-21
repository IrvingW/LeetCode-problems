class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)  return {};
        vector<int> temp(n, 0);
        vector<int> result;
        for(auto num : nums){
            if(temp[num - 1] == 0)
                temp[num - 1] = num;
            else
                result.push_back(num);
        }
        for(int i = 0; i < n; i++){
            if(temp[i] == 0)
                result.push_back(i + 1);
        }
        return result;
    }
};
