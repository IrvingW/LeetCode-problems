class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        int result = 0;
        for(auto num : nums){
            if(!m.count(num)){
                int left = m.count(num - 1) ? m[num - 1] : 0;
                int right = m.count(num + 1) ? m[num + 1]: 0;
                int sum = left + right + 1;
                m[num] = sum;
                result = max(result, sum);
                m[num - left] = sum;
                m[num + right] = sum;
            }
        }
        return result;
    }
};
