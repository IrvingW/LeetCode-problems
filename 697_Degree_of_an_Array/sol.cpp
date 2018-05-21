class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_map<int, pair<int, int>> pos;
        int degree = 0;
        for(int i = 0; i < nums.size(); i++){
            if(freq.count(nums[i])){
                freq[nums[i]] ++;
                pos[nums[i]].second = i;
            }else{
                freq[nums[i]] = 1;
                pos[nums[i]].first = i;
                pos[nums[i]].second = i;
            }
            degree = max(degree, freq[nums[i]]);
        }
        int result = INT_MAX;
        unordered_map<int, int>::iterator it;
        for(it = freq.begin(); it != freq.end(); it++){
            if(it->second == degree){
                int num = it->first;
                result = min(result, pos[num].second - pos[num].first + 1);
            }
        }
        return result;
    }
};
