class Solution {
public:
    int minMoves(vector<int>& nums) {
        // 转换为最大值减一
        // 只需要找到最小值，然后统计需要减的次数
        int min = INT_MAX;
        for(auto num : nums){
            if(num < min)   min = num;
        }
        int result = 0;
        for(auto num : nums){
            result += (num - min);
        }
        return result;
    }
};
