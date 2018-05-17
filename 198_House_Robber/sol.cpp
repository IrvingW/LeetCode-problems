class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size == 0)   return 0;
        if(size == 1)   return nums[0];
        if(size == 2)   return max(nums[0], nums[1]);
        int first = nums[0];
        int second = max(nums[0], nums[1]);
        int index = 2;
        while(index < size){
            int next = max(first + nums[index], second);    // steal index or not
            first = second;
            second = next;
            index ++;
        }
        return second;
    }
};
