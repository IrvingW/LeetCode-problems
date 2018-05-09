class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;
        int size = nums.size();
        for(int i = 0; i < size - 1; i ++){
            if(nums[i] <= nums[i+1])
                continue;
            cnt ++;
            if(i > 0 && nums[i - 1] > nums[i + 1])
                nums[i + 1] = nums[i];
            else
                nums[i] = nums[i + 1];
        }
        return cnt <= 1;
    }
};
